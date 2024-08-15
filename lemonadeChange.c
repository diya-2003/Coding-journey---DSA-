bool lemonadeChange(int* bills, int billsSize) {
    int count5 = 0, count10 = 0, i;
    for ( i = 0; i < billsSize; i++) {
        if (bills[i] == 5) {
            count5++;
        } else if (bills[i] == 10) {
            if (count5 > 0) {
                count5--;
                count10++;
            } else {
                return false; // Cannot provide change
            }
        } else { // $20 bill
            if (count10 > 0 && count5 > 0) {
                count10--;
                count5--;
            } else if (count5 >= 3) {
                count5 -= 3;
            } else {
                return false; // Cannot provide change
            }
        }
    }

    return true; // All customers served with correct change
}
