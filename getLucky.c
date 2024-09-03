int getLucky(char* s, int k) {
    int i, sum = 0, n, m, value;
    for (i = 0; s[i] != '\0'; i++) {
        value = (s[i] - 'a' + 1);
        while (value > 0) {
            sum += value % 10, value /= 10;}}
    while (--k) {
        n = sum, sum = 0;
        while (n > 0) {
            m = n % 10, sum += m, n /= 10;}}
    return sum;}
