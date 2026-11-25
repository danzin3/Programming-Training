#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    string mina;
    getline(cin, mina); // Consome o '\n' deixado após ler o inteiro n

    for (int i = 0; i < n; i++) {
        getline(cin, mina);

        stack<char> pilha;
        int diamantes = 0;

        for (char caractere : mina) {
            if (caractere == '<') {
                pilha.push('<'); // Empilha a abertura do diamante
            } else if (caractere == '>' && !pilha.empty()) {
                pilha.pop();     // Desempilha ao fechar um par válido
                diamantes++;
            }
            // Caracteres '.' (areia) e '>' sem par são naturalmente ignorados
        }

        cout << diamantes << "\n";
    }

    return 0;
}
