#include <stdio.h>
#include <string.h>

#define MAX 1000
#define LEN 50

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][LEN];
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    char unique[MAX][LEN];
    int count[MAX] = {0};
    int k = 0;

    for (int i = 0; i < n; i++) {
        int found = -1;

        for (int j = 0; j < k; j++) {
            if (strcmp(unique[j], names[i]) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            count[found]++;
        } else {
            strcpy(unique[k], names[i]);
            count[k] = 1;
            k++;
        }
    }

    int maxVotes = 0;
    char winner[LEN];

    for (int i = 0; i < k; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, unique[i]);
        } else if (count[i] == maxVotes) {
            if (strcmp(unique[i], winner) < 0) {
                strcpy(winner, unique[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}