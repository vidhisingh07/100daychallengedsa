#include <stdio.h>

void merge(int arr[], int index[], int count[], int temp[], int tempIndex[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    int rightCount = 0;

    while(i <= mid && j <= right) {
        if(arr[index[j]] < arr[index[i]]) {
            tempIndex[k] = index[j];
            rightCount++;
            j++;
        } else {
            count[index[i]] += rightCount;
            tempIndex[k] = index[i];
            i++;
        }
        k++;
    }

    while(i <= mid) {
        count[index[i]] += rightCount;
        tempIndex[k++] = index[i++];
    }

    while(j <= right) {
        tempIndex[k++] = index[j++];
    }

    for(i = left; i <= right; i++) {
        index[i] = tempIndex[i];
    }
}

void mergeSort(int arr[], int index[], int count[], int temp[], int tempIndex[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, index, count, temp, tempIndex, left, mid);
        mergeSort(arr, index, count, temp, tempIndex, mid + 1, right);
        merge(arr, index, count, temp, tempIndex, left, mid, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000], index[1000], count[1000];
    int temp[1000], tempIndex[1000];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        index[i] = i;
        count[i] = 0;
    }

    mergeSort(arr, index, count, temp, tempIndex, 0, n - 1);

    for(int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}