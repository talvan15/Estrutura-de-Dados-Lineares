#include <iostream>
#include "no.h"
using namespace std;

class Pilha{
    private:
        No* topo;
    
    public:
        Pilha(){
            topo = nullptr;
        }
   
    bool isEmpty(){
        return topo == nullptr;
    }

    void push(int valor){
        No* novoNo = new No();
        novoNo->valor = valor;
        novoNo->proximo = topo;
        topo = novoNo;
    }
        // 1 2 3 4 5
    void pop(){
        if (isEmpty()){
            cout << "Pilha vazia!" << endl;
            return;
        }
        No* temp = topo;
        topo = topo->proximo;
        delete temp;
    }

    void mostrar(){
        if(isEmpty()){
            cout << "Pilha vazia!" << endl;
            return;
        }
        No* atual = topo;
        while(atual != nullptr){
            cout << atual->valor << " ";
            atual = atual->proximo;
        }

        cout << endl;
    }

};

int main(){
    Pilha pilha;

    pilha.push(10);
    pilha.push(20);
    pilha.push(30);

    pilha.mostrar(); // Output: 30 20 10

    pilha.pop();
    pilha.mostrar(); 


    return 0;
}