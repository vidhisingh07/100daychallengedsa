#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node* adjLists[MAX];
    int indegree[MAX];
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->indegree[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    graph->indegree[dest]++;
}

void topologicalSort(struct Graph* graph) {
    int queue[MAX];
    int front = 0, rear = 0;

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;

    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);

        struct Node* temp = graph->adjLists[u];
        while (temp) {
            int v = temp->vertex;
            graph->indegree[v]--;

            if (graph->indegree[v] == 0)
                queue[rear++] = v;

            temp = temp->next;
        }
        count++;
    }

    if (count != graph->numVertices) {
        printf("\nCycle detected\n");
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    topologicalSort(graph);

    return 0;
}