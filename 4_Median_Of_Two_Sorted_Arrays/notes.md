## Problem:
Given two sorted arrays  `nums1`  and  `nums2`  of size  `m`  and  `n`  respectively, return  **the median**  of the two sorted arrays.

The overall run time complexity should be  `O(log (m+n))`.

**Example 1:**

**Input:** nums1 = [1,3], nums2 = [2]
**Output:** 2.00000
**Explanation:** merged array = [1,2,3] and median is 2.

**Example 2:**

**Input:** nums1 = [1,2], nums2 = [3,4]
**Output:** 2.50000
**Explanation:** merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

**Constraints:**

-   `nums1.length == m`
-   `nums2.length == n`
-   `0 <= m <= 1000`
-   `0 <= n <= 1000`
-   `1 <= m + n <= 2000`
-   `-106 <= nums1[i], nums2[i] <= 106`

### Thoughts:
Probably one of the hardest tasks I've seen in my life. Only because of the second line "The overall run time complexity should be `O(log (m + n))`. I figured I'd give brute forcing it a try and then move on to the correct time complexity, but the brute forcing does have some important lessons to be learned. Regardless, this is a divide and conquer problem.

### Solution 3: (Passed) [11ms runtime]
Solution 1 and 2 give the wrong answer in some of the test cases, solution 3 corrects that. The main difference between solution 1 and solutions 2 and 3 are that 1 uses a set while 2 and 3 use multisets. The given method to the solution is `double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2);` I first make a multiset `std::multiset<int> cache;` and emplace each number from nums1 and nums2 into the cache. Another vector is made afterward called `sorted_vec` and reserve the size to the size of the cache. Next I populate the sorted vector by emplacing back the elements from the cache. Since the multiset is something that sorts itself while pushes values into it, we can get a sorted list from it directly. Finally, we check whether the cache size is even, if it is, then the statement `return static_case<double>((sorted_vec[(cache.size() - 1) / 2] + 
sorted_vec[cache.size() / 2]) / 2.0f);` is executed. This basically averages the two numbers in the sorted vector that make up the middle (since lists with even total elements don't have a true center). If there are an odd number of elements in the sorted vector, it'll simply execute: `return static_cast<double>(sorted_vec[cache.size() / 2]);` Not much to this one.

### Solution 5:
Solution 4 is the same as Solution 5, but solution 5 applies const-ness to fields that do not need changed, such as the size of the lists and a field called `half` being const. In this solution, the divide and conquer is applied. We'll have constant sizes called m and n, where m is the size of `nums1` and n is the size of `nums2`. Next, for simplicity's sake, I check if m > n, if not, we simply return recursive call to our method with the vectors swapped in the arguments. I set an integer `left` to 0 and `right` to m, or the right most element in `nums1`, while the const half way point of both vectors is `(m + n + 1) / 2;`, which is the total elements on the left of the combined arrays to split them in half. Now I go into a while loop, checking if left < right. In this loop, I calculate the mid point `int mid = left + (right - left) / 2;` of both vectors. Next, check if `nums1[mid] < nums2[half - mid - 1]`, if so, set left to `mid + 1`, shifting the search range to the right. Else, set `right = mid;` to shift the search range to the left. The reason `nums2` needs the `half - mid - 1` is because the vectors aren't merged yet, so this will get the proper middle for both vectors. Once `left == right`, the loop stops, meaning the correct partition is found. Now, an integer `i = left` and `j = half - i` are made, where `i` and `j` are the partition indices in `nums1` and `nums2`. The next part is... complicated, but after searching more into this topic, this was needed. `nums1_left` and `nums2_left` are the largest elements on the left side of the partition and `nums1_right` and `nums2_right` are the smallest elements on the right of the partition. Edge cases needed to be tested, however, so setting them directly to their respective values without testing if the right or left of `nums1` and `nums2` is dangerous, so the solution was to set it to `INT_MIN` and `INT_MAX` with respect to finding the smallest or largest elements. Finally, I can calculate the median of the two sorted arrays. The statement `if(m + n) % 2 == 1)` checks if the total elements is odd, if so, just find the max of `nums1_left` and `nums2_left` and return it. It it is even, we'll skip this condition and return `(std::max(nums1_left, nums2_left) + std::min(nums1_right, nums2_right)) / 2.0f;` This solution runs at a time complexity of `O(log(min(m,n)))` instead, which is better than `O(log(m + n))`. The space complexity is `O(1)` since vectors are constant space complexity and no other data structures were used.