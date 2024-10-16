# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The problem involves generating the longest string using the letters 'a', 'b', and 'c', while avoiding three consecutive occurrences of the same letter. We should aim to maximize the length of the string by always selecting the letter with the highest available count, as this ensures the string can be as long as possible. However, we need to prevent any invalid combinations (like "aaa", "bbb", or "ccc"). Thus, a greedy approach where we pick the most frequent character but switch to others when necessary would work well.

# Approach
<!-- Describe your approach to solving the problem. -->
1. **Track Counts**: We maintain a count of how many occurrences of 'a', 'b', and 'c' are left to use.
2. **Greedy Choice**: At each step, we pick the character with the largest remaining count, as long as it doesn’t form an invalid substring (i.e., no three consecutive characters should be the same). 
3. **Switching Characters**: If adding the most frequent character would cause three consecutive characters, we switch to the next most frequent one.
4. **Terminate**: The process stops when no valid characters can be added to the string without violating the substring constraints.
5. **Helper Function**: A helper function is used to select the character when the most frequent one cannot be added due to forming an invalid substring.

# Complexity
- **Time complexity**:  
  The time complexity is $$O(a + b + c)$$. This is because we are processing each character exactly once, appending it to the result string. At each step, we are also scanning the counts to select the next valid character, but this takes constant time (since we only have 3 characters to choose from).
  
- **Space complexity**:  
  The space complexity is $$O(a + b + c)$$ as well, because we are storing the result string, which has a maximum size of `a + b + c`.

# Code
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestDiverseString(int a, int b, int c) {
    int totalLength = a + b + c;
    char* result = (char*)malloc((totalLength + 1) * sizeof(char));
    result[0] = '\0';
    int count[3] = {a, b, c};
    char chars[3] = {'a', 'b', 'c'};
    int chooseChar(int prev, int* count, char* chars) {
        for (int i = 0; i < 3; i++) {
            if (i != prev && count[i] > 0) {
                return i;
            }
        }
        return -1;
    }
    int prev = -1;
    int pos = 0;
    while (1) {
        int idx = -1;
        for (int i = 0; i < 3; i++) {
            if ((idx == -1 || count[i] > count[idx]) && count[i] > 0) {
                idx = i;
            }
        }
        if (idx == -1) {
            break;
        }
        int len = strlen(result);
        if (len >= 2 && result[len - 1] == chars[idx] && result[len - 2] == chars[idx]) {
            idx = chooseChar(prev, count, chars);
            if (idx == -1) {
                break;
            }
        }
        result[pos++] = chars[idx];
        result[pos] = '\0';
        count[idx]--;
        prev = idx;
    }

    return result;
/*      Author   : Pankaj Mondal
        Date     : Wedday, October 16, 2024, 8:15 PM
        LinkedIn : https://www.linkedin.com/in/buroush
        GitHub   : https://github.com/Buroush
        LeetCode : https://leetcode.com/Buroush                 */


}
```
> "If a person wants to become big, then he should do even the smallest work, because only self-help is the best." ~ Isar Chanda Vidyasagar
