## Problem:
Given two positive integers  `num1`  and  `num2`, find the positive integer  `x`  such that:

-   `x`  has the same number of set bits as  `num2`, and
-   The value  `x XOR num1`  is  **minimal**.

Note that  `XOR`  is the bitwise XOR operation.

Return  _the integer_ `x`. The test cases are generated such that  `x`  is  **uniquely determined**.

The number of  **set bits**  of an integer is the number of  `1`'s in its binary representation.

**Constraints:**

-   `1 <= num1, num2 <= 109`

**Hints:**
1. To arrive at a small xor, try to turn off some bits from num1
2. If there are still left bits to set, try to set them from the least significant bit

### Thoughts:
Basically, in plain English, we need a number `x` such that the total set bits of `x` equals the total set bits of `num2`, but is the `x XOR num1` is the most minimum value possible and return `x`. At first, I was lost until I read the hints (listed above). In my mind, we need to grab the total bits of `num1` and `num2` since  I'll need to know how many bits `num2` has to verify `x`. Quick research brought up the Brain Kernighan algorithm which counts the set bits given a number `n`, I'll call the count of set bits to bits(n) where n is a positive integer. The examples provided helped clarify what these totals will do:

**Example 1:**
**Input:** num1 = 3, num2 = 5
**Output:** 3
**Explanation:**
The binary representations of num1 and num2 are 0011 and 0101, respectively.
The integer **3** has the same number of set bits as num2, and the value `3 XOR 3 = 0` is minimal.

**Example 2:**
**Input:** num1 = 1, num2 = 12
**Output:** 3
**Explanation:**
The binary representations of num1 and num2 are 0001 and 1100, respectively.
The integer **3** has the same number of set bits as num2, and the value `3 XOR 1 = 2` is minimal.

In both situations, x = 3. In example 1, this tells me that x is set to num1 initially and could apply to all solutions. In example 2, x = 3, and bits(num1) < bits(num2). With the hints and knowing 0001 = 1 and 0011 = 3, we should set bits starting at the rightmost unset bit for this example. Likewise, if bits(num1) > bits(num2), then we should unset bits starting at the rightmost set bit. After quickly researching how to set and unset the rightmost bits, I was ready to code some solutions and see how I can improve them.

### Solution 1: (Passed) [0ms runtime]
I made a private method for the `class Solution` with a signature of `int count_bits(int n);` that implemented the Brain Kernighan algorithm. I would've used an unsigned integer to prevent undefined behavior, but that's a performance loss and the constraints prevented a negative count or negative `n`.  Within the public method provided by leetcode, `int minimizeXor(int num1, int num2);`, I create an integer `x` and set it to `num1`. Next, two integers `b_num1` and `b_num2` are set to the results of `count_bits(num1);` and `count_bits(num2);` respectively. An integer `diff` is the difference of `b_num1 - b_num2`. After this part wherein lies my most pathetic code in 2025, only 15 days in. I compare if `b_num1 == b_num2` and return x. Else if `b_num - b_num2 > 0`, then iterate `diff` times and set `x &= x - 1;`. Else flip the sign of `diff` and iterate `diff` times, setting `x |= x + 1;`. Then return `x`. Silly, but it worked, but it was confusing, but I was in the process of rewriting the code to use less memory. Anyway, the solutions later on of this confusing code are rewritten to be less confusing and inconsistent. I'm skipping solution 2 because it is more or less the same. Also, there's a mask in there, not needed, just thought I needed it but didn't remove it afterward.

### Solution 3: (Passed) [0ms runtime]
Solution 3 dealt with changing the Kernighan algorithm to deal with both num1 and num2 total bits in the same loop instead of calling it twice for b_num1 and b_num2. I was hoping this would save a call on the stack. I changed the method signature of `count_bits` to reflect this change: `void inline count_bits(int n, int m, int &b_num1, int &b_num2);`. The `void` is there because I don't need to return anything if passing `b_num1` and `b_num2` by reference. Since `n` and `m` are copies of num1 and num2 respectively, we can work on `n` and `m` without affecting `num1` and `num2`. Now the method uses a while loop, checking if both `n` and `m` are greater than 0. If so, check if `n > 0`, if so, `b_num1 += n & 1` and `n >>= 1`. After that, check if `m > 0`, if so, `b_num2 += m & 1` and `m >>= 1`. The logic is done slightly differently, but the result is the same. The integer `diff` is omitted since using `b_num1` and `b_num2` uses less memory for the comparisons. This did use less memory and had the same runtime. The rest of the posted solutions on my leetcode is just me trying to optimize the memory even more and only succeeding once at solution 5, but it did run at a 2ms runtime and was only 0.2MB less than the first solution.