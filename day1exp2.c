#include<stdio.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    static int result[2];
    *returnSize=2;
    for(int i=0;i<numSize;i++){
        for(int j=i+1;j<numSize;j++){
            if(nums[i]+nums[j]==target){
            result[0]=i;
            result[1]=j;
            return result;
            }
        }
    }
    return NULL;
}
