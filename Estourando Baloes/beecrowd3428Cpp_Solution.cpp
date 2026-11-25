#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Essencial nesse problema: N pode chegar a 500.000, exigindo leitura rápida
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Equivalente ao Int32Array(1000001) zerado do JavaScript
    vector<int> arrows(1000001, 0);
    int total = 0;

    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;

        if (arrows[h] > 0) {
            arrows[h]--; // Aproveita uma flecha que já estava voando nessa altura
        } else {
            total++;     // Dispara uma nova flecha
        }
        arrows[h - 1]++; // A flecha cai 1 unidade após estourar o balão
    }

    cout << total << "\n";

    return 0;
}
