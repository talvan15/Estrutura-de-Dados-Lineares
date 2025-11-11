
#include <iostream>
#include "no.h"
using namespace std;
class Fila {
private:
    No* inicio;
    No* fim;

public:
    Fila() {
        inicio = nullptr;
        fim = nullptr;
    }

    void enqueue(int valor) {
    No* novo = new No();
    novo->valor = valor;
    novo->proximo = nullptr;

    if (fim == nullptr) {        // fila vazia
        inicio = fim = novo;
    } else {
        fim->proximo = novo;     // último nó aponta pro novo
        fim = novo;              // atualiza o fim
    }
}

    void dequeue() {
        if (inicio == nullptr) {
            cout << "Fila vazia!" << endl;
            return;
        }
        No* temp = inicio;
        inicio = inicio->proximo;

        if (inicio == nullptr) fim = nullptr; // se esvaziou
        delete temp;
    }

    void mostrar() {
    No* atual = inicio;
    cout << "Fila: ";
    while (atual != nullptr) {
        cout << atual->valor << " ";
        atual = atual->proximo;
    }
    cout << endl;
}


};