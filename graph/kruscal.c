#include <stdio.h>
#include <stdlib.h>

// compare by weights
int comparator(const void* p1, const void* p2) {
    const int (*x)[3] = p1;
    const int (*y)[3] = p2;

    return x[2] - y[2];
}

// innitialize parent and rank arrays
void makeSet(int parent[], int rank[], int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int parent[], int component) {
    if (parent[component] == component) {
        return component;
    }
    return parent[component] = findParent(parent, parent[component]);
}

// unite two sets into one
void unionSet(int u, int v, int parent[], int rank[]) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

void kruscal(int n, int edges[5][3]) {

    // sort by weights in ascending order
    qsort(edges, n, sirzeof(edges[0]), comparator);

    int parent[n];
    int rank[n];

    // initialze parent and rank
    makeSet(parent, rank, n);

    int minCost;

    printf("Following are the edges in the constructed MST\n");

    // if there are two sets unite them and 
    for (int i = 0; i < n; i++) {
        int v1 = findParent(parent, edges[i][0]);
        int v2 = findParent(parent, edges[i][1]);
        int wt = edges[i][2];

        if (v1 != v2) {
            // set parent-child relation
            unionSet(v1, v2, parent, rank);
            minCost += wt;
            printf("%d -- %d == %d\n", edges[i][0], edges[i][1], wt);
        }
    }

    printf("Minimum cost spaning tree: %d\n", minCost);

}

int main() {
    int edges[5][3] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruscal(5, edges);

    return 0;
}