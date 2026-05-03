#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int cmp(const void *a, const void *b) {
    Interval *i1 = (Interval*)a;
    Interval *i2 = (Interval*)b;
    return i1->start - i2->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[1000];

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(Interval), cmp);

    int idx = 0;

    for(int i = 1; i < n; i++) {
        if(arr[idx].end >= arr[i].start) {
            if(arr[idx].end < arr[i].end) {
                arr[idx].end = arr[i].end;
            }
        } else {
            idx++;
            arr[idx] = arr[i];
        }
    }

    for(int i = 0; i <= idx; i++) {
        printf("%d %d\n", arr[i].start, arr[i].end);
    }

    return 0;
}