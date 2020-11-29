#ifndef COMPUTACAO_TABELAHASH_H
#define COMPUTACAO_TABELAHASH_H

#include <iostream>
#include <cstring>

#include "TabelaHashEncadeamentoExterior.h"
#include "TabelaHashEncadeamentoInterior.h"
#include "TabelaHashDuploHash.h"

using namespace std;

class TabelaHash {
    int tipoDeTabelaHash = 0;
    TabelaHashEncadeamentoInterior *hashInterior = nullptr;
    TabelaHashEncadeamentoExterior *hashExterior = nullptr;
    TabelaHashDuploHash *hashDuploHash = nullptr;

public:
    TabelaHash(){
        int opcoes;
        cout << "------------------------------------------" << endl;
        cout << "[   INFO] QUAL ESTRUTURA DE TABELA HASH QUER USAR?" << endl;
        cout << "[   INFO] 0 - ENCERRAR O PROGRAMA" << endl;
        cout << "[   INFO] 1 - ENCADEAMENTO EXTERNO POR LISTA" << endl;
        cout << "[   INFO] 2 - ENCADEAMENTO INTERNO" << endl;
        cout << "[   INFO] 3 - DUPLO HASH" << endl;
        cin >> opcoes;

        if(opcoes <= 0 || opcoes > 3) {
            exit(0);
        }

        this->tipoDeTabelaHash = opcoes;

        if(this->tipoDeTabelaHash == 1) hashExterior = new TabelaHashEncadeamentoExterior();
        if(this->tipoDeTabelaHash == 2) hashInterior = new TabelaHashEncadeamentoInterior();
        if(this->tipoDeTabelaHash == 3) hashDuploHash = new TabelaHashDuploHash();
    }

    void adicionar(int valor){
        if(this->tipoDeTabelaHash == 1) hashExterior->adicionar(valor);
        if(this->tipoDeTabelaHash == 2) hashInterior->adicionar(valor);
        if(this->tipoDeTabelaHash == 3) hashDuploHash->adicionar(valor);
    }

    void remover(int valor){
        if(this->tipoDeTabelaHash == 1) hashExterior->remover(valor);
        if(this->tipoDeTabelaHash == 2) hashInterior->remover(valor);
        if(this->tipoDeTabelaHash == 3) hashDuploHash->remover(valor);
    }

    void imprimir(){
        if(this->tipoDeTabelaHash == 1) hashExterior->imprimir();
        if(this->tipoDeTabelaHash == 2) hashInterior->imprimir();
        if(this->tipoDeTabelaHash == 3) hashDuploHash->imprimir();
    }

    bool localizar(int valor){
        if(this->tipoDeTabelaHash == 1) return hashExterior->localizar(valor);
        if(this->tipoDeTabelaHash == 2) return hashInterior->localizar(valor);
        if(this->tipoDeTabelaHash == 3) return hashDuploHash->localizar(valor);
        return false;
    }
};


#endif //COMPUTACAO_TABELAHASH_H
