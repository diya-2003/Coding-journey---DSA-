## Intuition
The problem requires merging two strings, `word1` and `word2`, alternately character by character. If one string is longer, the remaining characters of the longer string should be appended at the end of the merged string.

## Approach
1. Calculate the lengths of both `word1` and `word2`.
2. Allocate enough memory to store the resulting merged string. The length of the merged string will be the sum of the lengths of `word1` and `word2`, plus one additional character for the null terminator.
3. Use a loop to alternately append characters from both strings to the result until one of the strings is exhausted.
4. Append the remaining characters from the longer string.
5. Add a null terminator at the end of the merged string.

## Complexity
- **Time complexity:** \(O(n + m)\), where \(n\) is the length of `word1` and \(m\) is the length of `word2`. This is because we iterate through each character of both strings exactly once.
- **Space complexity:** \(O(n + m)\) for the output string that combines the characters of `word1` and `word2`.

# Code
```
#include<stdio.h>
#include<string.h>
char * mergeAlternately(char * word1, char * word2)
{
    int l1=strlen(word1),l2=strlen(word2),l3=l1+l2,i=0,j=0,m=0;
    char *output = (char *)malloc((l3 + 1) * sizeof(char));
    if (output == NULL)
    {
        return NULL; 
    }
    while(i<l1 && j<l2)
        {
            output[m]=word1[i];
            m++;
            i++;
            output[m]=word2[j];
            m++;
            j++;
        }
    while(i<l1)
    {
        output[m]=word1[i];
        m++;
        i++;
    }
    while(j<l2)
    {
        output[m]=word2[j];
        m++;
        j++;
    }
    output[m]='\0';
    return output;
}
```