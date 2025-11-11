#include <iostream>
#include <string>
using namespace std;

    struct Node {
        int numeroProntuario;
        string nomePaciente;
        string gravidade;
        Node* proximo;
    };

class FilaHospital {
private:

    Node* fim; 
    Node* atual;

public:
    FilaHospital() : fim(nullptr), atual(nullptr) {}

    void adicionarPaciente(int id, string nome, string grav) {
        Node* novo = new Node{id, nome, grav, nullptr};
        if (!fim) {
            fim = novo;
            fim->proximo = fim;
        } else {
            novo->proximo = fim->proximo;
            fim->proximo = novo;
            fim = novo;
        }
        cout << "Paciente '" << nome << "' adicionado à fila.\n";
        if (!atual) atual = fim->proximo;
    }

    void atenderPaciente() {
        if (!fim) {
            cout << "Fila vazia.\n";
            return;
        }
        Node* primeiro = fim->proximo;
        cout << "Atendendo paciente: " << primeiro->nomePaciente << endl;

        if (primeiro == fim) {
            fim = nullptr;
            atual = nullptr;
        } else {
            fim->proximo = primeiro->proximo;
            if (atual == primeiro)
                atual = primeiro->proximo;
        }
        delete primeiro;
    }

    string avancarPaciente() {
        if (!atual) return "Fila vazia.";
        atual = atual->proximo;
        return atual->nomePaciente;
    }

    void exibirFila() {
        if (!fim) {
            cout << "Fila vazia.\n";
            return;
        }
        Node* temp = fim->proximo;
        cout << "\n--- Fila de Pacientes ---\n";
        do {
            cout << "Prontuário: " << temp->numeroProntuario << "Nome: " << temp->nomePaciente << "Gravidade: " << temp->gravidade << "\n";
            temp = temp->proximo;
        } while (temp != fim->proximo);
        cout << "--------------------------\n";
    }
};

int main() {
    FilaHospital fila;

    fila.adicionarPaciente(101, "jose", "Alta");
    fila.adicionarPaciente(102, "aluisio", "Media");
    fila.adicionarPaciente(103, "Carlos", "Media");

    fila.exibirFila();

    fila.atenderPaciente();
    cout << "Proximo paciente: " << fila.avancarPaciente() << endl;

    fila.exibirFila();

    return 0;
}


