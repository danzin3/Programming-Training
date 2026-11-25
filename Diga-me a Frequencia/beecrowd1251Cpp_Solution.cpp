#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    int freq[128];
    bool firstCase = true;

    while (getline(cin, line)) {
        // Ignora linhas vazias ou apenas '\r'
        if (line.empty() || line == "\r") continue;

        memset(freq, 0, sizeof(freq));
        vector<int> chars;

        for (unsigned char c : line) {
            // Ignora '\r' (13); considera apenas caracteres válidos [32, 127]
            if (c >= 32 && c <= 127) {
                if (freq[c] == 0) {
                    chars.push_back(c);
                }
                freq[c]++;
            }
        }

        if (chars.empty()) continue;

        // Ordenação customizada com Lambda (equivalente ao .sort() do JS):
        // 1º critério: frequência crescente
        // 2º critério (empate): valor ASCII decrescente
        sort(chars.begin(), chars.end(), [&](int a, int b) {
            if (freq[a] != freq[b]) {
                return freq[a] < freq[b];
            }
            return a > b;
        });

        // Garante linha em branco apenas ENTRE casos de teste (sem linha extra no final)
        if (!firstCase) {
            cout << "\n";
        }
        firstCase = false;

        for (int code : chars) {
            cout << code << " " << freq[code] << "\n";
        }
    }

    return 0;
}
