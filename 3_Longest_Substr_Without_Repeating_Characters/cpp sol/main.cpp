#include <string>
#include <iostream>
#include <unordered_set>

class Solution {

public:

    int lengthOfLongestSubstring(std::string s) {

        std::unordered_set<char> char_set;
        int max_len = 0, start = 0;

        for(int end = 0; end < s.size(); end++){

            while(char_set.count(s[end])) {

                char_set.erase(s[start]);
                start++;

            }

            char_set.insert(s[end]);
            max_len = std::max(max_len, end - start + 1);

        }

        return max_len;

    }

};

int main(void) {

    Solution solution;
    std::cout << solution.lengthOfLongestSubstring("abcabcbb");

    return 0;

}