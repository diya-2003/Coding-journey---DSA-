int gcd(int a, int b) {
    return b == 0 ? abs(a) : gcd(b, a % b);}
char* fractionAddition(char* expression) {
    int numerator = 0;
    int denominator = 1;
    int num, den;
    int sign = 1;
    char *ptr = expression;
    while (*ptr) {
        if (*ptr == '-' || *ptr == '+') {
            if (*ptr == '-') sign = -1;
            else sign = 1;
            ptr++;
        }
        num = 0;
        while (isdigit(*ptr)) {
            num = num * 10 + (*ptr - '0');
            ptr++;        }
        num *= sign;
        ptr++;
        den = 0;
        while (isdigit(*ptr)) {
            den = den * 10 + (*ptr - '0');
            ptr++;        }
        numerator = numerator * den + num * denominator;
        denominator *= den;
        int common_divisor = gcd(numerator, denominator);
        numerator /= common_divisor;
        denominator /= common_divisor;    }
    char* result = (char*)malloc(20 * sizeof(char));
    snprintf(result, 20, "%d/%d", numerator, denominator);    
    return result;}
