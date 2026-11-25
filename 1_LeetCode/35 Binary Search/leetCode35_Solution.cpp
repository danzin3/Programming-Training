#include <vector>
//#include <algorithm>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0, right = n - 1, mid = 0;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
        }
        return left;
        // Or, using algorithm standar library:
        // return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
