#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestDiverseString(int a, int b, int c) {
    // Allocate memory for the result string (maximum possible length is a + b + c + 1 for '\0')
    int totalLength = a + b + c;
    char* result = (char*)malloc((totalLength + 1) * sizeof(char));
    result[0] = '\0';
    
    // Define the count of each character and their representation
    int count[3] = {a, b, c}; // count[0] = a, count[1] = b, count[2] = c
    char chars[3] = {'a', 'b', 'c'};
    
    // Function to choose the character with the largest remaining count that can be added
    int chooseChar(int prev, int* count, char* chars) {
        for (int i = 0; i < 3; i++) {
            if (i != prev && count[i] > 0) {
                return i;
            }
        }
        return -1; // No valid character to choose
    }

    int prev = -1; // Keeps track of the previous character added to avoid "aaa", "bbb", or "ccc"
    int pos = 0;
    
    while (1) {
        // Find the character with the highest count
        int idx = -1;
        for (int i = 0; i < 3; i++) {
            if ((idx == -1 || count[i] > count[idx]) && count[i] > 0) {
                idx = i;
            }
        }
        
        // If no more characters are available, break the loop
        if (idx == -1) {
            break;
        }
        
        // Check if we can add this character
        int len = strlen(result);
        if (len >= 2 && result[len - 1] == chars[idx] && result[len - 2] == chars[idx]) {
            // We can't add this character, so choose a different one
            idx = chooseChar(prev, count, chars);
            if (idx == -1) {
                break; // No valid characters to add, so stop
            }
        }
        
        // Add the chosen character
        result[pos++] = chars[idx];
        result[pos] = '\0'; // Keep the string null-terminated
        count[idx]--;       // Decrease the count of the added character
        prev = idx;         // Update the previous character
    }

    return result;
}

int main() {
    int a = 7, b = 1, c = 0;
    char* result = longestDiverseString(a, b, c);
    printf("%s\n", result);
    free(result);
    return 0;
}
