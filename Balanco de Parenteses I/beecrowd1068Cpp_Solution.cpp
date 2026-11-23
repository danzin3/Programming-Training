#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    stack<int> pilha;
    string linha;

    while (getline(cin, linha))
    {
        for (char ch : linha)
        {
            if (ch == '(')
            {
                pilha.push(1);
            }
            else if (ch == ')')
            {
                if (!pilha.empty())
                {
                    pilha.pop();
                }
                else
                {
                    pilha.push(1);
                }
            }
        }
        if (pilha.empty())
        {
            cout << "correct\n";
        }
        else
        {
            cout << "incorrect\n";
        }
        while (!pilha.empty())
        {
            pilha.pop();
        }
    }

    return 0;
}

// Quest o --> https://judge.beecrowd.com/pt/problems/view/1068
