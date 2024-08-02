int minSwaps(int* nums, int numsSize) {
    int first = 0;
    int second = 0;
    int zero = 0;
    int keep = 0;
    int minzero = INT_MAX;
    int* dummy = (int*)malloc(2*numsSize*sizeof(int));

    int ones = 0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]==1)
        ones++;
    
        dummy[i] = nums[i];
        dummy[i+numsSize] = nums[i];
    }

    while(first<(2*numsSize)){
        keep++;
        if(dummy[first] == 0){
            zero++;
        }

        while(keep>ones){
            if(dummy[second] == 0)
            zero--;

            if(zero<minzero)
            minzero = zero;
            second++;
            keep--;
        }
        first++;
    }
    return minzero;

}
