#include <iostream>
using namespace std;

struct No {
        int numeroSlide;
        string conteudo;
        No* anterior;
        No* proximo;
    };

class ListaSlides {
    private:
        No* atual;

    public:
        ListaSlides() : atual(nullptr) {}

        void inserirAposAtual(int numero, string conteudo) {
            No* novo = new No{numero, conteudo, nullptr, nullptr};

            if (!atual) {
                atual = novo;
            } else {
                novo->anterior = atual;
                novo->proximo = atual->proximo;
                if (atual->proximo)
                    atual->proximo->anterior = novo;
                atual->proximo = novo;
                atual = novo;
            }
            cout << "Slide " << numero << " adicionado: " << conteudo << "\n";
        }

        void removerSlideAtual() {
            if (!atual) {
                cout << "Nenhum slide para remover.\n";
                return;
            }

            No* temp = atual;

            if (atual->anterior)
                atual->anterior->proximo = atual->proximo;
            if (atual->proximo)
                atual->proximo->anterior = atual->anterior;

            if (atual->proximo)
                atual = atual->proximo;
            else if (atual->anterior)
                atual = atual->anterior;
            else
                atual = nullptr;

            delete temp;
        }

        void voltarSlide() {
            if (atual && atual->anterior) {
                atual = atual->anterior;
                cout << "slide: " << atual->numeroSlide << " - " << atual->conteudo << "\n";
            } else {
                cout << "Não há slide anterior.\n";
            }
        }

        void avancarSlide() {
            if (atual && atual->proximo) {
                atual = atual->proximo;
                cout << "Avançando para o slide: " << atual->numeroSlide << " - " << atual->conteudo << "\n";
            } else {
                cout << "Não há próximo slide.\n";
            }
        }
    };

    int main() {
        ListaSlides apresentacao;

        apresentacao.inserirAposAtual(1, "EDL");
        apresentacao.inserirAposAtual(2, "DB");
        apresentacao.inserirAposAtual(3, "DSW");
        apresentacao.inserirAposAtual(4, "APOO");

        apresentacao.voltarSlide();
        apresentacao.voltarSlide();
        apresentacao.avancarSlide();
        apresentacao.removerSlideAtual();
        apresentacao.avancarSlide();

        return 0;
    }
