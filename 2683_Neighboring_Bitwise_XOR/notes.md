## Problem:
A  **0-indexed**  array  `derived`  with length  `n`  is derived by computing the  **bitwise XOR** (⊕) of adjacent values in a  **binary array**  `original`  of length  `n`.

Specifically, for each index  `i`  in the range  `[0, n - 1]`:

-   If  `i = n - 1`, then  `derived[i] = original[i] ⊕ original[0]`.
-   Otherwise,  `derived[i] = original[i] ⊕ original[i + 1]`.

Given an array  `derived`, your task is to determine whether there exists a  **valid binary array**  `original`  that could have formed  `derived`.

Return  _**true**  if such an array exists or  **false**  otherwise._

-   A binary array is an array containing only  **0's**  and  **1's**

**Example 1:**

**Input:** derived = [1,1,0]
**Output:** true
**Explanation:** A valid original array that gives derived is [0,1,0].
derived[0] = original[0] ⊕ original[1] = 0 ⊕ 1 = 1 
derived[1] = original[1] ⊕ original[2] = 1 ⊕ 0 = 1
derived[2] = original[2] ⊕ original[0] = 0 ⊕ 0 = 0

**Example 2:**

**Input:** derived = [1,1]
**Output:** true
**Explanation:** A valid original array that gives derived is [0,1].
derived[0] = original[0] ⊕ original[1] = 1
derived[1] = original[1] ⊕ original[0] = 1

**Example 3:**

**Input:** derived = [1,0]
**Output:** false
**Explanation:** There is no valid original array that gives derived.

**Constraints:**

-   `n == derived.length`
-   `1 <= n <= 105`
-   The values in  `derived` are either  **0's**  or  **1's**

### Thoughts:
Really, all we need to do is just validate that there exists some list such that derived can be made. Since the derived list comes from XOR, we can use XOR to validate the derived list has an original list. Each derived list will either have an even total of set bits, or an odd total. If it is even, an xor sum of the list will be 0, meaning there is a valid original list, or 1, meaning there is no valid original list.

### Solution 1: (Passed) [7ms runtime]
I really wanted to practice using the STL again, so I set an integer `int xor_sum=  std::accumulate(derived.begin(), derived.end(), 0, std::bit_xor());` which will perform the operation `std::bit_xor` on the list, accumulating the results and returning it. Next, we just return if xor_sum == 0;

### Solution 2: (Passed) [3ms runtime]
This is the solution that tries to not deal with the STL as much as possible, besides the provided vector. Two integers `int xor_sum = 0, i = 0;` are made. Then the loop `for(i; i  <  derived.size(); ++i) { xor_sum  ^=  derived[i]; }` is executed, accumulating all the xor results for `xor_sum`. Return the comparison `xor_sum == 0`.

### Solution 3: (Passed) [1ms runtime]
This solution makes the first solution a one-liner: 
`return (std::accumulate(derived.begin(), derived.end(), 0, std::bit_xor())) ==  0;`