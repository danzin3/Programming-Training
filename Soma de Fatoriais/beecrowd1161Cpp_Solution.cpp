#include <iostream>
//#include <vector>

using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //Array dinâmico. Aloca os dados da Heap (memória dinâmica)
    //vector<unsigned long long> fat(21, 1);

    //Array estático. Fica aloacado na Stack (pilha de execução)
    unsigned long long fat[21];
    fat[0] = 1;
    for (int i = 1; i <= 20; i++) {
        fat[i] = fat[i - 1] * i;
    }
    int m, n;

    // Em C++, "while (cin >> m >> n)" lê até encontrar o EOF automaticamente
    while (cin >> m >> n) {
        cout << (fat[m] + fat[n]) << "\n";
    }
    return 0;
}
