#include <iostream>
using namespace std;

struct Node;
struct Edge;

struct Edge {
    Node* tujuan;
    Edge* next;
};

struct Node {
    char nama;
    bool aktif;        
    bool visited;
    Edge* firstEdge;
    Node* next;
};

Node* buatNode(char nama) {
    Node* n = new Node;
    n->nama = nama;
    n->aktif = true;
    n->visited = false;
    n->firstEdge = NULL;
    n->next = NULL;
    return n;
}

Edge* buatEdge(Node* tujuan) {
    Edge* e = new Edge;
    e->tujuan = tujuan;
    e->next = NULL;
    return e;
}

void tambahEdge(Node* from, Node* to) {
    Edge* e1 = buatEdge(to);
    e1->next = from->firstEdge;
    from->firstEdge = e1;

    Edge* e2 = buatEdge(from);
    e2->next = to->firstEdge;
    to->firstEdge = e2;
}

void DFS(Node* n) {
    if (n == NULL || !n->aktif || n->visited)
        return;

    n->visited = true;

    Edge* e = n->firstEdge;
    while (e != NULL) {
        DFS(e->tujuan);
        e = e->next;
    }
}

void resetVisited(Node* head) {
    while (head != NULL) {
        head->visited = false;
        head = head->next;
    }
}

bool grafTerputus(Node* head) {
    Node* start = NULL;
    Node* temp = head;

    while (temp != NULL) {
        if (temp->aktif) {
            start = temp;
            break;
        }
        temp = temp->next;
    }

    if (start == NULL)
        return true;

    DFS(start);

    temp = head;
    while (temp != NULL) {
        if (temp->aktif && !temp->visited)
            return true;
        temp = temp->next;
    }
    return false;
}

void analisisKotaKritis(Node* head) {
    Node* temp = head;

    cout << "\nAnalisis Kota Kritis (Single Point of Failure)\n";

    while (temp != NULL) {
        temp->aktif = false;
        resetVisited(head);

        if (grafTerputus(head)) {
            cout << "[PERINGATAN] Kota " << temp->nama
                 << " adalah KOTA KRITIS!\n";
            cout << " -> Jika " << temp->nama
                 << " lockdown, distribusi terputus.\n";
        } else {
            cout << "Kota " << temp->nama
                 << " aman (redundansi oke).\n";
        }

        temp->aktif = true;   
        temp = temp->next;
    }
}

void tampilkanGraph(Node* head) {
    cout << "Membangun Jaringan Distribusi Vaksin\n";

    Node* n = head;
    while (n != NULL) {
        cout << "Node " << n->nama << " terhubung ke: ";
        Edge* e = n->firstEdge;
        while (e != NULL) {
            cout << e->tujuan->nama << " ";
            e = e->next;
        }
        cout << endl;
        n = n->next;
    }
}

int main() {
    Node* A = buatNode('A');
    Node* B = buatNode('B');
    Node* C = buatNode('C');
    Node* D = buatNode('D');
    Node* E = buatNode('E');

    A->next = B;
    B->next = C;
    C->next = D;
    D->next = E;

    tambahEdge(A, B);
    tambahEdge(B, C);
    tambahEdge(B, E);
    tambahEdge(C, D);

    tampilkanGraph(A);
    analisisKotaKritis(A);

    return 0;
}