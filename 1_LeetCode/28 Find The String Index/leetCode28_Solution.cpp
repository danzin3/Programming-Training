#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t i = haystack.find(needle);
        if(i == std::string::npos) {
            return -1;
        } else {
            return i;
        }
        // Or just this:
        // return haystack.find(needle);
    }
};
