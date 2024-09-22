int findKthNumber(int n, int k) {

    int countSteps(long long n, long long prefix) {

        long long min(long long a, long long b) {
            return (a < b) ? a : b;
        }

        long long current = prefix, next = prefix + 1;
        int steps = 0;
        while (current <= n) {
            steps += min(n + 1, next) - current;
            current *= 10;
            next *= 10;
        }
        return steps;
    }
    int curr = 1, steps;
    k -= 1;
    
    while (k > 0) {
        steps = countSteps(n, curr);
        if (steps <= k) {
            k -= steps;
            curr += 1;
        } else {
            curr *= 10;
            k -= 1;
        }
    }
    
    return curr;
}
