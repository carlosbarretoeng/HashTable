#ifndef COMPUTACAO_TABELAHASHENCADEAMENTOEXTERIOR_H
#define COMPUTACAO_TABELAHASHENCADEAMENTOEXTERIOR_H

#define funcaoDeDispersao(valor, slots) (valor % slots)

#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>

#include "Lista.h"

using namespace std;

class ElementoHashExterno {
public:
    bool emUso;
    int chave;
    Lista *lista;

    ElementoHashExterno(){
        emUso = false;
        chave = 0;
        lista = new Lista();
    }
};

class TabelaHashEncadeamentoExterior {
private:
    int M;
    vector<ElementoHashExterno> tabela;
public:
    TabelaHashEncadeamentoExterior() {
        int m;
        // Obtem o número de m da tabela hash
        do{
            cout << "[   INFO] QUAL O VALOR DE 'M'? (1...100)" << endl;
            cin >> m;

            if (m < 1 || m > 100) {
                cout << "[WARNING] VALOR INVALIDO. POR FAVOR ATENHA-SE AOS LIMITES." << endl;
            }
        } while (m < 1 || m > 100);

        this->M = m;
        for(int i=0; i < this->M; i++){
            tabela.emplace_back();
        }
    }

    void adicionar(int valor) {
        int chave = funcaoDeDispersao(valor, this->M);
        if(this->tabela[chave].emUso){
            cout << "[ALERTA] COLISAO NA CHAVE " << chave << endl;
        }else{
            this->tabela[chave].emUso = true;
            this->tabela[chave].chave = chave;
        }
        this->tabela[chave].lista->adicionar(valor);
    }

    void remover(int valor) {
        int chave = funcaoDeDispersao(valor, this->M);
        if(!this->tabela[chave].emUso){
            return;
        }
        this->tabela[chave].lista->remover(valor);
        if(this->tabela[chave].lista->vazia()){
            this->tabela[chave].emUso = false;
        }
    }

    bool localizar(int valor) {
        int chave = funcaoDeDispersao(valor, this->M);
        if(!this->tabela[chave].emUso){
            return false;
        }
        return this->tabela[chave].lista->localizar(valor);
    }

    float obterFatorDeCarga() {
        int N = 0;
        for(int i=0; i<this->M; i++){
            if (this->tabela[i].emUso){
                N++;
            }
        }
        return ((float) N / (float)this->M);
    }

    void imprimir() {
        cout << endl;
        cout << "TABELA HASH ENCADEAMENTO EXTERNO _________" << endl;
        cout << "INDICE | LISTA" <<endl;
        for(int i=0; i<this->M; i++){
            string chave = "  ";
            if(this->tabela[i].emUso){
                chave = to_string(this->tabela[i].chave);
            }
            cout << setw(6) << chave << " | ";
            this->tabela[i].lista->imprimir();
            cout << endl;
        }
    }
};


#endif
