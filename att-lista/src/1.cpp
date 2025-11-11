#include <iostream>
using namespace std;

class No {
    public:
        int valor;
        int valor2;
        No* prox;

    No(int valor){
        valor = valor;
        prox = NULL;
    }

};

class Lista{
    private: 
    No* cabeca;


    public: 
    Lista(){
        cabeca = NULL;
    } 

    void inserirOrdenado(int valor)
        No* novo = new No(valor);
        

        No* getCabeca(){
            return cabeca;
        }

        void exibir(){
            No* atual = cabeca;
            while(atual != NULL){
                cout << atual->valor << " " << atual->valor2 << " ";
                atual = atual->prox;
            }
            cout << endl;
        }
};


int main() {

    Lista lista;

    lista.inserirOrdenado(5);
    lista.inserirOrdenado(3);

    lista.getCabeca();
    lista.exibir();
    return 0;

}