### Intuition
When dealing with a sequence of customers in the lemonade stand problem, our primary concern is ensuring we have the correct change for each customer. The challenge lies in managing the available $5 and $10 bills effectively, as every $20 bill requires a combination of these to provide change.

### Approach
We iterate through each customer's bill in the array. If the customer pays with a $5 bill, we simply increase our count of $5 bills. For a $10 bill, we check if we have a $5 bill to provide as change, decreasing the respective counts accordingly. For a $20 bill, the optimal approach is to give back one $10 bill and one $5 bill if available. If that’s not possible, we attempt to provide three $5 bills as change. If neither option is available at any point, we return `false`, indicating we cannot provide the correct change.

### Complexity
- **Time complexity:** The algorithm runs in linear time, so the time complexity is $$O(n)$$, where `n` is the number of bills.
  
- **Space complexity:** The space complexity is $$O(1)$$ since we are only using a fixed amount of extra space (for counters).

### Code
```c
#include <stdio.h>

bool lemonadeChange(int* bills, int billsSize) {
    int count5 = 0; // Number of $5 bills
    int count10 = 0; // Number of $10 bills

    for (int i = 0; i < billsSize; i++) {
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
```
