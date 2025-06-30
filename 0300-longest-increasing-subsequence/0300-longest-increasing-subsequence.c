int dp[2505];   // length of the LIS, ends with dp[i]
/*
    dp[i] : max(dp[i-k]) + 1, nums[i-k] < nums[i], k=0~i-1
*/

int lengthOfLIS(int* nums, int numsSize) {
    // init dp[i] to all 1
    for (int i=0; i<dp[numsSize]; i++) {
        dp[i] = 1;
    }

    // iterate i
    int ret = 0;
    for (int i=0; i<numsSize; i++) {
        // iterate 0~i-1
        int max = 0;
        for (int j=0; j<i; j++) {
            // get max
            if (nums[i] > nums[j] && max < dp[j]) {
                max = dp[j];
            }
        }
        // set max + 1
        dp[i] = max + 1;
        // save max value
        if (ret < dp[i])
            ret = dp[i];
    }

    // return max value
    return ret;
}