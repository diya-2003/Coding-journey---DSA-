#include <stdlib.h>
#include <string.h>

char* stringHash(char* s, int k) {
    int n = strlen(s);
    int result_len = n / k;
    
    // Allocate memory for the result string
    char* result = (char*)malloc((result_len + 1) * sizeof(char));
    
    for (int i = 0; i < result_len; i++) {
        int sum = 0;
        
        // Calculate the sum of hash values for the current substring
        for (int j = 0; j < k; j++) {
            sum += s[i * k + j] - 'a';
        }
        
        // Calculate the hashed character and append to result
        int hashedChar = sum % 26;
        result[i] = 'a' + hashedChar;
    }
    
    // Null-terminate the result string
    result[result_len] = '\0';
    
    return result;
}
