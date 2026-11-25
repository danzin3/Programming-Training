#include <vector>
using namespace std;
class Solution {
public:
    long long gcd(long long a, long long b) {
        return b ? gcd(b, a % b) : a;
    }
    long long lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / gcd(a, b)) * b;
    }
    int maxLength(vector<int>& nums) {
        int maxLen = 0;
        for(size_t i = 0; i < nums.size(); i++) {
            long long g = 0, l = 1, prod = 1;
            for(size_t j = i; j < nums.size(); j++) {
                prod *= nums[j];
                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);
                if(prod > 1e12) break;
                if(prod == l * g) {
                    int current = (int)(j - i + 1);
                    if(current > maxLen) maxLen = current;
                }
            }
        }
        return maxLen;
    }
};
