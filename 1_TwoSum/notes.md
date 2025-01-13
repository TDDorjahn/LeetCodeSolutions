## Problem

Given an array of integers  `nums` and an integer  `target`, return  indices of the two numbers such that they add up to  `target`.

You may assume that each input would have  **_exactly_  one solution**, and you may not use the  _same_  element twice.

You can return the answer in any order.
### Thoughts:
We could go through the whole list with two pointers that, when dereferenced, will add together and compare if the result is the target. However, that's an O(n^2) solution since we need to scan the array with two pointers. Ideally, the most optimal solution scans through the array once to get O(n) time complexity, which is the minimum complexity achievable.
### Approach:
We can find the target by making an unordered map that stores the differences between the target and the current number that we are on in the list and a list that holds the indices of visited indices of the list passed in. If the difference isn't found, insert the key-value pairs of the number currently pointed to and the index into the map. If it is found, insert the index from the map into the list and the current index. The difference of the target and the current number in the list can be used because we can search for the difference within the list, so if the target is 9 and the first element is 2, we can search for 7 that we have stored in our map, eliminating the need for two loops.

### Solution 1:
Solution 1 implements this design. I create an unordered map and a vector, where the map will hold the key-value pairs for the difference and index respectively, while the vector called indices will hold the indices where the elements add up to the target. Looping through the vector passed in, called nums, we insert the difference-index key-value pairs into the map if the difference isn't found in the vector nums. If it is found (from previous iterations), then return the indices.

>**Note:** When inserting into the indices vector, I use the push_back method, which will create an object to be inserted into the list. A minor inefficiency comes from the copying of this object, however, a different method is used in Solution 2. The push_back method slowed the algorithm by 3ms.

### Solution 2:
It is exactly the same as Solution 1, but the push_back method is replaced with the emplace_back method. The emplace_back method will create a reference to a new vector with the index inserted at the back. This is faster than push_back, which creates an object to be inserted, copies it, and inserts it to the end of the vector. Whereas emplace_back will take the current vector, insert the value at the end, and return a reference to the new vector created. This shaved off the 3ms to 0ms runtime.