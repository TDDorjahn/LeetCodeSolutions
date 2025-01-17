#include <vector>
using std::vector;

class Solution {

public:
    int removeDuplicates(vector<int>& nums) {

        if(nums.size() == 1)
            return 1;

        auto left = nums.begin();
        auto right = left + 1;
        int i = 1;

        while(right != nums.end()) {

            if(left == right) {
                right++;

            } else {

                nums.erase(left, right - 1);
                left = nums.begin() + i;
                right = left + 1;
                i++;

            }

        }

        nums.erase(left, right - 1);

        return i;

    }

};