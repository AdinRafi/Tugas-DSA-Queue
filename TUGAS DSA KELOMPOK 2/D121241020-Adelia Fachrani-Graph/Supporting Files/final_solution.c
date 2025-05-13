#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 20005  // Cukup besar untuk menampung hingga 2*N

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* graph[MAX_NODES];
bool visited[MAX_NODES];

// Menambahkan edge ke adjacency list
void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = v;
    newNode->next = graph[u];
    graph[u] = newNode;
}

// Breadth-First Search untuk menghitung ukuran komponen
int bfs(int start) {
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    int size = 0;

    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int node = queue[front++];
        size++;

        Node* temp = graph[node];
        while (temp != NULL) {
            int neighbor = temp->value;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue[rear++] = neighbor;
            }
            temp = temp->next;
        }
    }

    return size;
}

int main() {
    int n = 4;
    int edges[][2] = {
        {1, 5},
        {2, 6},
        {3, 6},
        {4, 7},
        {7, 8}
    };
    int edgeCount = sizeof(edges) / sizeof(edges[0]);

    // Inisialisasi graph
    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        addEdge(u, v);
        addEdge(v, u);
    }

    int minSize = MAX_NODES, maxSize = 0;

    for (int i = 1; i <= 2 * n; i++) {
        if (!visited[i] && graph[i] != NULL) {
            int size = bfs(i);
            if (size >= 2) {
                if (size < minSize) minSize = size;
                if (size > maxSize) maxSize = size;
            }
        }
    }

    if (maxSize == 0) {
        printf("Komponen Terkecil: 0\n");
        printf("Komponen Terbesar: 0\n");
    } else {
        printf("Komponen Terkecil: %d\n", minSize);
        printf("Komponen Terbesar: %d\n", maxSize);
    }

    return 0;
}
