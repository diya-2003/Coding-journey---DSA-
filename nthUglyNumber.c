int min(int a, int b, int c) {
    if (a < b) {
        return (a < c) ? a : c;
    } else {
        return (b < c) ? b : c;    }}
int nthUglyNumber(int n) {
    int ugly[n];
    ugly[0] = 1;    
    int i2 = 0, i3 = 0, i5 = 0, next_multiple_of_2 = 2, next_multiple_of_3 = 3, next_multiple_of_5 = 5, next_ugly_number = 1, i;
    for ( i = 1; i < n; i++) {
        next_ugly_number = min(next_multiple_of_2, next_multiple_of_3, next_multiple_of_5);
        ugly[i] = next_ugly_number;
        if (next_ugly_number == next_multiple_of_2) {
            i2++;
            next_multiple_of_2 = ugly[i2] * 2;        }
        if (next_ugly_number == next_multiple_of_3) {
            i3++;
            next_multiple_of_3 = ugly[i3] * 3;        }
        if (next_ugly_number == next_multiple_of_5) {
            i5++;
            next_multiple_of_5 = ugly[i5] * 5;        }    }
    return next_ugly_number;}
