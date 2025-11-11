#include <iostream>
#include <string>
using namespace std;

struct Node {
    int id;
    string nome;
    Node* proximo;
};

class ListaCircular {
private:
    Node* fim;

public:
    ListaCircular() : fim(nullptr) {}

    void inserir(int id, string nome) {
        Node* novo = new Node{id, nome, nullptr};
        if (!fim) {
            fim = novo;
            fim->proximo = fim; // aponta para si mesmo
        } else {
            novo->proximo = fim->proximo;
            fim->proximo = novo;
            fim = novo;
        }
    }

    void removerPrimeiro() {
        if (!fim) {
            cout << "Lista vazia!\n";
            return;
        }

        Node* inicio = fim->proximo;
        if (inicio == fim) {
            delete inicio;
            fim = nullptr;
        } else {
            fim->proximo = inicio->proximo;
            delete inicio;
        }
    }

    void exibir() {
        if (!fim) {
            cout << "Nenhum processo na lista.\n";
            return;
        }

        Node* aux = fim->proximo;
        cout << "=== Processos ===\n";
        do {
            cout << "ID: " << aux->id << " | Nome: " << aux->nome << endl;
            aux = aux->proximo;
        } while (aux != fim->proximo);
    }

    ~ListaCircular() {
        if (!fim) return;
        Node* atual = fim->proximo;
        Node* prox;
        do {
            prox = atual->proximo;
            delete atual;
            atual = prox;
        } while (atual != fim->proximo);
    }
};

int main() {
    ListaCircular processos;
    processos.inserir(1, "Chrome");
    processos.inserir(2, "VSCode");
    processos.inserir(3, "Spotify");
    processos.exibir();
    cout << "\nRemovendo o primeiro processo...\n";
    processos.removerPrimeiro();
    processos.exibir();
    return 0;
}
