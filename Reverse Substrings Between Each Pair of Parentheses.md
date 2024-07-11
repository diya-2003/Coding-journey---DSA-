## Intuition

The problem involves reversing substrings enclosed by parentheses. The approach to solve this problem involves two main tasks:
1. **Identifying substrings enclosed by parentheses** and keeping track of their positions.
2. **Reversing the identified substrings** and constructing the final string with the reversed substrings while removing the parentheses.

## Approach

1. **Use a Stack to Track Parentheses:** As we traverse the string, use a stack to keep track of the indices of the opening parentheses `'('`. When encountering a closing parenthesis `')'`, pop the index from the stack to get the position of the corresponding opening parenthesis.
2. **Reverse the Substring:** For each pair of parentheses, reverse the substring enclosed by them.
3. **Construct the Result String:** After processing all parentheses, remove the parentheses and create the resulting string with the reversed substrings.

## Complexity

- **Time Complexity:** \(O(n)\), where \(n\) is the length of the string. Each character is processed a constant number of times (push and pop operations are \(O(1)\), and reversing substrings takes linear time in the worst case).
- **Space Complexity:** \(O(n)\), primarily due to the space used by the stack and the result string.

## Code
```
void reverseSubstring(char* str, int start, int end) 
{
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
char* reverseParentheses(char* s) 
{
    int n = strlen(s);
    int* pos = (int*)malloc(n * sizeof(int));
    int top = -1; 
    for (int i = 0; i < n; i++) 
    {
        if (s[i] == '(') 
        {
            pos[++top] = i;
        } 
        else if (s[i] == ')') 
        {
            int start = pos[top--];
            reverseSubstring(s, start + 1, i - 1);
        }
    }
    char* result = (char*)malloc((n + 1) * sizeof(char));
    int j = 0;
    for (int i = 0; i < n; i++) 
    {
        if (s[i] != '(' && s[i] != ')') 
        {
            result[j++] = s[i];
        }
    }
    result[j] = '\0';
    free(pos);
    return result;
}
```