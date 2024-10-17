# Intuition
The main idea is that we can increase the value of the number by swapping its digits. We should aim to maximize the leftmost digits first, as they have the most influence on the value of the number. By swapping a smaller digit with a larger digit that occurs later in the number, we can achieve the largest possible number in a single swap.

# Approach
1. **Convert the number to a string**: Since we need to manipulate individual digits, it’s convenient to treat the number as a character array. 
   
2. **Track the last occurrence of each digit**: We create an array `last[]` where each index represents a digit (0-9). The value at each index is the last occurrence of that digit in the number. This helps us quickly determine where a larger digit can be swapped in.

3. **Traverse the number**: We go through each digit in the number from left to right. For each digit, we check if there is a larger digit (9 down to the current digit) that occurs later in the number (i.e., has a greater index).

4. **Swap the digits**: If such a larger digit is found, we swap it with the current digit. After the swap, we immediately convert the string back to an integer and return the result.

5. **Return the original number**: If no beneficial swap is found after traversing all digits, we simply return the original number.

# Complexity

- **Time Complexity**: 
  - Converting the number to a string takes \( O(n) \), where \( n \) is the number of digits in the number.
  - We iterate over each digit in the number, and for each digit, we check for a larger digit in the `last[]` array. In the worst case, this takes \( O(n) \) iterations for each digit, so the overall time complexity is \( O(n) \).

- **Space Complexity**: 
  - We use an array `last[]` of size 10 to store the last occurrence of each digit. The character array `numStr[]` also uses \( O(n) \) space. Thus, the overall space complexity is \( O(n) \).

# Code
```c
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;}
int maximumSwap(int num) {
    char numStr[11];
    sprintf(numStr, "%d", num);
    int n = strlen(numStr);
    int i, last[10];
    for (i = 0; i < 10; i++) 
        last[i] = -1;
    for (i = 0; i < n; i++) 
        last[numStr[i] - '0'] = i;
    for (i = 0; i < n; i++)
        for ( d = 9; d > numStr[i] - '0'; d--)
            if (last[d] > i) {
                swap(&numStr[i], &numStr[last[d]]);
                int swappedNum;
                sscanf(numStr, "%d", &swappedNum);
                return swappedNum;
            }
    return num;
}
/*      Author   : Pankaj Mondal
        Date     : Thursday, October 17, 2024, 9:52 PM
        LinkedIn : https://www.linkedin.com/in/buroush
        GitHub   : https://github.com/Buroush
        LeetCode : https://leetcode.com/Buroush                 */

```

> The society that does not respect women can never progress. ~ Ishwar Chandra Vidyasagar
