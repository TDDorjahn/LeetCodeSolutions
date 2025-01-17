#include <vector>
using std::vector;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        
        const int n1_size = nums1.size();
        const int n2_size = nums2.size();
        int n1_xor = 0, n2_xor = 0;

        if(n1_size % 2 == 1) {

            for(auto num2: nums2){

                n2_xor ^= num2;

            }

        }

        if(n2_size % 2 == 1) {

            for(auto num1: nums1) {

                n1_xor ^= num1;

            }

        }

        return n1_xor ^ n2_xor;
    }

};