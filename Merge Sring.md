# Intuition
The problem requires merging two strings alternately. This can be efficiently achieved by iterating through both strings simultaneously and appending characters from each string in an alternating manner.

# Approach
1. Determine the lengths of both input strings.
2. Create an output string of sufficient length to hold all characters from both input strings.
3. Use two pointers to traverse both strings simultaneously, adding characters alternately to the output string.
4. If one string is longer, append the remaining characters from the longer string to the output.
5. Ensure the output string is null-terminated.

# Complexity
- Time complexity: \(O(n + m)\), where \(n\) and \(m\) are the lengths of the two input strings. This is because each character from both strings is processed exactly once.
- Space complexity: \(O(n + m)\), as a new string is created to hold the merged result.

# Code
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * mergeAlternately(char * word1, char * word2) {
    int l1 = strlen(word1);
    int l2 = strlen(word2);
    int l3 = l1 + l2;
    int i = 0, j = 0, m = 0;
    char *output = (char *)malloc((l3 + 1) * sizeof(char));
    
    if (output == NULL) {
        return NULL; 
    }
    
    while (i < l1 && j < l2) {
        output[m++] = word1[i++];
        output[m++] = word2[j++];
    }
    
    while (i < l1) {
        output[m++] = word1[i++];
    }
    
    while (j < l2) {
        output[m++] = word2[j++];
    }
    
    output[m] = '\0';
    return output;
}
```