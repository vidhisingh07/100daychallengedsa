/**/
#include <stdio.h>

int findMissing(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum = sum+arr[i];
    }
    int total = (n * (n + 1)) / 2;
    return total - sum;
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    
    int arr[n - 1];
    printf("Enter %d elements: ", n - 1);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("%d\n", findMissing(arr, n));
    
    return 0;
}