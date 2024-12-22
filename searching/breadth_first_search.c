#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

void bfs(int adj[MAX][MAX], int V, int s) {
    int q[MAX]; // queue
    int front = 0;
    int rear = 0;

    bool visited[MAX] = {false};

    visited[s] = true; // visit first node

    q[rear++] = s; // push the first node into the queue

    while (front < rear) { // until queue is empty
        int curr = q[front++];
        printf("%d ", curr);

        for (int i = 0; i < V; i++) { // loop through vertices
            if (adj[curr][i] == 1 && !visited[i]) { // if adjacent and not visited
                visited[i] = true;
                q[rear++] = i; // push into the queue
            }
        }
    }
}

void addEdge(int adj[MAX][MAX], int u, int v) {

    // undirectional graph
    adj[u][v] = 1;
    adj[v][u] = 1;
}

int main() {
    const int V = 5;
    int adj[MAX][MAX] = {0};

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    printf("BFS starting from 0:\n");
    bfs(adj, V, 0);
}