# Intuition

The problem is essentially about counting how many swaps are required to arrange a binary string (composed of `0`s and `1`s) such that all `0`s come before all `1`s. Every `0` before a `1` is already correctly positioned, but every `0` after a `1` would require swapping to the left.

The idea is to traverse the string and count how many `1`s have been seen so far (`b`). For each `0` encountered, the number of steps required is the total number of `1`s before that `0`, which can be accumulated as we scan through the string.

---

# Approach

1. Initialize two counters:
   - `b` to count how many `1`s have been encountered so far.
   - `c` to accumulate the total number of swaps needed.
   
2. Traverse through the binary string:
   - If the current character is a `0`, add the current value of `b` (which represents the number of `1`s before this `0`) to the result `c`.
   - If the current character is a `1`, increment `b` to track the number of `1`s.

3. At the end of the traversal, the value of `c` will represent the minimum number of swaps required to move all `0`s before all `1`s.

---

# Complexity

- **Time complexity:**  
  The time complexity is $$O(n)$$, where `n` is the length of the binary string `s`. We make a single pass through the string.

- **Space complexity:**  
  The space complexity is $$O(1)$$, as we are only using a constant amount of extra space for the counters `c` and `b`.

---

# Code
```c
#include <stdio.h>
```
```c
long long minimumSteps(char* s) {
    long long c = 0, b = 0;
    for (register int i = 0; s[i] != '\0'; i++)
        if (s[i] == '0')
            c += b;
        else
            b++;
    return c;
}
```
```c
int main() {
    char s[] = "01101001";
    long long result = minimumSteps(s);
    printf("Minimum steps: %lld\n", result);
    return 0;
}
/*	Author   : Pankaj Mondal
	Date     : Monday, October 15, 2024, 9:28 PM
	LinkedIn : https://www.linkedin.com/in/buroush
	GitHub   : https://github.com/Buroush
	LeetCode : https://leetcode.com/Buroush        		*/

```
> "একমাত্র সমাধান যা সর্বদা মূল্যবান তা হল সেই সমাধান যা মানুষ নিজেরাই খুঁজে পায়।" ~ সত্যজিৎ রায়

> "The only solutions that are ever worth anything are the solutions that people find themselves." ~ Satyajit Ray
