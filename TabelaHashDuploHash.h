#ifndef COMPUTACAO_TABELAHASHDUPLOHASH_H
#define COMPUTACAO_TABELAHASHDUPLOHASH_H

#define funcaoDeDispersao(valor, slots) (valor % slots)

#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

class ElementoHashDuploHash {
public:
    bool emUso;
    int chave;
    int valor;
    ElementoHashDuploHash *proximo;
};

class TabelaHashDuploHash {
private:
    int M;
    vector<ElementoHashDuploHash> tabela;
public:
    TabelaHashDuploHash() {
        int m;
        do {
            cout << "[   INFO] QUAL O VALOR DE 'M'? (1...100)" << endl;
            cin >> m;

            if (m < 1 || m > 100) {
                cout << "[WARNING] VALOR INVALIDO. POR FAVOR ATENHA-SE AOS LIMITES." << endl;
            }
        } while (m < 1 || m > 100);

        this->M = m;
        for (int i = 0; i < this->M; i++) {
            tabela.emplace_back();
        }
    }

    void adicionar(int valor) {
        bool temLugar = false;
        for(int i = 0; i<this->M;i++){
            if(!this->tabela[i].emUso){
                temLugar = true;
            }
        }
        if(!temLugar){
            cout << "[WARNING] NÃO EXISTE ESPAÇO LIVRE NA TABELA" << endl;
            return;
        }

        int h1 = funcaoDeDispersao(valor, this->M);
        int h2 = funcaoDeDispersao(valor, (int)this->M / 2) + 1;
        for(int tentativas = 0; tentativas < this->M; tentativas++){
            int chave = (h1 + tentativas * h2) % this->M;
            if(!this->tabela[chave].emUso){
                this->tabela[chave].chave = chave;
                this->tabela[chave].valor = valor;
                this->tabela[chave].emUso = true;
                cout << "[   INFO] ELEMENTO ADICIONADO" << endl;
                return;
            }
            cout << "[   INFO] COLISÃO EM " << chave << endl;
        }
        cout << "[WARNING] NÃO FOI POSSÍVEL A INSERSÃO NA TABELA. EXCESSO DE TENTATIVAS." << endl;
    }

    void remover(int valor) {
        int h1 = funcaoDeDispersao(valor, this->M);
        int h2 = funcaoDeDispersao(valor, (int)this->M / 2) + 1;
        for(int tentativas = 0; tentativas < this->M; tentativas++){
            int chave = (h1 + tentativas * h2) % this->M;
            if(this->tabela[chave].emUso){
                if(this->tabela[chave].valor == valor){
                    this->tabela[chave].emUso = false;
                    cout << "[   INFO] ELEMENTO REMOVIDO" << endl;
                    return;
                }
            }
        }
        cout << "[WARNING] NÃO FOI POSSÍVEL A REMOÇÃO NA TABELA. EXCESSO DE TENTATIVAS." << endl;
    }

    bool localizar(int valor) {
        int h1 = funcaoDeDispersao(valor, this->M);
        int h2 = funcaoDeDispersao(valor, (int)this->M / 2) + 1;
        for(int tentativas = 0; tentativas < this->M; tentativas++){
            int chave = (h1 + tentativas * h2) % this->M;
            if(this->tabela[chave].emUso && this->tabela[chave].valor == valor){
                return true;
            }
        }
        return false;
    }

    void imprimir() {
        cout << endl;
        cout << "TABELA HASH DUPLO HASH ___________________" << endl;
        cout << "INDICE | VALOR" <<endl;
        for(int i=0; i<this->M; i++){
            if(this->tabela[i].emUso){
                cout << setw(6) << this->tabela[i].chave << " | " << this->tabela[i].valor << endl;
            }else{
                cout << "       | " << endl;
            }
        }
    }
};


#endif
