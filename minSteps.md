### Intuition
When faced with a problem where you need to construct a sequence using minimal operations, think about how to decompose the problem into smaller, manageable pieces. The key insight here is to understand that building up the sequence by multiplying factors (through copy and paste operations) is more efficient than adding one character at a time.

### Approach
1. **Factorization**: The number of operations needed to get exactly `n` 'A's is determined by breaking down `n` into its prime factors. Each factor represents a step in which you could copy a substring of 'A's and paste it multiple times.
2. **Iterative Process**: Start by checking the smallest possible factor (starting from 2) and divide `n` by this factor repeatedly. Each division corresponds to a copy-paste operation sequence. Sum up these factors to get the minimum number of operations required.

### Complexity
- **Time Complexity**: The time complexity of this approach is \(O(\sqrt{n})\). This is because you only need to check factors up to \(\sqrt{n}\) for prime factorization.
- **Space Complexity**: The space complexity is \(O(1)\) since the solution only requires a constant amount of extra space regardless of the input size.

### Code

```c
int minSteps(int n) {
    int result = 0;
    
    // Start dividing n by its smallest possible factor starting from 2
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {  // While i is a factor of n
            result += i;      // Add the factor to the result
            n /= i;           // Reduce n
        }
    }
    
    return result;
}
```
