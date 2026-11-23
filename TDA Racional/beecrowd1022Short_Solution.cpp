#include <iostream>
#include <cstdlib> // std::abs

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;

    int a, b, c, d;
    char s1, op, s2;

    while (n--)
    {
        cin >> a >> s1 >> b >> op >> c >> s2 >> d;

        int num, den;
        switch (op)
        {
        case '+':
            num = a * d + c * b;
            den = b * d;
            break;
        case '-':
            num = a * d - c * b;
            den = b * d;
            break;
        case '*':
            num = a * c;
            den = b * d;
            break;
        default:
            num = a * d;
            den = c * b;
            break;
        }

        int g = gcd(std::abs(num), std::abs(den));
        cout << num << '/' << den << " = " << (num / g) << '/' << (den / g) << '\n';
    }

    return 0;
}
