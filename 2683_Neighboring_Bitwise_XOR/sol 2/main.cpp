#include <vector>
using std::vector;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {

        int xor_sum = 0, i = 0;

        for(i; i < derived.size(); ++i) { xor_sum ^= derived[i]; }

        return xor_sum == 0;

    }
};