#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct List {
    struct Node* head;
};

struct Graph {
    int vertices;
    struct List* array;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    // destination node index
    newNode->data = data; 
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->array = (struct List*) malloc(vertices * sizeof(struct List));

    for (int i = 0; i < vertices; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {

    // set the destination as data of the new node
    struct Node* newNode = createNode(dest);

    // set the new node as the source node's head 
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

void DFS(struct Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true; // set visited true
    printf("%d ", vertex);

    // get the node's first adjacent node
    struct Node* currentNode = graph->array[vertex].head;

    while (currentNode) {
        int adjacentVertex = currentNode->data;
        // traverse the node's descendents first
        if (!visited[adjacentVertex]) {
            DFS(graph, adjacentVertex, visited);
        }
        // and then get the next adjacent node
        currentNode = currentNode->next;
    }
}

void DFSTraversal(struct Graph* graph, int* order, int orderSize) {
    bool* visited = (bool*) malloc(graph->vertices * sizeof(bool));

    // set visited with false
    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = false;
    }

    // traverse the graph starting the node's from the order array
    for (int i = 0; i < orderSize; i++) {
        if (!visited[order[i]]) { // if not already visited
            DFS(graph, order[i], visited);
        }
    }

    free(visited);
}

int main() {
    int vertices = 4;
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 2, 0);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 0, 1);
    addEdge(graph, 3, 3);
    addEdge(graph, 1, 3);

    int order[] = {2, 0, 1, 3};
    int orderSize = sizeof(order) / sizeof(order[0]);

    printf("Following isDepth FIrst Traversal (starting from vertex 2): \n");
    DFSTraversal(graph, order, orderSize);

    return 0;
}
