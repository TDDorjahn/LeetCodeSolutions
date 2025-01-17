## Problem:
You are given two  **0-indexed**  arrays,  `nums1`  and  `nums2`, consisting of non-negative integers. There exists another array,  `nums3`, which contains the bitwise XOR of  **all pairings**  of integers between  `nums1`  and  `nums2`  (every integer in  `nums1`  is paired with every integer in  `nums2`  **exactly once**).

Return _the  **bitwise XOR**  of all integers in_ `nums3`.

**Example 1:**

**Input:** nums1 = [2,1,3], nums2 = [10,2,5,0]
**Output:** 13
**Explanation:**
A possible nums3 array is [8,0,7,2,11,3,4,1,9,1,6,3].
The bitwise XOR of all these numbers is 13, so we return 13.

**Example 2:**

**Input:** nums1 = [1,2], nums2 = [3,4]
**Output:** 0
**Explanation:**
All possible pairs of bitwise XORs are nums1[0] ^ nums2[0], nums1[0] ^ nums2[1], nums1[1] ^ nums2[0],
and nums1[1] ^ nums2[1].
Thus, one possible nums3 array is [2,5,1,6].
2 ^ 5 ^ 1 ^ 6 = 0, so we return 0.

**Constraints:**

-   `1 <= nums1.length, nums2.length <= 105`
-   `0 <= nums1[i], nums2[j] <= 109`

**Hints:**
1. Think how the count of each individual integer affects the final answer.
2. If the length of nums1 is m and the length of nums2 is n, then each number in nums1 is repeated n times and each number in nums2 is repeated m times.

### Thoughts:
The continuation of XOR week for leetcode ongoing, so another daily problem with XOR. The main idea using logical pairings of `vector<int> nums1` and `vector<int> nums2` where the size of `nums1` is `n` and `nums2` is `m`. Keyword here is *logical pairings*, and just by doing this problem, one can figure out that the `xor` operation has the *communitive property*, so the order which we `xor` does not matter, we just have to get each element of `nums1` and `nums2` to `xor` properly. Initially, I didn't think the sizes of the vectors mattered much, but in Solution 2, I'll discuss why the evenness of the vectors matters.

### Solution 1: (Failed) [Memory Limit Exceeded]
My initial thought was to create a vector `vector<int> xor_pairs = {};` that is initialized to an empty list that'll hold the result of `xor`'ing the two numbers of `nums1[n]` and `nums2[m]`. I created two ranged loops with one nested, where inside the nested loop, I execute `xor_pairs.emplace_back(num1 ^ num2);` where `num1` and `num2` are the current elements for vectors `nums1` and `nums2` respectively. This grabs the unique pairs from the vectors and performs the `xor` operation on them. Now `xor_pairs` contains the resulting `xor` multiplication between the two elements. Next, `int xor_result = xor_pairs[0];` is made after the loops which will hold on to the first `xor`'d element. A for loop `for(int i = 1; i < xor_pairs.size(); ++i) { ... }` will go through the vector and `xor` the elements with `xor_result` by `xor_result ^= xor_pairs[i];`. We then return `xor_result` once the loop is finished. This failed memory expectations because some test cases show that `nums1` and `nums2` can be pretty long with 105 elements being the maximum for each vector. So, a different approach was needed, because storing that many elements, worst case 210 elements in `xor_pairs`, is too much memory to put into a list logically.

### Solution 2: (Passed) [0ms runtime]
Even though the last solution passed a lot of the test cases, it did not consider memory allocation. After solution 1 is when I figured out `xor` was communitive and that using two loops to populate another vector wasn't good enough, despite the problem itself hinting to use another vector. All that needs to happen now is to check if each list is either even or odd, if one of them is odd, `xor` that list by itself, else, all we need to do is `xor` 0 and 0. This solution first grabs the sizes for `nums1` and `nums2` and stores them in integers `n1_size` and `n2_size` respectively. Next, integers `n1_xor` and `n2_xor` are set to 0 to represent the `xor` operations on `nums1` and `nums2` if and only if one, or both their sizes are odd. Next, check if `n1_size` is odd, if so, iterate over `nums2` and set `n2_xor ^= num2` where `num2` is the element from `nums2` currently being pointed to. Jumping out the loop and conditional, if `n2_size` is odd, repeat the same process above but for vector `nums1`. After jumping out of that, return `n1_xor ^ n2_xor`. This will immediately if `n1_size` and `n2_size` are even.