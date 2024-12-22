#include <stdio.h>
#define INFINITY 9999
#define MAX 10

// get min distasnces for all nodes
void dijkstra(int graph[MAX][MAX], int n, int start) {
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, minDistance, nextNode, i, j;

    // push weights into cost array
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == 0) {
                cost[i][j] = INFINITY;
            } else {
                cost[i][j] = graph[i][j];
            }
        }
    }

    // set distances with cost and initialize visited array
    for (i = 0; i < n; i++) {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    // initialize for start node 
    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    while (count < n - 1) {
        minDistance = INFINITY;

        // find nearest node
        for (i = 0; i < n; i++) {
            if (distance[i] < minDistance && !visited[i]) {
                minDistance = distance[i];
                nextNode = i;
            }
        }

        // set nearest node as visited
        visited[nextNode] = 1;

        // if shorter path is found update distance
        for (i = 0; i < n; i++) {
            if (!visited[i]) {
                if (minDistance + cost[nextNode][i] < distance[i]) {
                    distance[i] = minDistance + cost[nextNode][i];
                    pred[i] = nextNode;
                }   
            }
        }

        count++;
    }

    // print nodes
    for (i = 0; i < n; i++) {
        if (i != start) {
            printf("\nDistance from source to %d: %d", i, distance[i]);
        }
    }
}

int main()
{
    int graph[MAX][MAX], i, j, n, u;
    n = 7;

    graph[0][0] = 0;
    graph[0][1] = 0;
    graph[0][2] = 1;
    graph[0][3] = 2;
    graph[0][4] = 0;
    graph[0][5] = 0;
    graph[0][6] = 0;

    graph[1][0] = 0;
    graph[1][1] = 0;
    graph[1][2] = 2;
    graph[1][3] = 0;
    graph[1][4] = 0;
    graph[1][5] = 3;
    graph[1][6] = 0;

    graph[2][0] = 1;
    graph[2][1] = 2;
    graph[2][2] = 0;
    graph[2][3] = 1;
    graph[2][4] = 3;
    graph[2][5] = 0;
    graph[2][6] = 0;

    graph[3][0] = 2;
    graph[3][1] = 0;
    graph[3][2] = 1;
    graph[3][3] = 0;
    graph[3][4] = 0;
    graph[3][5] = 0;
    graph[3][6] = 1;

    graph[4][0] = 0;
    graph[4][1] = 0;
    graph[4][2] = 3;
    graph[4][3] = 0;
    graph[4][4] = 0;
    graph[4][5] = 2;
    graph[4][6] = 0;

    graph[5][0] = 0;
    graph[5][1] = 3;
    graph[5][2] = 0;
    graph[5][3] = 0;
    graph[5][4] = 2;
    graph[5][5] = 0;
    graph[5][6] = 1;

    graph[6][0] = 0;
    graph[6][1] = 0;
    graph[6][2] = 0;
    graph[6][3] = 1;
    graph[6][4] = 0;
    graph[6][5] = 1;
    graph[6][6] = 0;

    u = 0;
    dijkstra(graph, n, u);

    return 0;
}