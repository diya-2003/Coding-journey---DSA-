## Intuition
When solving this problem, the first idea is to iterate through the string starting from the end and move backward to find the last word. A word is defined as a maximal substring consisting of non-space characters only.

## Approach
1. Start from the end of the string and move backwards.
2. Skip any trailing spaces at the end of the string.
3. Count the characters of the last word until a space or the start of the string is encountered.
4. Return the length of the last word.

## Complexity
- **Time complexity**: \( O(n) \), where \( n \) is the length of the input string. This is because we may need to scan through the entire string.
- **Space complexity**: \( O(1) \). We only use a constant amount of extra space for the counter and the iterator.

## Code
```
int lengthOfLastWord(char* s) {
int i=strlen(s)-1,c=0;
while(i >= 0 && s[i] == ' ') 
{
    i--;
}
while(i>=0 && s[i]!=' ')
{
    c++;
    i--;
}
return c;
}

```