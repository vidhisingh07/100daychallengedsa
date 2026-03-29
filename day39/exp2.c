#include <stdlib.h>

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = k;
    int offset = 10000;
    int freq[20001] = {0};

    for (int i = 0; i < numsSize; i++) {
        freq[nums[i] + offset]++;
    }
    int** buckets = (int**)malloc((numsSize + 1) * sizeof(int*));
    int* bucketSize = (int*)calloc(numsSize + 1, sizeof(int));

    for (int i = 0; i <= numsSize; i++) {
        buckets[i] = (int*)malloc(numsSize * sizeof(int));
    }
    for (int i = 0; i < 20001; i++) {
        if (freq[i] > 0) {
            int f = freq[i];
            buckets[f][bucketSize[f]++] = i - offset;
        }
    }
    int* result = (int*)malloc(sizeof(int) * k);
    int count = 0;

    for (int i = numsSize; i >= 0 && count < k; i--) {
        for (int j = 0; j < bucketSize[i] && count < k; j++) {
            result[count++] = buckets[i][j];
        }
    }

    return result;
}