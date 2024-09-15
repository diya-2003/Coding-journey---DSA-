#include <stdio.h>
#include <string.h>

int findTheLongestSubstring(char* s) {
    // To store the vowel characters 'a', 'e', 'i', 'o', 'u'
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    
    // Map to store the first occurrence of each bitmask
    int seen[32]; // 32 possible bitmasks for 5 vowels (2^5 = 32)
    memset(seen, -1, sizeof(seen));
    
    int bitmask = 0; // Current bitmask
    seen[0] = 0;     // The empty substring has an "even" bitmask (00000)
    
    int max_len = 0; // To store the maximum length
    int n = strlen(s); // Length of the input string
    
    for (int i = 0; i < n; ++i) {
        // Update the bitmask based on the current character
        if (s[i] == 'a') {
            bitmask ^= 1 << 0; // Toggle the 0th bit (for 'a')
        } else if (s[i] == 'e') {
            bitmask ^= 1 << 1; // Toggle the 1st bit (for 'e')
        } else if (s[i] == 'i') {
            bitmask ^= 1 << 2; // Toggle the 2nd bit (for 'i')
        } else if (s[i] == 'o') {
            bitmask ^= 1 << 3; // Toggle the 3rd bit (for 'o')
        } else if (s[i] == 'u') {
            bitmask ^= 1 << 4; // Toggle the 4th bit (for 'u')
        }
        
        // If the bitmask has been seen before, calculate the length of the substring
        if (seen[bitmask] != -1) {
            int current_len = i + 1 - seen[bitmask];
            if (current_len > max_len) {
                max_len = current_len;
            }
        } else {
            // Otherwise, store the first occurrence of this bitmask
            seen[bitmask] = i + 1;
        }
    }
    
    return max_len;
}

int main() {
    char s[] = "eleetminicoworoep";
    int result = findTheLongestSubstring(s);
    printf("The longest substring length is: %d\n", result); // Expected output: 13
    return 0;
}
