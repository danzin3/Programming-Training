#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int lastIndex = height.size() - 1;
        int left = 0, right = lastIndex, ans = 0;
        int minHeight = 0, currentArea = 0;

        while (left < right)
        {
            minHeight = min(height[left], height[right]);
            currentArea = minHeight * (right - left);
            ans = max(ans, currentArea);
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return ans;
    }
};
