#include <iostream>
#include <string>
using namespace std;

struct No
{
    string nomeProduto;
    int quantidade;
    float precoUnitario;
    No* proximo;
};

class ListaEncadeada {
    private: 
        No* cabeca;
    public:
        ListaEncadeada() {
            cabeca = nullptr;
        }
    
        void inserirProduto(string nomeProduto, int quantidade, float precoUnitario){
            No* novoNo = new No();
            novoNo->nomeProduto = nomeProduto;
            novoNo->quantidade = quantidade;
            novoNo->precoUnitario = precoUnitario;
            novoNo->proximo = cabeca;
            cabeca = novoNo;
        }

        void removerProduto(){
            No* atual = cabeca;
            No* aux = atual->proximo;
            delete atual;
            cabeca = aux;
        }

        void buscarProduto(string nomeProduto, int atualizarQuantidade){
            No* atual = cabeca;
            while(atual != nullptr){
                if(atual->nomeProduto == nomeProduto){
                    cout << "Produto encontrado: " << atual->nomeProduto << ", Quantidade: " << atual->quantidade << ", Preco: " << atual->precoUnitario << endl;
                    atual->quantidade = atualizarQuantidade;
                    return;
                }
                atual = atual->proximo;
            }
        }

        void exibirProdutos(){
            No* atual = cabeca;
            while(atual != nullptr){
                cout << "Produto: " << atual->nomeProduto << ", Quantidade: " << atual->quantidade << ", Preco: " << atual->precoUnitario << endl;
                atual = atual->proximo;
            }
        }
};

int main() {
    ListaEncadeada lista;
    lista.inserirProduto("Arroz", 2, 5.50);
    lista.inserirProduto("Feijao", 3, 7.30);
    lista.inserirProduto("Macarrao", 1, 4.20);
    lista.inserirProduto("Soja", 3, 7.30);
    lista.inserirProduto("Carne", 4, 20.00);
    lista.exibirProdutos();

    cout << "------------------------" << endl;
    lista.removerProduto();
    cout << "Depois de remover um produto:" << endl;
    lista.exibirProdutos();

    cout << "------------------------" << endl;
    lista.buscarProduto("Feijao", 10);
    cout << "Depois de atualizar a quantidade do Feijao:" << endl;
    lista.exibirProdutos();


    return 0;
}