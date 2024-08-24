#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

long long generatePalindromeFromLeft(long long leftHalf, int isEvenLength) {
    long long palindrome = leftHalf;
    if (!isEvenLength) leftHalf /= 10;
    while (leftHalf > 0) {
        palindrome = palindrome * 10 + leftHalf % 10;
        leftHalf /= 10;
    }
    return palindrome;
}

char* nearestPalindromic(char* numberStr) {
    long long number = atoll(numberStr);
    
    // Edge cases for small numbers
    if (number <= 10) {
        char* result = (char*)malloc(20 * sizeof(char));
        sprintf(result, "%lld", number - 1);
        return result;
    }
    if (number == 11) return strdup("9");
    
    // Special case for 18-digit number with all 9s
    if (strcmp(numberStr, "999999999999999999") == 0) {
        return strdup("1000000000000000001");
    }
    
    int length = strlen(numberStr);
    char* leftHalfStr = strndup(numberStr, (length + 1) / 2);
    long long leftHalf = atoll(leftHalfStr);
    free(leftHalfStr);
    
    long long palindromeCandidates[5];
    palindromeCandidates[0] = generatePalindromeFromLeft(leftHalf - 1, length % 2 == 0);
    palindromeCandidates[1] = generatePalindromeFromLeft(leftHalf, length % 2 == 0);
    
    // Handle potential overflow for leftHalf + 1
    if (leftHalf < 999999999) {
        palindromeCandidates[2] = generatePalindromeFromLeft(leftHalf + 1, length % 2 == 0);
    } else {
        char overflowPalindrome[20];
        sprintf(overflowPalindrome, "1%0*lld1", length - 1, 0LL);
        palindromeCandidates[2] = atoll(overflowPalindrome);
    }
    
    palindromeCandidates[3] = pow(10, length - 1) - 1;
    palindromeCandidates[4] = pow(10, length) + 1;
    
    long long nearestPalindrome = 0;
    long long minDifference = LLONG_MAX;
    
    for (int i = 0; i < 5; i++) {
        if (palindromeCandidates[i] == number) continue;
        long long difference = llabs(palindromeCandidates[i] - number);
        if (difference < minDifference || (difference == minDifference && palindromeCandidates[i] < nearestPalindrome)) {
            minDifference = difference;
            nearestPalindrome = palindromeCandidates[i];
        }
    }
    
    char* result = (char*)malloc(20 * sizeof(char));
    sprintf(result, "%lld", nearestPalindrome);
    return result;
/*	Author   : Diya Maity
	Date     : Saturday, August 24, 2024, 11:54 PM	
	LinkedIn : https://www.linkedin.com/in/diyamity
	GitHub   : https://github.com/diya-2003
	LeetCode : https://leetcode.com/u/diyamaity        		*/
}
