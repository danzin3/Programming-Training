#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() % 2 != 0)
            return false;
        stack<char> pilha;
        for (char ch : s)
        {
            if (ch == '(' || ch == '[' || ch == '{')
            {
                pilha.push(ch);
            }
            else
            {
                if (pilha.empty())
                    return false;
                char lastItem = pilha.top();

                if ((ch == ')' && lastItem != '(') ||
                    (ch == ']' && lastItem != '[') ||
                    (ch == '}' && lastItem != '{'))
                {
                    return false;
                }
                pilha.pop();
            }
        }
        return pilha.empty();
    }
};
