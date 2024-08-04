void concure(int *ar, int mid, int l, int r) {
    int i = l, j = mid + 1;
    int a[r - l + 1];
    int m = 0;
    while (i <= mid && j <= r) {
        if (ar[i] <= ar[j]) {
            a[m++] = ar[i++];
        } else {
            a[m++] = ar[j++];
        }
    }
    while (i <= mid) {
        a[m++] = ar[i++];
    }
    while (j <= r) {
        a[m++] = ar[j++];
    }
    for (int k = l; k <= r; k++) {
        ar[k] = a[k - l];
    }
}

void devide(int *ar, int l, int r) {
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    devide(ar, l, mid);
    devide(ar, mid + 1, r);
    concure(ar, mid, l, r);
}

int rangeSum(int* nums, int numsSize, int n, int left, int right) {
    int l = n * (n + 1) / 2;
    int k = 0, i, j;
    unsigned int sum[l], temp = 0;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            temp += nums[j];
            sum[k++] = temp;
        }
        temp = 0;
    }
    devide(sum, 0, l - 1);
    temp = 0; // Reset temp to 0
    for (i = left - 1; i < right; i++) {
        temp = (temp + sum[i]) % 1000000007;
    }
    return temp;
}
