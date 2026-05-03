#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int n;
    scanf("%d", &n);

    int start[1000], end[1000];

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &start[i], &end[i]);
    }

    qsort(start, n, sizeof(int), cmp);
    qsort(end, n, sizeof(int), cmp);

    int rooms = 0, maxRooms = 0;
    int i = 0, j = 0;

    while(i < n && j < n) {
        if(start[i] < end[j]) {
            rooms++;
            if(rooms > maxRooms) maxRooms = rooms;
            i++;
        } else {
            rooms--;
            j++;
        }
    }

    printf("%d\n", maxRooms);
    return 0;
}
