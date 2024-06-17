# Intuition
To determine if an integer \( c \) can be expressed as the sum of two squares, we can utilize the fact that a positive integer \( c \) can be represented in such a way if and only if in its prime factorization, every prime of the form \( 4k + 3 \) appears with an even exponent.

# Approach
- Iterate through potential prime factors of \( c \) from \( 2 \) up to the square root of \( c \).
- For each prime factor \( i \), count how many times it divides \( c \).
- If \( i \) is of the form \( 4k + 3 \) and its count is odd, return `false`.
- After the loop, if \( c \) is greater than \( 1 \) and \( c \) modulo \( 4 \) is not \( 3 \), return `false`.
- Otherwise, return `true`.

# Complexity
- Time complexity: \( O(\sqrt{c} \log(\log(c))) \) due to the prime factorization.
- Space complexity: \( O(1) \) as we use only a constant amount of extra space.

# Code
```
bool judgeSquareSum(int c)
{
    for (int i=2; i*i <= c; i++) 
    {
        int count = 0;
        while (c % i == 0) 
        {
            count++;
            c /= i;
         }
        if (i % 4 == 3 && count % 2 != 0) 
        {
            return false;
        }
    }
    return c % 4 != 3;
}
```