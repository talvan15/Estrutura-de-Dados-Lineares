#include <iostream>
#include <string>
using namespace std;

struct Node {
    string descricao;
    int prioridade;
    Node* proximo;
};

class ListaTarefas {
private:
    Node* inicio;

public:
    ListaTarefas() : inicio(nullptr) {}

    void inserir(string desc, int prio) {
        Node* novo = new Node{desc, prio, nullptr};
        if (!inicio)
            inicio = novo;
        else {
            Node* aux = inicio;
            while (aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    }

    void exibir() {
        if (!inicio) {
            cout << "Nenhuma tarefa cadastrada.\n";
            return;
        }
        Node* aux = inicio;
        cout << "=== Lista de Tarefas ===\n";
        while (aux) {
            cout << "Descricao: " << aux->descricao
                 << " | Prioridade: " << aux->prioridade << endl;
            aux = aux->proximo;
        }
    }

    ~ListaTarefas() {
        Node* aux;
        while (inicio) {
            aux = inicio;
            inicio = inicio->proximo;
            delete aux;
        }
    }
};

int main() {
    ListaTarefas tarefas;
    tarefas.inserir("Estudar C++", 1);
    tarefas.inserir("Lavar louça", 3);
    tarefas.inserir("Fazer relatório", 2);
    tarefas.exibir();
    return 0;
}
