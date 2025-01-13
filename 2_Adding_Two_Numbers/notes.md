## Problem:
You are given two  **non-empty**  linked lists representing two non-negative integers. The digits are stored in  **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

### Thoughts:
We've got to go through both linked lists' nodes simultaneously, adding the number that is within each node into a new node that'll be inserted into a new list. A case I need to deal with is when I need to carry over a one if the sum is greater than 9, so we'll need an integer to carry over the 1.

### Solution 1: (Failed Attempt)
I created a linked list called sum_list and a temporary list called temp that is set to the previously created linked list, sum_list. An integer is made to store the carry. Check if the lists aren't pointing to null, if they are, return nullptr, else, we'll iterate through the two lists. We iterate while the lists aren't null, in future solutions, we'll include the carry to check if the carry is 1 or 0 (This prevents exceeding memory constraints, along with different pointer comparisons, in future solutions). Check if both lists aren't pointing to null, if not, sum up their values and move the node points to the next node. Set carry equal to the sum divided by 10 and set temp->next to a new node and pass sum % 10 as the argument. Move the temp pointer to the next node. This solution, and the future solutions, are O(n) since I iterate through the linked lists simultaneously while I create the nodes for sum_list with constant time operations.

### Solution 2: (Passed) [2ms runtime]
The same as solution one, except carry is now a condition for the while loop because even if there are no more nodes to visit in the linked lists doesn't mean that there aren't more numbers to add to the linked list returned by the function. The comparisons to check if the two lists are pointing to null were separated out due to the fact that the two lists may not be equal length and we still need to perform addition with one node. With these two changes, memory expectations were finally met.

### Solution 3: (Passed) [4ms runtime]
I initialized the sum_list with 0 to see if any performance gains could come from initializing instead of having a list with many unknowns, however, this was false. It slowed the solution down and added 0.1mb of memory.

### Solution 4: (Passed) [0ms runtime]
I changed the carry from an unsigned integer to an integer. Since there is more overhead with unsigned integers, the solution is made slower by it with slightly more memory. Since signed integers are native to CPUs, that is, no extra operations are needed to work with them, it runs faster. 