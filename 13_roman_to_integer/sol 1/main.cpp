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

        switch(current) {

            case 'I':
                if(previous == 'V' || previous == 'X')
                    return -1;

            case 'X':
                if(previous == 'L' || previous == 'C')
                    return -10;

            case 'C':
                if(previous == 'D' || previous == 'M')
                     return -100;

            default:
                return roman_numerals.at(current);

        }

    }


public:
    int romanToInt(string &s){

        int decimal_val = 0;
        char current = *s.rbegin(), previous = *s.rbegin();

        decimal_val += roman_numerals.at(current);

        for(auto rit = s.rbegin() + 1; rit != s.rend(); ++rit) {

            current = *rit;
            decimal_val += subtraction(current, previous, decimal_val);

            previous = current;
            
        }

        return decimal_val;

    }

};