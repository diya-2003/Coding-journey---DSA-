int countKConstraintSubstrings(char* s, int k) {
    int n = strlen(s);
    int count = 0;

    for (int i = 0; i < n; i++) {
        int zeros = 0, ones = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == '0') {
                zeros++;
            } else {
                ones++;
            }
            
            // Check the k-constraint
            if (zeros <= k || ones <= k) {
                count++;
            } else {
                break;  // No need to check further as subsequent substrings will not satisfy the k-constraint
            }
        }
    }

    return count;
}
