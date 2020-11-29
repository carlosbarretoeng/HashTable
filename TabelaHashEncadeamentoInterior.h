#ifndef COMPUTACAO_TABELAHASHENCADEAMENTOINTERIOR_H
#define COMPUTACAO_TABELAHASHENCADEAMENTOINTERIOR_H

#define funcaoDeDispersao(valor, slots) (valor % slots)

#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

class ElementoHashInterno {
public:
    bool emUso;
    int chave;
    int valor;
    ElementoHashInterno *proximo;
};

class TabelaHashEncadeamentoInterior {
private:
    int M, P;
    vector<ElementoHashInterno> tabela;
public:
    TabelaHashEncadeamentoInterior() {
        int m;
        int p;
        do {
            cout << "[   INFO] QUAL O VALOR DE 'M'? (2...100)" << endl;
            cin >> m;

            if (m < 2 || m > 100) {
                cout << "[WARNING] VALOR INVALIDO. POR FAVOR ATENHA-SE AOS LIMITES." << endl;
            }
        } while (m < 2 || m > 100);

        do {
            cout << "[   INFO] QUAL O VALOR DE 'P'? [M = P + S] (1.." << m - 1 << ")" << endl;
            cin >> p;

            if (p < 1 || p > (m - 1)) {
                cout << "[WARNING] VALOR INVALIDO. POR FAVOR ATENHA-SE AOS LIMITES." << endl;
            }
        } while (p < 1 || p > (m - 1));

        this->M = m;
        this->P = p;
        for (int i = 0; i < this->M; i++) {
            tabela.emplace_back();
        }
    }

    TabelaHashEncadeamentoInterior(int m, int p) {
        this->M = m;
        this->P = p;
        for (int i = 0; i < this->M; i++) {
            tabela.emplace_back();
        }
    }


    void adicionar(int valor) {
        int chave = funcaoDeDispersao(valor, this->P);

        // Se a posição da tabela esta vazia
        if(!this->tabela[chave].emUso) {
            this->tabela[chave].emUso = true;
            this->tabela[chave].chave = chave;
            this->tabela[chave].valor = valor;
            this->tabela[chave].proximo = nullptr;
            cout << "[   INFO] ELEMENTO ADICIONADO" << endl;
            return;
        }

        // Localizar posicão livre na tabela
        int posicaoLivre = 0;
        for(int i = this->P; i < this->M; i++){
            if(!this->tabela[i].emUso){
                posicaoLivre = i;
                break;
            }
        }

        if(posicaoLivre == 0){
            cout << "[WARNING] OVERFLOW DE POSICAO." << endl;
            return;
        }

        // Localizar último elemento da lista interna
        auto *ultimoElementoDaFila = new ElementoHashInterno;
        ultimoElementoDaFila = &this->tabela[chave];
        while(ultimoElementoDaFila->proximo != nullptr){
            ultimoElementoDaFila = ultimoElementoDaFila->proximo;
        }

        this->tabela[posicaoLivre].emUso = true;
        this->tabela[posicaoLivre].chave = posicaoLivre;
        this->tabela[posicaoLivre].valor = valor;
        this->tabela[posicaoLivre].proximo = nullptr;
        ultimoElementoDaFila->proximo = &this->tabela[posicaoLivre];

        cout << "[   INFO] ELEMENTO ADICIONADO" << endl;
    }

    void remover(int valor) {
        int chave = funcaoDeDispersao(valor, this->P);

        if(!this->tabela[chave].emUso) {
            cout << "[WARNING] ELEMENTO NÃO ENCONTRADO NA TABELA" << endl;
            return;
        }

        //Se é pra remover o elemento que esta na chave-base
        if(this->tabela[chave].valor == valor) {
            // Se não existe mais de um elemento na lista interna
            if (this->tabela[chave].proximo == nullptr) {
                this->tabela[chave].emUso = false;
                cout << "[   INFO] ELEMENTO REMOVIDO DA TABELA" << endl;
                return;
            }

            this->tabela[chave].proximo->emUso = false;
            this->tabela[chave].valor = this->tabela[chave].proximo->valor;
            this->tabela[chave].proximo = this->tabela[chave].proximo->proximo;

            cout << "[   INFO] ELEMENTO REMOVIDO DA TABELA" << endl;
            return;
        }

        auto *anterior = &this->tabela[chave];

        while(anterior->proximo != nullptr){
            if(anterior->proximo->valor == valor){
                anterior->proximo->emUso = false;
                anterior->proximo = anterior->proximo->proximo;
                cout << "[   INFO] ELEMENTO REMOVIDO DA TABELA" << endl;
                return;
            }
            anterior = anterior ->proximo;
        }

    }

    bool localizar(int valor) {
        int chave = funcaoDeDispersao(valor, this->P);
        if (!this->tabela[chave].emUso) {
            return false;
        }

        auto *elemento = &this->tabela[chave];

        while (elemento != nullptr){
            if(elemento->valor == valor){
                return true;
            }
            elemento = elemento->proximo;
        }

        return false;
    }

    void imprimir() {
        cout << endl;
        cout << "TABELA HASH ENCADEAMENTO INTERIOR ________" << endl;
        cout << "           | INDICE | VALOR | PROXIMO" << endl;
        for (int i = 0; i < this->M; i++) {
            if (this->tabela[i].emUso) {
                cout << setw(10) << &this->tabela[i] << " | " << setw(6) << this->tabela[i].chave << " | " << setw(5)
                     << this->tabela[i].valor << " | " << this->tabela[i].proximo << endl;
            } else {
                cout << "           |        |       |        " << endl;
            }
        }
    }
};


#endif
