#include <string>
#include <map>
#include <iostream>

using std::string, std::map, std::cout;

/**
 * Constraints:
 * 1 <= s.length <= 15
 * s ∈ {'I', 'V', 'X', 'L', 'C', 'D', 'M'}
 * Guaranteed that s is a valid roman numeral will be in range of [1, 3999]
 */

class Solution {

private:
    const map<char, int> roman_numerals {

        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}

    };

    int subtraction(char current, char previous, int &num) {

        if(current == 'I' && (previous == 'V' || previous == 'X'))
            return -1;
        else if(current == 'X' && (previous == 'L' || previous == 'C'))
            return -10;
        else if(current == 'C' && (previous == 'D' || previous == 'M'))
            return -100;
        else
            return roman_numerals.at(current);

    }


public:
    int romanToInt(string &s){

        int decimal_val = 0;
        const int end = s.length() - 1;
        char current, previous;
        current = previous = s[end];

        decimal_val += roman_numerals.at(current);

        for(int i = end - 1; i >= 0; --i) {

            current = s[i];
            decimal_val += subtraction(current, previous, decimal_val);

            previous = current;
            
        }

        std::cout << decimal_val << '\n';

        return decimal_val;

    }

};

int main(void) {

    Solution sol;
    string roman_numeral = "MMCDXLIV";

    sol.romanToInt(roman_numeral);

}