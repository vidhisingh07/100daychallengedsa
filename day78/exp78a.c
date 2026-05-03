#include <stdio.h>
#include <limits.h>

int graph[1000][1000];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int selected[1000] = {0};
    int min_edge[1000];

    for(int i = 1; i <= n; i++) {
        min_edge[i] = INT_MAX;
    }

    min_edge[1] = 0;
    int total = 0;

    for(int i = 1; i <= n; i++) {
        int u = -1;
        for(int j = 1; j <= n; j++) {
            if(!selected[j] && (u == -1 || min_edge[j] < min_edge[u])) {
                u = j;
            }
        }

        selected[u] = 1;
        total += min_edge[u];

        for(int v = 1; v <= n; v++) {
            if(graph[u][v] && !selected[v] && graph[u][v] < min_edge[v]) {
                min_edge[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", total);
    return 0;
}