# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The problem revolves around counting the imbalance in the number of opening and closing brackets as we traverse the string. The main challenge is to fix situations where closing brackets `]` appear before opening brackets `[`, which violates the balanced string property. We need to swap such brackets to restore balance.

# Approach
<!-- Describe your approach to solving the problem. -->
1. Initialize a `balance` variable to track the net number of opening brackets `[`. Increment it when encountering an opening bracket and decrement it when encountering a closing bracket.
2. If `balance` becomes negative at any point, it means we have encountered more closing brackets `]` than opening brackets `[`. This imbalance needs to be corrected by swapping.
3. The number of imbalances represents how many swaps we need. Each swap can fix two misplaced brackets (one opening and one closing), so the number of swaps is half the number of imbalances, rounded up.
4. Finally, return the total number of swaps required.

# Complexity
- **Time complexity:**
  $$O(n)$$  
  We only need to traverse the string once to count the imbalances, so the time complexity is linear with respect to the length of the string.

- **Space complexity:**
  $$O(1)$$  
  We use a constant amount of space for tracking the `balance`, `swaps`, and `imbalance`, regardless of the input size.

# Code
```c
int minSwaps(char* s) {
    int balance = 0, swaps = 0, imbalance = 0, n = strlen(s), i;
    for (i = 0; i < n; i++) {
        if (s[i] == '[') {
            balance++;
        } else {
            balance--;
        }
        if (balance < 0) {
            imbalance++;
            balance = 0;
        }
    }
    swaps = (imbalance + 1) / 2;
/*      Author   : Pankaj Mondal
        Date     : Tuesday, October 8, 2024, 9:32 PM
        LinkedIn : https://www.linkedin.com/in/buroush
        GitHub   : https://github.com/Buroush
        LeetCode : https://leetcode.com/Buroush                */

    return swaps;
}
```

This approach ensures that the problem is solved efficiently, and the complexity analysis demonstrates that it performs well even for larger strings.
