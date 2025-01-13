from collections import Counter

class Solution:
    def takeCharacters(self, s: str, k: int) -> int:

        if k == 0:
            return 0
        
        letter_map = Counter(s)

        if letter_map['a'] < k or letter_map['b'] < k or letter_map['c'] < k:
            return -1
        
        window_length = start = 0

        for index, char in enumerate(s):
            letter_map[char] -= 1

            while letter_map[char] < k:
                letter_map[s[start]] += 1
                start += 1

            window_length = max(window_length, index - start + 1)

        return len(s) - window_length