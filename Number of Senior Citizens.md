### Intuition
To solve this problem, you want to count the number of seniors in a list of details, where a senior is defined as someone aged above 60. You assume that the age information is stored in a specific part of each string in the list.

### Approach
1. Iterate through the list of details.
2. For each entry, extract the age from the 12th and 13th characters (0-indexed) of the string.
3. Convert these characters to an integer to get the age.
4. Check if the age is greater than 60. If it is, increment the count.

### Complexity
- **Time complexity:** \(O(n)\), where \(n\) is the number of entries in the list `details`. This is because you are iterating through each entry once.
- **Space complexity:** \(O(1)\), since you are using a constant amount of extra space regardless of the input size.

### Code
```
int countSeniors(char ** details, int detailsSize){
    int count=0;
    for(int i=0;i<detailsSize;i++){
        int age=(details[i][11] - '0')*10+(details[i][12]-'0');
        if(age>60)
        {
            count++;
        }
    }
    return count;
}
```