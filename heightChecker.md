### Approach

1. **Frequency Array**:
    - Create a frequency array to count the number of students for each possible height (assuming heights range from 1 to 100).
    - Iterate through the input `heights` array and populate the frequency array.

2. **Count Mismatches**:
    - Use the frequency array to reconstruct the sorted version of the heights.
    - Compare each element in the original `heights` array with the reconstructed sorted array.
    - Count how many positions differ between the original array and the sorted version.

### Complexity

- **Time Complexity**: The time complexity is \(O(n + k)\), where \(n\) is the number of students and \(k\) is the range of possible heights (in this case, \(k\) is 100). This is efficient since the operations on the frequency array are \(O(k)\) and iterating through the input array is \(O(n)\).
- **Space Complexity**: The space complexity is \(O(k)\) due to the frequency array, which is constant space relative to the problem's constraints.

### Code

```c
int heightChecker(int* heights, int n) {
    int freq[101] = {0};
    int count = 0;
    int i, index = 0, j;
    
    // Fill the frequency array with counts of each height
    for (i = 0; i < n; ++i) {
        freq[heights[i]]++;
    }
    
    // Compare the original heights with the sorted order
    for (i = 1; i <= 100; ++i) {
        for (j = 0; j < freq[i]; ++j) {
            if (heights[index] != i) {
                ++count;
            }
            ++index;
        }
    }
    
    return count;
}
```

### Explanation

- **Frequency Array**: We initialize a frequency array `freq` of size 101 (to cover heights from 0 to 100) with zeros. We then iterate over the input array `heights`, incrementing the count for each height.
- **Reconstruction and Comparison**: We iterate through each possible height from 1 to 100. For each height, we check how many times it appears (using the frequency array). For each occurrence, we compare the current position in the original array with the expected height. If they do not match, we increment the count of mismatches.
- **Return Result**: Finally, we return the total count of mismatches.

This approach ensures that we efficiently determine the number of students who are not in their correct positions if the array were sorted.
