#ifndef COMPUTACAO_TABELAHASH_H
#define COMPUTACAO_TABELAHASH_H

#define funcaoDeDispersao(valor, slots) (valor % slots)

#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>

#include "Lista.h"

using namespace std;

class ElementoHash {
public:
    bool emUso;
    int chave;
    Lista *lista;

    ElementoHash(){
        emUso = false;
        chave = 0;
        lista = new Lista();
    }
};

class TabelaHash {
private:
    int M;
    vector<ElementoHash> tabela;
public:
    TabelaHash(int slots) {
        this->M = slots;
        for(int i=0; i<slots; i++){
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
        for(int i=0; i<this->M; i++){
            string chave = "  ";
            if(this->tabela[i].emUso){
                chave = to_string(this->tabela[i].chave);
            }
            cout << setw(2) << chave << " ~> ";
            this->tabela[i].lista->imprimir();
            cout << endl;
        }
    }
};


#endif
