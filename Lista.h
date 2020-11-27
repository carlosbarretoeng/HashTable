#ifndef COMPUTACAO_LISTA_H
#define COMPUTACAO_LISTA_H
#include <iostream>
#include <cstring>

using namespace std;

class ElementoLista {
public:
    int valor;
    ElementoLista *proximo;
};

class Lista {
private:
    ElementoLista *inicio, *fim;

public:
    Lista() {
        this->inicio = nullptr;
        this->fim = nullptr;
    }

    void adicionar(int valor) {
        // se a lista esta vazia e é o primeiro elemento
        if (this->vazia()) {
            auto *temporario = new ElementoLista;
            temporario->valor = valor;
            temporario->proximo = nullptr;
            this->inicio = temporario;
            this->fim = temporario;
            temporario = nullptr;
            cout << "[ALERTA] ADICIONADO " << endl;
            return;
        }
        // se a lista esta preenchida e é o último elemento
        else {
            auto *novoElemento = new ElementoLista;

            novoElemento->valor = valor;
            novoElemento->proximo = nullptr;

            if(this->inicio->valor >= valor){
                novoElemento->proximo = this->inicio;
                this->inicio = novoElemento;
                cout << "[ALERTA] ADICIONADO " << endl;
                return;
            }

            auto *temporario = new ElementoLista;

            temporario = this->inicio;
            while(temporario->proximo != nullptr){
                if(temporario->proximo->valor >= valor){
                    novoElemento->proximo = temporario->proximo;
                    temporario->proximo = novoElemento;
                    cout << "[ALERTA] ADICIONADO " << endl;
                    return;
                }
                temporario = temporario->proximo;
            }

            this->fim->proximo = novoElemento;
            this->fim = novoElemento;
            cout << "[ALERTA] ADICIONADO " << endl;
        }
    }

    void remover(int valor) {
        // Lista vazia
        if(this->vazia()) {
            cout << "[ALERTA] LISTA VAZIA " << endl;
            return;
        }

        // Se é pra remover o primeiro elemento
        if(this->inicio->valor == valor){
            this->inicio = this->inicio->proximo;
            cout << "[ALERTA] REMOVIDO " << endl;
            return;
        }

        auto *atual = new ElementoLista;
        auto *anterior = new ElementoLista;

        // Caminha pela lista
        atual = this->inicio;
        while (atual->proximo != nullptr) {
            // Se é para remover o elemento atual;
            if(atual->valor == valor){
                anterior->proximo = atual->proximo;
                cout << "[ALERTA] REMOVIDO " << endl;
                return;
            }
            anterior = atual;
            atual = atual->proximo;
        }

        // Se é para remover o último elemento
        if(atual->valor == valor){
            this->fim = anterior;
            anterior->proximo = nullptr;
            delete atual;
        }
        cout << "[ALERTA] REMOVIDO " << endl;
    }

    bool vazia() {
        return this->inicio == nullptr;
    }

    void imprimir() {
        auto *temporario = new ElementoLista;
        temporario = this->inicio;
        while (temporario!= nullptr){
            cout << temporario->valor << " ";
            temporario = temporario->proximo;
        }
    }

    bool localizar(int valor) {
        auto *temporario = new ElementoLista;
        temporario = this->inicio;
        while (temporario!= nullptr){
            if(temporario->valor == valor) {
                return true;
            }
            temporario = temporario->proximo;
        }
        return false;
    }
};


#endif //COMPUTACAO_LISTA_H
