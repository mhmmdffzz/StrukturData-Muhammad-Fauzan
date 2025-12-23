#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode InsertNode(Graph &G, infoGraph X) {
    adrNode N = new ElmNode;
    N->info = X;
    N->visited = 0;
    N->firstEdge = NULL;
    N->next = NULL;

    if (G.first == NULL)
        G.first = N;
    else {
        adrNode temp = G.first;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = N;
    }
    return N;
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = new ElmEdge;
    E1->node = N2;
    E1->next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = new ElmEdge;
    E2->node = N1;
    E2->next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode N = G.first;
    while (N != NULL) {
        cout << N->info << " : ";
        adrEdge E = N->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        N = N->next;
    }
}

void ResetVisited(Graph &G) {
    adrNode N = G.first;
    while (N != NULL) {
        N->visited = 0;
        N = N->next;
    }
}

void PrintDFS(Graph G, adrNode N) {
    if (N == NULL || N->visited == 1)
        return;

    cout << N->info << " ";
    N->visited = 1;

    adrEdge E = N->firstEdge;
    while (E != NULL) {
        PrintDFS(G, E->node);
        E = E->next;
    }
}

struct Queue {
    adrNode data;
    Queue* next;
};

void enqueue(Queue* &front, Queue* &rear, adrNode N) {
    Queue* Q = new Queue{N, NULL};
    if (rear == NULL)
        front = rear = Q;
    else {
        rear->next = Q;
        rear = Q;
    }
}

adrNode dequeue(Queue* &front, Queue* &rear) {
    if (front == NULL)
        return NULL;
    Queue* Q = front;
    adrNode N = Q->data;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    delete Q;
    return N;
}

void PrintBFS(Graph G, adrNode start) {
    Queue *front = NULL, *rear = NULL;

    start->visited = 1;
    enqueue(front, rear, start);

    while (front != NULL) {
        adrNode N = dequeue(front, rear);
        cout << N->info << " ";

        adrEdge E = N->firstEdge;
        while (E != NULL) {
            if (E->node->visited == 0) {
                E->node->visited = 1;
                enqueue(front, rear, E->node);
            }
            E = E->next;
        }
    }
}
