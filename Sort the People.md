## Intuition
To solve this problem, the goal is to sort people based on their heights in descending order. This will involve rearranging both the names and heights arrays simultaneously to ensure that each person's height corresponds to their name correctly.

## Approach
1. Verify that the lengths of the names and heights arrays are the same. If not, return an empty array and set `returnSize` to 0.
2. Implement a selection sort algorithm to sort the heights array in descending order. During this process, swap the corresponding names to maintain the correct association.
3. Return the sorted names array and set `returnSize` to the length of the names array.

## Complexity
- **Time complexity:** 
  - The selection sort algorithm has a time complexity of \(O(n^2)\), where \(n\) is the size of the array.
- **Space complexity:**
  - The space complexity is \(O(1)\) since the sorting is done in place and no additional space is used except for a few temporary variables.

## Code
```
void swapi(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swaps(char** a, char** b) 
{
    char* temp = *a;
    *a = *b;
    *b = temp;
}
char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) 
{
    if (namesSize != heightsSize) 
    {
        *returnSize = 0;
        return NULL;
    }
    for (int i = 0; i < namesSize - 1; i++) 
    {
        int maxIdx = i;
        for (int j = i + 1; j < namesSize; j++) 
        {
            if (heights[j] > heights[maxIdx]) 
            {
                maxIdx = j;
            }
        }
        swapi(&heights[i], &heights[maxIdx]);
        swaps(&names[i], &names[maxIdx]);
    }

    *returnSize = namesSize;
    return names;
}  
```
