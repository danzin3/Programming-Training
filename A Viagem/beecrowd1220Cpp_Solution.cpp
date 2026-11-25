#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Lê a quantidade de estudantes até encontrar n == 0 ou EOF
    while (cin >> n && n != 0) {
        vector<int> costs(n);
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            string raw;
            cin >> raw;

            // Parsing inteiro direto pela posição do ponto (evita imprecisão IEEE 754)
            size_t dot = raw.find('.');
            int dollars = stoi(raw.substr(0, dot));
            int cents = stoi(raw.substr(dot + 1));

            int val = dollars * 100 + cents;
            costs[i] = val;
            sum += val;
        }

        int low = sum / n;
        int high = (sum % n == 0) ? low : low + 1;

        long long posDiff = 0;
        long long negDiff = 0;

        for (int i = 0; i < n; i++) {
            if (costs[i] > high) {
                posDiff += costs[i] - high;
            } else if (costs[i] < low) {
                negDiff += low - costs[i];
            }
        }

        long long ans = max(posDiff, negDiff);

        // Formata a saída com '$' e garante 2 dígitos nos centavos (ex: $10.05)
        cout << "$" << (ans / 100) << "." << setw(2) << setfill('0') << (ans % 100) << "\n";
    }

    return 0;
}
