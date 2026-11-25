#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    void backtrackFunc(vector<string> &result, string &current, int opened,
                       int closed, int n)
    {
        if (current.size() == 2 * n)
        {
            result.push_back(current);
            return;
        }

        if (opened < n)
        {
            current.push_back('(');
            backtrackFunc(result, current, opened + 1, closed, n);
            current.pop_back();
        }

        if (closed < opened)
        {
            current.push_back(')');
            backtrackFunc(result, current, opened, closed + 1, n);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string current;
        current.reserve(2 * n);
        backtrackFunc(ans, current, 0, 0, n);
        return ans;
    }
};
