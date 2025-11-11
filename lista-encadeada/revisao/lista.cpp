#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using namespace std;
#include "no.h"

class Lista {
    No* cabeca;

    public:
    Lista(){
        cabeca = nullptr;
    }

    void inserirInicio(int valor){
        No* novoNo = new No();
        novoNo->valor = valor;
        novoNo->proximo = cabeca;
        cabeca = novoNo;
    }

    void inserirFim(int valor){
        No* novoNo = new No();
        novoNo->valor = valor;
        novoNo->proximo = nullptr;

        if(cabeca == nullptr){
            cabeca = novoNo;
        } else{

            No* atual = cabeca;
            while(atual->proximo != nullptr){
                atual = atual->proximo;
            }
            atual->proximo = novoNo;
        }
    }

     void removerElemento(int valor){
        No* atual = cabeca;
        No* anterior = nullptr;
        
        while(atual != nullptr && atual->valor != valor){
            anterior = atual;
            atual = atual->proximo;
        }
        
        //remover do inicio
        
        if(anterior == nullptr){
            cabeca = atual->proximo;
        }
        else{
            anterior->proximo = atual->proximo;
        }
        
        delete atual;
    }

       void removerDuplicados() {
        No* atual = cabeca;

        while (atual != nullptr) {
            No* anterior = atual;
            No* aux = atual->proximo;

            while (aux != nullptr) {
                if (aux->valor == atual->valor) {
                    // Encontrou duplicado: remove o nó
                    anterior->proximo = aux->proximo;
                    delete aux;
                    aux = anterior->proximo;
                } else {
                    anterior = aux;
                    aux = aux->proximo;
                }
            }

            atual = atual->proximo;
        }
    }

    void inserirMeio(int valor, int posicao){
        No* novoNo = new No();
        novoNo->valor = valor;

        if(posicao == 0){
            novoNo->proximo = cabeca;
            cabeca = novoNo;
            return;
        }

        No* atual = cabeca;
        for(int i = 0; i<posicao -1; i++){
            if(atual == nullptr) break;
            atual = atual->proximo;
        }

        novoNo->proximo = atual->proximo;
        atual->proximo = novoNo;
        
    }
    void modificar(No* no, int novoValor){
        if(no != nullptr){
            no->valor = novoValor;
        }
    }

    void mostrar(){
        No* atual = cabeca;
        while (atual != nullptr){
            std::cout << atual->valor << " ";
            atual = atual->proximo;
        }
    }

};

#endif