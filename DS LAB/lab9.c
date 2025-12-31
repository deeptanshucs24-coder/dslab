#include <stdio.h>

int adj[10][10], visited[10];
int n;

/* DFS Traversal */
void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

/* BFS Traversal */
void BFS(int start) {
    int queue[10], front = 0, rear = 0;
    int visited_bfs[10] = {0};

    queue[rear++] = start;
    visited_bfs[start] = 1;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited_bfs[i] == 0) {
                queue[rear++] = i;
                visited_bfs[i] = 1;
            }
        }
    }
}

int main() {
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("\nDFS Traversal: ");
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    DFS(start);

    printf("\nBFS Traversal: ");
    BFS(start);

    return 0;
}
