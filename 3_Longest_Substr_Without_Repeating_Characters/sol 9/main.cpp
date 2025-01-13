#include <string>
#include <vector>
#include <unordered_set>

class Solution {

private:

    bool is_unique(std::string s) {

        std::unordered_set<char> char_set;

        for(char& c : s) {

            if(char_set.count(c))
                return false;

            char_set.insert(c);

        }

        return true;

    }

public:

    int lengthOfLongestSubstring(std::string s) {

        if(s.empty())
            return 0;

        int max_len = 0;

        for(auto len = 0; len <= s.size(); len++) {

            for(auto pos = 0; pos <= s.size() - len; pos++) {

                std::string substrs = s.substr(pos, len);

                if(is_unique(substrs)) {

                    max_len = std::max(max_len, (int)(substrs.size()));

                }

            }

        }

        return max_len;

    }

};