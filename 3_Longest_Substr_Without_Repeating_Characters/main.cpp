#include <string>
#include <vector>
#include <iostream>

class Solution {

public:

    int lengthOfLongestSubstring(const std::string& s){

        int max_len = 0;

        for(auto& c : s){

            std::cout << c << ' ';
            

        }

        return 0;

    }

};

unsigned int my_sqrt(unsigned int n) {

    //Basically long hand division but with bits

    unsigned int result = 0;
    unsigned int bit = 1 << 30;

    while (bit > n){

        bit >>= 2;

    }

    while(bit != 0) {

        if(n >= result + bit){

            n -= result + bit;
            result = (result >> 2) + bit;

        } else {
            result >>= 1;
        }

        bit >>= 2;

    }

    return result;

}

int main(void) {

    Solution solution;
    std::cout << solution.lengthOfLongestSubstring("ababccbaabab");

}