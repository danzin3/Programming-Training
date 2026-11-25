#include <iostream>
#include <string>
#include <algorithm> // Necessário para std::reverse

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    string linha;
    getline(cin, linha); // Consome o '\n' deixado no buffer após ler N

    for (int i = 0; i < N; i++) {
        getline(cin, linha);

        // Remove possível '\r' (CRLF do Windows) sem usar trim para não apagar espaços válidos da frase
        if (!linha.empty() && linha.back() == '\r') {
            linha.pop_back();
        }

        int metade = linha.length() / 2;

        // Abordagem 1 (Idiomática C++): Inversão in-place usando iteradores [início, fim)
        // Não aloca memória extra: inverte direto na própria string em O(n)
        reverse(linha.begin(), linha.begin() + metade);
        reverse(linha.begin() + metade, linha.end());
        cout << linha << "\n";

        /* Abordagem 2 (Alternativa manual por índices, espelhando seu Python de 2020):
        string resp = "";
        for (int j = metade - 1; j >= 0; j--) resp += linha[j];
        for (int j = linha.length() - 1; j >= metade; j--) resp += linha[j];
        cout << resp << "\n";
        */
    }

    return 0;
}
