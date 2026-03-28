int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }

    int* result = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    int* dq = (int*)malloc(sizeof(int) * numsSize);
    int front = 0, rear = 0;

    *returnSize = numsSize - k + 1;

    for (int i = 0; i < numsSize; i++) {
        if (front < rear && dq[front] < i - k + 1) {
            front++;
        }
        while (front < rear && nums[dq[rear - 1]] < nums[i]) {
            rear--;
        }
        dq[rear++] = i;
        if (i >= k - 1) {
            result[i - k + 1] = nums[dq[front]];
        }
    }

    free(dq);
    return result;
}