### [Problem Explanation:](https://www.hackerrank.com/challenges/circle-city/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign)

Roy lives in a city that is circular in shape, centered at the origin (0, 0) on a coordinate plane, with a given radius \( r \). The city has suburbs located at lattice points — points where both the x and y coordinates are integers. Suburbs located strictly inside the city are protected by the Police Department Headquarters. However, suburbs located on the border of the city (the circumference) are unprotected.

The police department can build a limited number of additional police stations at the suburbs. Roy's task is to determine if it is possible to protect all the suburbs on the border by building police stations at some of the unprotected suburbs.

The city is defined by its **radius squared**, \( d \), and the police department is willing to build **up to \( k \)** police stations.

The objective is to calculate the number of suburbs that lie on the border (circumference), then check if \( k \) police stations are sufficient to protect all of these suburbs.

### Input Format:
- The first line contains the integer \( t \), the number of test cases.
- Each of the next \( t \) lines contains two integers:
  - \( d \), the square of the radius of the city.
  - \( k \), the maximum number of police stations the headquarters is willing to build.

### Output Format:
For each test case, print "possible" if it is possible to protect all suburbs on the border with \( k \) police stations, otherwise print "impossible".

### Sample Input:
```
5
1 3
1 4
4 4
25 11
25 12
```

### Sample Output:
```
impossible
possible
possible
impossible
possible
```

### Explanation:
1. **Test Case 1 (d = 1, k = 3)**:
   - Suburbs on the border: (0, 1), (0, -1), (1, 0), (-1, 0).
   - Total suburbs on the border: 4.
   - Since \( k = 3 \) is less than the required 4 police stations, the output is "impossible".

2. **Test Case 2 (d = 1, k = 4)**:
   - Same border points as above, but \( k = 4 \) matches exactly the required 4 police stations, so the output is "possible".

3. **Test Case 3 (d = 4, k = 4)**:
   - Border suburbs: (0, 2), (0, -2), (2, 0), (-2, 0).
   - Total suburbs on the border: 4.
   - \( k = 4 \) matches exactly the number of police stations needed, so the output is "possible".

4. **Test Case 4 (d = 25, k = 11)**:
   - Border suburbs: Multiple points such as (0, 5), (3, 4), (-5, 0), etc., totaling 12 border suburbs.
   - Since \( k = 11 \) is less than the required 12 police stations, the output is "impossible".

5. **Test Case 5 (d = 25, k = 12)**:
   - Same as above, but \( k = 12 \), so it is possible to cover all border suburbs with the police stations, and the output is "possible".

---

### Algorithm Explanation:

1. **Calculate radius**:  
   The square of the radius \( d \) is given, so the radius \( r \) is \( \sqrt{d} \). We calculate the integer form of the radius using `ceil(sqrt(d))`.

2. **Loop through possible x-values**:  
   For each \( x \) from 0 to \( r \), calculate the corresponding \( y \) such that \( x^2 + y^2 = d \). If \( y \) is an integer (i.e., it lies on the circumference), we count the symmetric points on the circle.

3. **Count border suburbs**:  
   For each valid \( (x, y) \) point, we count all symmetric points (x, y), (-x, y), (x, -y), (-x, -y). If \( x \) or \( y \) is 0, we count fewer points to avoid duplication.

4. **Check if \( k \) is sufficient**:  
   If the number of police stations \( k \) is greater than or equal to the number of border suburbs, print "possible", otherwise print "impossible".

---

### Code Implementation:

```c
#include <stdio.h>
#include <math.h>

char* solve(int d, int k) {
    int count = 0; // To count the points on the border
    
    // Find the integer radius value
    int r = (int)ceil(sqrt(d));

    // Loop through all x values from 0 to r
    for (int i = 0; i <= r; i++) {
        // Calculate y based on the equation x^2 + y^2 = d
        double y = sqrt(d - i * i);
        
        // Check if y is an integer
        if (y == (int)y) {
            // If both x and y are not zero, we count all 4 points: (x, y), (-x, y), (x, -y), (-x, -y)
            if (i > 0 && (int)y > 0) {
                count += 4;
            } 
            // If x or y is zero, count only two symmetric points
            else if (i == 0 || (int)y == 0) {
                count += 2;
            }
        }
    }

    // Check if the number of police stations is sufficient to cover all border points
    if (k >= count) {
        return "possible";
    } else {
        return "impossible";
    }
}

int main() {
    int t;
    scanf("%d", &t);  // Number of test cases
    while (t--) {
        int d, k;
        scanf("%d %d", &d, &k);  // Read square of radius and number of police stations
        printf("%s\n", solve(d, k));  // Output the result for each test case
    }
    return 0;
}
/*	Author   : Pankaj Mondal
    Date     : Saturday, October 12, 2024, 7:44 PM
	  LinkedIn : https://www.linkedin.com/in/buroush
	  GitHub   : https://github.com/Buroush
	  LeetCode : https://leetcode.com/Buroush        		*/
```

### Test Cases:

**Input:**
```
5
1 3
1 4
4 4
25 11
25 12
```

**Output:**
```
impossible
possible
possible
impossible
possible
```
> "A life without suffering is like a boat without a sailor; it has no discretion of its own, moving only in a light breeze." - Ishwar Chandra Vidyasagar
