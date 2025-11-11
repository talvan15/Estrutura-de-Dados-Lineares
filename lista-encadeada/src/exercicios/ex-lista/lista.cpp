#include <iostream>
#include "no.h"
using namespace std;

class Lista{
    public:
        No* primeiro;
        Lista(){
            primeiro = nullptr;
        }
    

    void inserir(int valor){
        No* novoNo = new No();
        novoNo->valor = valor;
        novoNo->proximo = primeiro;

        primeiro = novoNo;

    }

    void mostrar(){
        No* atual = primeiro;
        while (atual != nullptr)
        {
            cout << atual->valor << " ";
            atual = atual->proximo;
        } 
        cout << endl;
    }

    void inserirMeio(int valor, int posicao){
        
    }

};

int main(){
    Lista l;
    l.inserir(10);
    l.inserir(20);
    l.inserir(30);

    l.mostrar();

    return 0;
}