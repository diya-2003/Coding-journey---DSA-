### Intuition
The problem involves finding the complement of an integer. The complement is derived by flipping all the bits of the binary representation of the integer. The basic idea is to create a mask of the same length as the number's binary representation, where all bits are set to 1. XORing the original number with this mask will flip its bits, yielding the complement.

### Approach
1. **Create a Mask**: First, generate a mask that has all bits set to 1. The length of this mask should match the number of bits in the binary representation of the input number.
2. **XOR Operation**: XOR the original number with this mask. XORing a bit with 1 flips it (0 becomes 1, and 1 becomes 0), which gives the complement of the number.

### Complexity
- **Time Complexity**: 
  - The time complexity is \(O(\log n)\) because the while loop runs for a number of iterations proportional to the number of bits in the binary representation of `num`, which is logarithmic with respect to `num`.
  
- **Space Complexity**:
  - The space complexity is \(O(1)\) as the algorithm uses a constant amount of space regardless of the input size.

### Code
```c
int findComplement(int num) {
    // Step 1: Create a mask with all bits set to 1 of the same length as the number
    int mask = 0, temp = num;
    while (temp != 0) {
        mask = (mask << 1) | 1;
        temp = temp >> 1;
    }
    
    // Step 2: XOR the number with the mask to get the complement
    return num ^ mask;
}
```
