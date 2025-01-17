#include <vector>
#include <numeric>

using std::vector;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {

        int xor_sum = std::accumulate(derived.begin(), derived.end(), 0, std::bit_xor());

        return xor_sum == 0;
        
    }
};