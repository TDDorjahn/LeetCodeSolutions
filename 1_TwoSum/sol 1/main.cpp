#include <vector>
#include <unordered_map>

class Solution {

public:

    std::vector<int> twoSum(std::vector<int>& nums, int target) {

        std::unordered_map<int, int> map;
        std::vector<int> indices;

        for (int i = 0; i < nums.size(); ++i) {
        int num = nums[i];
        int difference = target - num;

            if (map.find(difference) != map.end()) {
                indices.push_back(map[difference]);
                indices.push_back(i);
                return indices;
            }

            map[num] = i;
        }

        return indices;

    }

};