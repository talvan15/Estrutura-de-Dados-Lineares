#include <iostream>
#include <string>
using namespace std;

struct Node {
    string acao;
    Node* proximo;
};

class Pilha {
private:
    Node* topo;

public:
    Pilha() : topo(nullptr) {}

    void push(string acao) {
        Node* novo = new Node{acao, topo};
        topo = novo;
        cout << "Ação empilhada: " << acao << endl;
    }

    void pop() {
        if (!topo) {
            cout << "Pilha vazia!\n";
            return;
        }
        Node* aux = topo;
        topo = topo->proximo;
        cout << "Desfazendo ação: " << aux->acao << endl;
        delete aux;
    }

    bool estaVazia() {
        return topo == nullptr;
    }

    void exibir() {
        Node* aux = topo;
        cout << "\n=== Pilha de ações ===\n";
        while (aux) {
            cout << aux->acao << endl;
            aux = aux->proximo;
        }
    }

    ~Pilha() {
        while (!estaVazia())
            pop();
    }
};

int main() {
    Pilha pilha;
    pilha.push("Digitar texto");
    pilha.push("Apagar palavra");
    pilha.push("Salvar arquivo");
    pilha.exibir();

    cout << "\nDesfazendo duas ações:\n";
    pilha.pop();
    pilha.pop();
    pilha.exibir();

    return 0;
}
