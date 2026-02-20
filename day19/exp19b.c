int maxSubarraySumCircular(int* nums, int numsSize) {
    int totalSum = nums[0];
    int curMax = nums[0], maxSum = nums[0];
    int curMin = nums[0], minSum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        totalSum += nums[i];
        curMax = fmax(nums[i], curMax + nums[i]);
        maxSum = fmax(maxSum, curMax);
        curMin = fmin(nums[i], curMin + nums[i]);
        minSum = fmin(minSum, curMin);
    }
    if (maxSum < 0)
        return maxSum;
    return fmax(maxSum, totalSum - minSum);
}