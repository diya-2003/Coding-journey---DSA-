## Intuition
Merge Sort is a divide-and-conquer algorithm that works by recursively dividing the array into smaller subarrays, sorting those subarrays, and then merging them back together. This method ensures that each element is compared and moved at most \( \log n \) times, making it an efficient sorting algorithm.

## Approach
1. **Divide**: Recursively split the array into two halves until each subarray contains a single element.
2. **Conquer**: Merge the sorted subarrays back together to form a sorted array.
3. **Merge**: The merging process involves comparing elements from each subarray and combining them in a sorted manner.

## Complexity
- **Time Complexity**: 
  - The time complexity of Merge Sort is \( O(n \log n) \) in all cases (best, average, and worst).
  - This is because the array is divided into two halves at each step, and merging the two halves takes linear time.
- **Space Complexity**:
  - The space complexity of Merge Sort is \( O(n) \) because it requires additional space for the temporary arrays used in the merging process.

## Code
```/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void concure(int *heights,int mid,int l,int r)
{
    int *a=(int*)malloc((r - l + 1) * sizeof(int));
    int i=l,j=mid+1;
    int m=0;
    while(i<=mid && j<=r)
    {
        if(heights[i]<=heights[j])
        {
            a[m++]=heights[i++];
        }
        else
        {
            a[m++]=heights[j++];
        }
    }
    while(i<=mid)
    {
        a[m++]=heights[i++];
    }
    while(j<=r)
    {
        a[m++]=heights[j++];
    }
    for (int k = l; k <= r; k++) 
    {
        heights[k] = a[k - l];
    }
}
void devide(int *heights,int l,int r)
{
    if (l >= r)
    return;
    int mid=(l+r)/2;
    devide(heights,l,mid);
    devide(heights,mid+1,r);
    concure(heights,mid,l,r);
}
int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int i=0;
    devide(nums,i,numsSize-1);
    return nums;
}
```