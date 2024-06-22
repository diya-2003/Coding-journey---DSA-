# Intuition
To solve this problem, we can use a sliding window approach. We maintain a count of the odd numbers encountered so far while iterating through the array. Whenever the count of odd numbers reaches or exceeds `k`, we can compute the number of subarrays with exactly `k` odd numbers by using the count of subarrays ending at the current index and the count of subarrays ending at an index `k` positions back.

# Approach
1. Initialize an array `arr` to store the count of subarrays with a specific count of odd numbers encountered so far.
2. Initialize variables `c` to keep track of the count of odd numbers encountered and `count` to store the total count of subarrays with exactly `k` odd numbers.
3. Iterate through the array and update `c` and `count` accordingly.
4. Return the final count.

# Complexity
- Time complexity: $$O(n)$$, where $$n$$ is the size of the input array. We iterate through the array once.
- Space complexity: $$O(n)$$, as we use an additional array of size `numsSize+1` to store the count of subarrays.

# Code
```
int numberOfSubarrays(int* nums, int numsSize, int k)
{
    int* arr=(int*)calloc(numsSize+1,sizeof(int));
    int c=0, count=0;
    arr[0]=1;
    for(int i=0;i<numsSize;i++) 
    {
        if(nums[i]%2!=0) 
        {
            c++;
        }
        if(c>=k) 
        {
            count+=arr[c-k];
        }
        arr[c]++;
    }
    free(arr);
    return count; 
}
```