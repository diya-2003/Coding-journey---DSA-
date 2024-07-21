# Intuition
The problem requires us to keep track of scores based on a series of operations, and our goal is to calculate the total score at the end. The operations include:
- Adding a new score.
- Doubling the last score.
- Summing the last two scores.
- Removing the last score.

We can use an array to simulate the score records and handle each operation accordingly.

# Approach
1. Initialize an array `record` to store the scores and a variable `recordSize` to track the number of scores.
2. Iterate through each operation in the input array:
    - If the operation is "C", remove the last score by decrementing `recordSize`.
    - If the operation is "D", double the last score and add it to `record`.
    - If the operation is "+", sum the last two scores and add it to `record`.
    - Otherwise, convert the operation to an integer and add it to `record`.
3. After processing all operations, sum up all the scores in `record` and return the total.

# Complexity
- Time complexity: \(O(n)\), where \(n\) is the number of operations. We process each operation once and then sum the scores.
- Space complexity: \(O(n)\), for storing the scores in the `record` array.

# Code
```
int calPoints(char **operations, int opsSize) {
    int record[1000];
    int recordSize = 0;
    int sum = 0;
    for (int i = 0; i < opsSize; i++) 
    {
        if (operations[i][0] == 'C') 
        {
            if (recordSize > 0) 
            {
                recordSize--;
            }
        } 
        else if (operations[i][0] == 'D') 
        {
            if (recordSize > 0) 
            {
                record[recordSize] = 2 * record[recordSize - 1];
                recordSize++;
            }
        } 
        else if (operations[i][0] == '+') 
        {
            if (recordSize >= 2)
            {
                record[recordSize] = record[recordSize - 1] + record[recordSize - 2];
                recordSize++;
            }
        } 
        else 
        {
            record[recordSize] = atoi(operations[i]);
            recordSize++;
        }
    }
    for (int i = 0; i < recordSize; i++) 
    {
        sum += record[i];
    }
    return sum;
}    
```