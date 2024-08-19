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
