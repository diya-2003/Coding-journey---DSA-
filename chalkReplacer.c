int chalkReplacer(int* chalk, int chalkSize, int k) {
    // Calculate the total chalk used in one full cycle
    long long total_chalk = 0;
    for (int i = 0; i < chalkSize; i++) {
        total_chalk += chalk[i];
    }
    
    // Reduce k using the modulus operation
    k = k % total_chalk;
    
    // Find the student who will run out of chalk
    for (int i = 0; i < chalkSize; i++) {
        if (k < chalk[i]) {
            return i;
        }
        k -= chalk[i];
    }
    
    return -1; // This line should never be reached
}
