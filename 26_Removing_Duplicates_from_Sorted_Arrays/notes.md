## Problem:
Given an integer array  `nums`  sorted in  **non-decreasing order**, remove the duplicates  [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm)  such that each unique element appears only  **once**. The  **relative order**  of the elements should be kept the  **same**. Then return  _the number of unique elements in_ `nums`.

Consider the number of unique elements of  `nums`  to be  `k`, to get accepted, you need to do the following things:

-   Change the array  `nums`  such that the first  `k`  elements of  `nums`  contain the unique elements in the order they were present in  `nums`  initially. The remaining elements of  `nums`  are not important as well as the size of  `nums`.
-   Return  `k`.

**Custom Judge:**

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}

If all assertions pass, then your solution will be  **accepted**.

**Example 1:**

**Input:** nums = [1,1,2]
**Output:** 2, nums = [1,2,_]
**Explanation:** Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

**Example 2:**

**Input:** nums = [0,0,1,1,1,2,2,3,3,4]
**Output:** 5, nums = [0,1,2,3,4,_,_,_,_,_]
**Explanation:** Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

**Constraints:**

-   `1 <= nums.length <= 3 * 104`
-   `-100 <= nums[i] <= 100`
-   `nums`  is sorted in  **non-decreasing**  order.

### Thoughts:
The structure of a sorted array with repeating characters is just some arbitrary number `n` where `n` is the total repeats of the number after discovering a unique number. A two pointer solution solves this problem, where the left pointer can be sitting at the first occurrence of a unique number and the right pointer will be moving to the right, checking if the number it is pointing to is unique or the same as the left. Keeping track of how many moves the right pointer makes tells us how many numbers to remove starting at the left pointer.

### Solution 1: (Passed) [0ms runtime]
First, check the size of the array to see if it is 1, if it is, return 1. Otherwise, I set a left and right iterator to the beginning and the left + 1 respectively, and an integer `i` that keeps track of where to start when it is time for left to move, initially set to 1. I jump into a while loop that checks to see if the right pointer has reached the end. The first thing the loop does is check if the left and right elements are equal, if so, move the right pointer. Else, if the right side is different, then erase the duplicate elements with `nums.erase(left, right - 1);`, set `left = nums.begin() + i;`, make right `left + 1` and update and increment `i` by one. After loop execution has stopped, execute `nums.erase(left, right - 1);` again to get rid of the duplicates at the end. Then, return `i`, since it starts at 1 and moves the total times the left pointer moves, it will be the size of the array with deleted duplicate elements, which is what needs returned.

### Afterthoughts:
The solution could definitely use less memory when dealing with the iterators provided by the STL of C++. However, the erase function of the vectors, which is what is provided, requires iterators. This doesn't mean that left and right have to be iterators, they can simply be the offset from the beginning or ending iterators, i.e. `nums.erase(nums.begin() + left, nums.begin() + right - 1);`. I will most likely come up with a solution that uses less memory by eliminating the overhead from the STL as much as possible.