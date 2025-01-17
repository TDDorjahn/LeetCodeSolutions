#include <vector>
using std::vector;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> xor_pairs = {};

        for(auto num1 : nums1) {

            for(auto num2: nums2) {

                xor_pairs.emplace_back(num1 ^ num2);

            }

        }

        int xor_result = xor_pairs[0];

        for(int i = 1; i < xor_pairs.size(); ++i) {

            xor_result ^= xor_pairs[i];

        }

        return xor_result;

    }

};