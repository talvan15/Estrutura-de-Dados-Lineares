#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool verificarBalanceamento(const string& expressao) {
    stack<char> pilha; // Pilha para armazenar os símbolos de abertura

    for (char c : expressao) {
        if (c == '(' || c == '{' || c == '[') {
            pilha.push(c);
        } 
        else if (c == ')' || c == '}' || c == ']') {
            if (pilha.empty()) {
                return false; // Fechamento sem abertura
            }

            char topo = pilha.top();
            pilha.pop();

            // Verifica se o símbolo corresponde ao fechamento correto
            if ((c == ')' && topo != '(') ||
                (c == '}' && topo != '{') ||
                (c == ']' && topo != '[')) {
                return false;
            }
        }
    }

    // Se a pilha estiver vazia, está balanceada
    return pilha.empty();
}

int main() {
    string expressoes[] = {
        "(a + b)",
        "{[a * (b + c)]}",
        "a + {b - [c * d]}",
        "a + (b",
        "{[a * b]",
        "(a + b)}",
        "a + {b - [c * d}"
    };

    for (string exp : expressoes) {
        cout << "Expressão: " << exp << endl;
        if (verificarBalanceamento(exp))
            cout << "Balanceada" << endl;
        else
            cout << "Não Balanceada" << endl;
        cout << string(30, '-') << endl;
    }

    return 0;
}
