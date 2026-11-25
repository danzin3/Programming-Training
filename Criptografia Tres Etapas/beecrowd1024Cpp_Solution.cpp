#include <iostream>
#include <string>

using namespace std;

int main() {
    // Otimiza a velocidade de leitura e escrita (cin/cout) no beecrowd
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    if (!(cin >> N)) return 0;

    // Consome a quebra de linha (\n) que sobrou no buffer após ler o inteiro N
    string linha;
    getline(cin, linha);

    for (int i = 0; i < N; i++) {
        getline(cin, linha);

        // Remove possível '\r' (quebra de linha do Windows) no final da string
        if (!linha.empty() && linha.back() == '\r') {
            linha.pop_back();
        }
        int len = linha.length();
        int metade = len / 2; // Divisão de inteiros em C++ já trunca automaticamente
        string saida(len, ' ');

        for (int j = 0; j < len; j++) {
            char c = linha[j];
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                c += 3;
            }
            int posInvertida = len - 1 - j;
            if (posInvertida >= metade) {
                c -= 1;
            }

            saida[posInvertida] = c;
        }

        cout << saida << "\n";
    }
    return 0;
}
