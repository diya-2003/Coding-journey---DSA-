 ### Intuition
The problem involves performing arithmetic operations on fractions that are represented as strings. Each fraction is given in the form of `numerator/denominator`, and the goal is to compute the result of the addition or subtraction of these fractions. My first thought was to parse the fractions, compute a common denominator, and then combine the numerators accordingly.

### Approach
1. **Parse the Input**: Traverse the string to extract numerators and denominators for each fraction.
2. **Compute the Result**: Initialize the numerator as 0 and the denominator as 1. For each fraction, update the running numerator and denominator by adding the current fraction to the running total.
3. **Reduce the Fraction**: After processing all the fractions, compute the greatest common divisor (GCD) of the numerator and denominator to reduce the fraction to its simplest form.
4. **Return the Result**: Format the final numerator and denominator as a string in the format `"numerator/denominator"`.

### Complexity
- **Time Complexity**: The time complexity is $$O(n)$$, where \(n\) is the length of the input string. This is because we are parsing the string and processing each character linearly.
- **Space Complexity**: The space complexity is $$O(1)$$, as we are using a fixed amount of extra space for variables, excluding the space required for the input and output.

### Code
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int gcd(int a, int b) {
    return b == 0 ? abs(a) : gcd(b, a % b);
}

char* fractionAddition(char* expression) {
    int numerator = 0;
    int denominator = 1;

    // Parsing the expression
    int num, den;
    int sign = 1;
    char *ptr = expression;

    while (*ptr) {
        if (*ptr == '-' || *ptr == '+') {
            if (*ptr == '-') sign = -1;
            else sign = 1;
            ptr++;
        }

        // Extracting the numerator
        num = 0;
        while (isdigit(*ptr)) {
            num = num * 10 + (*ptr - '0');
            ptr++;
        }
        num *= sign;

        // Skipping the '/'
        ptr++;

        // Extracting the denominator
        den = 0;
        while (isdigit(*ptr)) {
            den = den * 10 + (*ptr - '0');
            ptr++;
        }

        // Updating the numerator and denominator
        numerator = numerator * den + num * denominator;
        denominator *= den;

        // Calculate GCD to reduce the fraction
        int common_divisor = gcd(numerator, denominator);
        numerator /= common_divisor;
        denominator /= common_divisor;
    }

    // Formatting the result as a string
    char* result = (char*)malloc(20 * sizeof(char)); // Enough space for the result
    snprintf(result, 20, "%d/%d", numerator, denominator);
    
    return result;
}

int main() {
    char expression[] = "-1/2+1/2";
    char* result = fractionAddition(expression);
    printf("%s\n", result);
    free(result);  // Remember to free the allocated memory

    return 0;
}
/*	Author   : Diya Maity
	Date     : Friday, August 23, 2024, 11:25 PM	
	LinkedIn : https://www.linkedin.com/in/diyamity
	GitHub   : https://github.com/diya-2003
	LeetCode : https://leetcode.com/u/diyamaity        		*/
```
