#include <string>
#include <vector>

class Solution {

private:

    bool is_unique(std::string s) {

        for(int i = 0; i < s.size(); ++i){

            if(i < s.size() - 1) {

                for(int j = i + 1; j < s.size(); ++j){

                    if(s[j] == s[i] || std::isspace(s[i]))
                        return false;

                }

            }

        }

        return true;

    }

public:

    int lengthOfLongestSubstring(std::string s) {

        if(s.empty())
            return 0;

        std::vector<std::string> strs;
        int max_len = 1;

        for(auto len = 1; len < s.size(); len++) {

            for(auto pos = 0; pos <= s.size(); pos++) {

                std::string substrs = s.substr(pos, len);

                if(substrs.size() < len)
                    continue;

                if(is_unique(substrs)) {

                    strs.emplace_back(substrs);
                    max_len = substrs.size();

                }

            }

        }

        return max_len;

    }

};