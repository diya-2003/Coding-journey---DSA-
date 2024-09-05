int* missingRolls(int* rolls, int rollsSize, int mean, int n, int* returnSize) {
    int total_sum = mean * (n + rollsSize);
    int observed_sum = 0;
    for (int i = 0; i < rollsSize; i++) {
        observed_sum += rolls[i];    }
    int missing_sum = total_sum - observed_sum;
    if (missing_sum < n || missing_sum > 6 * n) {
        *returnSize = 0;
        return NULL;    }
    int* result = (int*)malloc(n * sizeof(int));
    *returnSize = n;
    int avg = missing_sum / n;
    int remainder = missing_sum % n;
    for (int i = 0; i < n; i++) {
        result[i] = avg + (i < remainder ? 1 : 0);    }
    return result;}
/*
  Author   : Diya Maity
	Date     : Thursday, September 5, 2024, 4:03 PM
	LinkedIn : https://www.linkedin.com/in/diyamity
	GitHub   : https://github.com/diya-2003
	LeetCode : https://leetcode.com/u/diyamaity	
*/
