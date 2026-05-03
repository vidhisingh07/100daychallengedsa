#include <stdio.h>

int possible(int arr[], int n, int k, int maxTime) {
    int painters = 1, curr = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > maxTime) return 0;

        if(curr + arr[i] > maxTime) {
            painters++;
            curr = arr[i];
        } else {
            curr += arr[i];
        }
    }

    return painters <= k;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[1000];
    int sum = 0, mx = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if(arr[i] > mx) mx = arr[i];
    }

    int left = mx, right = sum, ans = sum;

    while(left <= right) {
        int mid = (left + right) / 2;

        if(possible(arr, n, k, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%d\n", ans);
    return 0;
}