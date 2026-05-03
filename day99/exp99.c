#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    int speed;
} Car;

int cmp(const void *a, const void *b) {
    return ((Car*)a)->pos - ((Car*)b)->pos;
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    Car cars[1000];

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &cars[i].pos, &cars[i].speed);
    }

    qsort(cars, n, sizeof(Car), cmp);

    double time[1000];

    for(int i = 0; i < n; i++) {
        time[i] = (double)(target - cars[i].pos) / cars[i].speed;
    }

    int fleets = 0;
    double curr = 0;

    for(int i = n - 1; i >= 0; i--) {
        if(time[i] > curr) {
            fleets++;
            curr = time[i];
        }
    }

    printf("%d\n", fleets);
    return 0;
}