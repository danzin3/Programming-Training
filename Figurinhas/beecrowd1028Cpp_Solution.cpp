#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, F1, F2;
    if (!(cin >> N)) return 0;
    for (int i = 0; i < N; i++) {
        cin >> F1 >> F2;
        cout << gcd(F1, F2) << "\n";
    }
    return 0;
}
