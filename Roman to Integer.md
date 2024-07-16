# Intuition
The goal is to convert a Roman numeral string into an integer. Roman numerals are usually written from largest to smallest from left to right. However, if a smaller numeral appears before a larger numeral, it should be subtracted rather than added.

# Approach
1. **Create a helper function**: `basicvalue(char i)` that returns the integer value of a Roman numeral character.
2. **Initialize two variables**: `c` for the current numeral value and `t` for the total sum.
3. **Iterate through the string**: Starting from the end of the string, for each character:
   - Get its integer value using `basicvalue`.
   - If the current numeral value (`temp`) is greater than or equal to `c`, add it to `t`.
   - Otherwise, subtract it from `t`.
   - Update `c` to the current numeral value.

# Complexity
- **Time complexity**: \( O(n) \), where \( n \) is the length of the string. This is because we process each character of the string exactly once.
- **Space complexity**: \( O(1) \). We use a fixed amount of extra space regardless of the input size.

# Code
```
int basicvalue(char i)
{
    switch(i)
    {
        case 'I': 
            return 1;
        case 'V': 
            return 5;
        case 'X': 
            return 10;
        case 'L': 
            return 50;
        case 'C': 
            return 100;
        case 'D': 
            return 500;
        case 'M': 
            return 1000;
        default: 
            return 0;

    }
}
int romanToInt(char* s) 
{
    int c=0,t=0;
    for(int i=strlen(s)-1;i>=0;i--)
    {
        int temp=basicvalue(s[i]);
        if(temp>=c)
        {
            t+=temp;
            c=temp;
        }
        else
        {
            t-=temp;
            c=temp;
        }
    }
    return t;
}
```