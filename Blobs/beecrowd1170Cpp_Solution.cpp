#include <iostream>
// #include <cmath> // Necessário apenas se usar a solução O(1) com log2

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    for (int i = 0; i < N; i++) {
        double comida;
        cin >> comida;

        // Abordagem 1: Simulação Iterativa - Complexidade O(log2 C)
        int dias = 0;
        while (comida > 1.0) {
            comida /= 2.0;
            dias++;
        }

        // Abordagem 2: Matemática pura com Logaritmo - Complexidade O(1)
        // Se C > 1, o número de divisões por 2 até chegar em <= 1 é ceil(log2(C))
        // int dias = (comida > 1.0) ? static_cast<int>(ceil(log2(comida))) : 0;

        cout << dias << " dias\n";
    }

    return 0;
}
