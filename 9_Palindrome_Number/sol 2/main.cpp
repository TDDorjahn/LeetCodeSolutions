class Solution {

public:
    bool isPalindrome(int n) {

        long long reversed_num = 0;
        int n_copy = n;

        for(n_copy; n_copy > 0; n_copy /= 10) {

            reversed_num = reversed_num * 10 + n_copy % 10;

        }

        if(n == reversed_num)
            return true;
        
        return false;

    }

};