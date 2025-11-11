#include <iostream>
#include <string>
using namespace std;

    struct Node {
        string nomeTag;
        Node* proximo;
    };

class PilhaHTML {
    private:
        Node* topo;

    public:
        PilhaHTML() : topo(nullptr) {}

        void push(const string& tag) {
            Node* novo = new Node{tag, topo};
            topo = novo;
            cout << "Tag <" << tag << "> empilhada.\n";
        }

        void pop(const string& tagFechamento) {
            if (isEmpty()) {
                cout << "Erro: tentativa de fechar </" << tagFechamento << "> sem tag aberta correspondente.\n";
                return;
            }

            string tagTopo = topo->nomeTag;
            if (tagTopo == tagFechamento) {
                Node* temp = topo;
                topo = topo->proximo;
                cout << "Tag </" << tagFechamento << "> corresponde a <" << tagTopo << "> — OK.\n";
                delete temp;
            } else {
                cout << "Erro: tag </" << tagFechamento << "> não corresponde a <" << tagTopo << ">.\n";
            }
        }

        string peek() const {
            if (isEmpty()) return "(pilha vazia)";
            return topo->nomeTag;
        }

        bool isEmpty() const {
            return topo == nullptr;
        }

        void exibirPilha() const {
            cout << "\n--- Pilha Atual ---\n";
            Node* atual = topo;
            while (atual) {
                cout << "<" << atual->nomeTag << ">\n";
                atual = atual->proximo;
            }
            cout << "-------------------\n";
        }

        void verificarBalanceamentoFinal() const {
            if (isEmpty())
                cout << "\n Todas as tags foram fechadas corretamente.\n";
            else
                cout << "\n Existem tags não fechadas. Topo atual: <" << topo->nomeTag << ">\n";
        }
    };