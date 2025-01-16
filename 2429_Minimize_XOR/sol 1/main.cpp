class Solution {

private:

    int count_bits(int n) {

        int count = 0;
        for (n; n > 0; n = n & (n - 1)){

            count++;

        }

        return count;

    }

public:

    int minimizeXor(int num1, int num2) {

        int mask = 0xFFFFFFFF;
        int x = num1;

        int b_num1 = count_bits(num1);
        int b_num2 = count_bits(num2);
        int diff = b_num1 - b_num2;

        if(b_num1 == b_num2)
        {

            return x;

        }
        else if(b_num1 - b_num2 > 0) 
        {

            for(int i = 0; i < diff; ++i){

                x = x & (x - 1);

            }

        } 
        else 
        {

            diff *= -1;

            for(int i = 0; i < diff; ++i) {

                x = x | (x + 1);

            }

        }
        

        return x;
        
    }

};