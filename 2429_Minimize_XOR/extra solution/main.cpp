
/**
 * Extra solution is the best formatted and easiest to read while maintaining its speed. Not necessarily the best solution.
 */

class Solution {

private:

    void inline count_bits(int n, int m, int &b_num1, int &b_num2) {

        while(n > 0 || m > 0) {

            if(n > 0) {

                b_num1 += n & 1;
                n >>= 1;

            }

            if(m > 0) {

                b_num2 += m & 1;
                m >>= 1;

            }

        }

    }

public:

    int minimizeXor(int num1, int num2) {

        int x = num1;
        int b_num1 = 0, b_num2 = 0;

        count_bits(num1, num2, b_num1, b_num2);

        if(b_num1 > b_num2) 
        {

            for(int i = 0; i < (b_num1 - b_num2); ++i){

                x &= x - 1;

            }

        } 
        else if (b_num1 < b_num2)
        {

            for(int i = 0; i < (b_num2 - b_num1); ++i) {

                x |= x + 1;

            }

        }
        

        return x;
        
    }

};
