# Intuition
To determine if the array can form an arithmetic progression, we need to check if the difference between consecutive elements is constant throughout the array. First, we should sort the array to ensure elements are in order. Once sorted, we can easily check the difference between consecutive elements.

# Approach
1. **Sort the Array:** Use the merge sort algorithm to sort the array.
2. **Check Differences:** After sorting, calculate the difference between the first two elements. Then, iterate through the array and check if this difference is consistent for all consecutive elements.

# Complexity
- **Time complexity:** \(O(n \log n)\)
  - Sorting the array using merge sort takes \(O(n \log n)\) time.
  - Checking the differences takes \(O(n)\) time.

- **Space complexity:** \(O(n)\)
  - Merge sort requires additional space for the temporary array used in merging.

# Code
```
void concure(int *arr, int mid, int l, int r) 
{
    int i = l, j = mid + 1;
    int *a = (int *)malloc((r - l + 1) * sizeof(int));
    int m = 0;
    while (i <= mid && j <= r) 
    {
        if (arr[i] <= arr[j]) 
        {
            a[m++] = arr[i++];
        } 
        else 
        {
            a[m++] = arr[j++];
        }
    }
    while (i <= mid) 
    {
        a[m++] = arr[i++];
    }
    while (j <= r) 
    {
        a[m++] = arr[j++];
    }
    for (int k = l; k <= r; k++) 
    {
        arr[k] = a[k - l];
    }
    free(a);
}
void divide(int *arr, int l, int r) 
{
    if (l >= r) return;
    int mid = (l + r) / 2;
    divide(arr, l, mid);
    divide(arr, mid + 1, r);
    concure(arr, mid, l, r);
}
bool canMakeArithmeticProgression(int* arr, int arrSize) 
{
    divide(arr, 0, arrSize - 1);
    int diff = arr[1] - arr[0];
    for (int i = 2; i < arrSize; i++) 
    {
        if (arr[i] - arr[i - 1] != diff) 
        {
            return false;
        }
    }
    return true;
}

```