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

    int source;
    scanf("%d", &source);

    int dist[1000];
    int visited[1000] = {0};

    for(int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }

    dist[source] = 0;

    for(int i = 1; i <= n; i++) {
        int u = -1;
        for(int j = 1; j <= n; j++) {
            if(!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        visited[u] = 1;

        for(int v = 1; v <= n; v++) {
            if(graph[u][v] && !visited[v] && dist[u] != INT_MAX &&
               dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}