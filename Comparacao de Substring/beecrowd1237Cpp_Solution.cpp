#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    while (getline(cin, s1) && getline(cin, s2)) {
        if (!s1.empty() && s1.back() == '\r') s1.pop_back();
        if (!s2.empty() && s2.back() == '\r') s2.pop_back();

        int ans = 0, dp[51][51] = {};
        for (int i = 1; i <= (int)s1.size(); i++)
            for (int j = 1; j <= (int)s2.size(); j++)
                if (s1[i - 1] == s2[j - 1])
                    ans = max(ans, dp[i][j] = dp[i - 1][j - 1] + 1);

        cout << ans << "\n";
    }
 
    return 0;
}
