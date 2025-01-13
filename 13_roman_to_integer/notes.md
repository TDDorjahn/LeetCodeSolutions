## Problem:
Roman numerals are represented by seven different symbols: `I`,  `V`,  `X`,  `L`,  `C`,  `D`  and  `M`.

**Symbol**       **Value**
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, `2`  is written as  `II` in Roman numeral, just two ones added together.  `12`  is written as `XII`, which is simply  `X + II`. The number  `27`  is written as  `XXVII`, which is  `XX + V + II`.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not  `IIII`. Instead, the number four is written as  `IV`. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as  `IX`. There are six instances where subtraction is used:

-   `I`  can be placed before  `V`  (5) and  `X`  (10) to make 4 and 9.
-   `X`  can be placed before  `L`  (50) and  `C`  (100) to make 40 and 90.
-   `C`  can be placed before  `D`  (500) and  `M`  (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.

### Thoughts:
Representing a roman numeral into an integer number is essentially adding up all the translated roman numerals as it is read. However, sometimes subtraction is needed as per the roman numeral representation. Since this problem relies on addition, the subtraction can be done through adding negative numbers. This can be done either right to left or left to right due to properties of addition. Making a map of the roman numerals translated to an integer will make this easier, and reading the string in reverse order will make determining if a positive or negative number needs added easier.

### Solution 1: (Passed) [11ms runtime]
This solution is to show the implementation of the algorithm with STL containers such as a `map` and `reverse iterators`. The map is private to the `Solution` class which contains the roman numeral to integer conversion. A helper function is also private, which will determine whether or not subtraction is needed or not. The function signature is: `int subtraction(char current, char previous, int &num);` which will either return a negative in the case of subtraction or `num` if none is needed. I initialize an integer `decimal_val` for the decimal value of the roman numeral, and a character called current and previous, both initialized to point to the end of the string with a reverse iterator. Next, I match `current` with the integer equivalent and add it to `decimal_val` before going into a loop since no subtraction will be needed for the first value. I then loop through the string in reverse with reverse iterators, starting at the second to last character until I reach the beginning of the string. `current` is set to the dereferenced reverse iterator `rit` and then we add the value to `decimal_val` by writing `decimal_val += subtraction(current, previous, decimal_val);` where `current` will a conditional to a switch case since `current` points to a character that determines subtraction from the table above. If it passes one of the tests, return the respective negative integer (-1 for IV and IX, -10 for XL and XC, -100 for CD and CM), not it fails, just return the `num`. Set `previous` to `current` and iterate until `rit` has no more characters to read from the string. Return `decimal_val`.

### Solution 2: (Passed) [1ms runtime]
This solution tries to speed things up, which it did but inconsistently, by not using reverse iterators and the slow switch statement. The map remains the same, but the switch statement within the method `int subtraction(...)` has been replaced with if statements. Next, the reverse iterators were replaced with raw pointers with an integer `end` being set to the string's length - 1, which will be a place holder for the end of the string. It logically still works the same way, but rewritten to have less overhead since an STL container, the reverse iterators, are gone and less overhead from getting rid of the switch statement.