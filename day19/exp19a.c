//Problem: Given an array of integers, find two elements whose sum is closest to zero.

// s.Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the pair of elements whose sum is closest to zero

// Example:
// Input:
// 5
// 1 60 -10 70 -80

// Output:
// -10 1

// Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pair
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Comparator for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    printf("entr number of integer ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;

    int closestSum = arr[left] + arr[right];
    int bestLeft = arr[left];
    int bestRight = arr[right];

    while (left < right) {
        int currentSum = arr[left] + arr[right];
        if (abs(currentSum) < abs(closestSum)) {
            closestSum = currentSum;
            bestLeft = arr[left];
            bestRight = arr[right];
        }
        if (currentSum < 0)
            left++;
        else if (currentSum > 0)
            right--;
        else
            break; 
    }

    printf("%d %d\n", bestLeft, bestRight);

    return 0;
}