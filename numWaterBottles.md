### Intuition

The function employs a greedy approach where empty bottles are continuously exchanged for new bottles until there are not enough empty bottles left for an exchange.

### Approach

1. **Initialization**: Start with `totalBottles` set to the initial number of `numBottles`.
   
2. **Exchange Loop**: Utilize a while loop to keep exchanging bottles as long as `numBottles` (current bottles) is greater than or equal to `numExchange` (the number of empty bottles required for an exchange).
   
3. **Update Logic**: Inside the loop, update `totalBottles` by adding the number of new bottles obtained from the exchange (`numBottles / numExchange`). Then, update `numBottles` for the next iteration to reflect both the new bottles obtained (`numBottles / numExchange`) and any remaining bottles after the exchange (`numBottles % numExchange`).

### Complexity

- **Time Complexity**: The function runs a loop that depends on how many times you can perform the exchange, which is approximately `O(log(numBottles))` in the worst case scenario.
- **Space Complexity**: The function uses a constant amount of extra space (`O(1)`), regardless of the input size.

### Code

Here's the complete code snippet for the `numWaterBottles` function:

```cpp
int numWaterBottles(int numBottles, int numExchange) {
    int totalBottles = numBottles;
    while (numBottles >= numExchange) {
        totalBottles += numBottles / numExchange;
        numBottles = (numBottles / numExchange) + (numBottles % numExchange);
    }
    return totalBottles;
}
```
