#include <vector>
#include <numeric>
#include <iostream>

using std::vector;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {

        return (std::accumulate(derived.begin(), derived.end(), 0, std::bit_xor())) == 0;
        
    }
};