#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> lastPos;
        int left = 0, maxLen = 0;

        for (int right = 0; right < (int)s.size(); right++)
        {
            char ch = s[right];
            if (lastPos.count(ch) && lastPos[ch] >= left)
            {
                left = lastPos[ch] + 1;
            }
            lastPos[ch] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
