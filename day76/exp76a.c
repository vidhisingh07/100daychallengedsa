#include <stdio.h>
#include <stdlib.h>

int visited[1000];
int adj[1000][1000];

void dfs(int v, int n) {
    visited[v] = 1;
    for(int i = 1; i <= n; i++) {
        if(adj[v][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int count = 0;

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i, n);
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}