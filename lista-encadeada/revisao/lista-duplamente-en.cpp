#include <iostream>
#include <string>
using namespace std;

struct Node {
    string url;
    Node* anterior;
    Node* proximo;
};

class Historico {
private:
    Node* atual;

public:
    Historico() : atual(nullptr) {}

    void visitar(string url) {
        Node* novo = new Node{url, atual, nullptr};
        if (atual)
            atual->proximo = novo;
        atual = novo;
        cout << "Visitando: " << url << endl;
    }

    void voltar() {
        if (atual && atual->anterior) {
            atual = atual->anterior;
            cout << "Voltando para: " << atual->url << endl;
        } else {
            cout << "Nao ha pagina anterior.\n";
        }
    }

    void avancar() {
        if (atual && atual->proximo) {
            atual = atual->proximo;
            cout << "Avancando para: " << atual->url << endl;
        } else {
            cout << "Nao ha pagina seguinte.\n";
        }
    }

    void exibir() {
        Node* aux = atual;
        while (aux && aux->anterior)
            aux = aux->anterior;
        cout << "\n=== Historico de Navegacao ===\n";
        while (aux) {
            cout << aux->url;
            if (aux == atual) cout << " <-- (atual)";
            cout << endl;
            aux = aux->proximo;
        }
    }

    ~Historico() {
        Node* aux = atual;
        while (aux && aux->anterior)
            aux = aux->anterior;
        while (aux) {
            Node* prox = aux->proximo;
            delete aux;
            aux = prox;
        }
    }
};

int main() {
    Historico h;
    h.visitar("google.com");
    h.visitar("youtube.com");
    h.visitar("github.com");
    h.voltar();
    h.exibir();
    h.avancar();
    h.exibir();
    return 0;
}
