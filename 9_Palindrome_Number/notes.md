## Problem:
Given an integer `x`, return `true` _if_ `x` _is a_ _**palindrome**_ _, and_ `false` _otherwise_.

### Thoughts:
Not the hardest problem in the world, but still needed to sit down and think some things through. First thought would be to make an integer for the reversed number of the argument pass through, which is `n`. I also need a copy of `n` so that I don't modify the original value and I'll have something to compare to.

### Solution 1: (Failed) [Run Time Error]
I initialize an integer `reversed_num` to 0 and `n_copy` to `n`. A for loop is used starting at `n_copy`, while `n_copy > 0`, and the logic being `n_copy /= 10`. This will take each number in the number's place, such as ones, tens, hundreds, etc. Set `reversed_num = revered_num * 10 + n_copy % 10;`. The `reversed_num * 10` sets the number place where the digit extracted is going to go and `+ n_copy % 10` will grab `n_copy`'s right most number and add it onto `reversed_num`. We check if `reversed_num == n`, or if the reversed number is equal to the original number, meaning it is a palindrome. If it is, return true, else return false. The runtime error comes from the fact that `reversed_num` is only a 32-bit integer.

### Solution 2: (Passed) [0ms]
As mentioned before, the runtime error comes from the fact that `reversed_num` is a 32-bit integer, so some operations such as `reversed_num * 10` cannot be done. Fixing it required changing it to a long long, a 64-bit integer. 