#include <stdio.h>
#include <string.h>

#define EMPTY -1

int main() {
    int m, q;
    scanf("%d", &m);

    int table[m];
    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    scanf("%d", &q);

    char op[10];
    int key;

    while (q--) {
        scanf("%s %d", op, &key);

        int h = key % m;

        if (strcmp(op, "INSERT") == 0) {
            int i = 0;
            while (i < m) {
                int idx = (h + i * i) % m;
                if (table[idx] == EMPTY) {
                    table[idx] = key;
                    break;
                }
                i++;
            }
        } else if (strcmp(op, "SEARCH") == 0) {
            int i = 0;
            int found = 0;

            while (i < m) {
                int idx = (h + i * i) % m;

                if (table[idx] == key) {
                    found = 1;
                    break;
                }

                if (table[idx] == EMPTY)
                    break;

                i++;
            }

            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}