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
