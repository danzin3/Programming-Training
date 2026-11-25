#include <iostream>

using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long hashmat, oponente;
    
    while(cin >> hashmat >> oponente) {
        cout << abs(hashmat - oponente) << "\n";
    }
    
    return 0;
}
