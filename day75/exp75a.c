#include <stdio.h>

int maxLen(int arr[], int n) {
    int sum = 0, max_len = 0;

    // Using array as hashmap (for simplicity, assume range)
    // Better to use actual hashmap in real case
    int map[1000];
    for(int i = 0; i < 1000; i++) map[i] = -2;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(sum == 0) {
            max_len = i + 1;
        }

        if(map[sum + 500] != -2) { // offset to handle negative
            int len = i - map[sum + 500];
            if(len > max_len)
                max_len = len;
        } else {
            map[sum + 500] = i;
        }
    }
    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("%d\n", maxLen(arr, n));  // Output: 5
    return 0;
}