# <h1 align="center">Laporan Praktikum Modul 14 - Graph </h1>
<p align="center">Muhammad Fauzan - 103112400064</p>

## Dasar Teori
Graph merupakan salah satu struktur data non-linier yang digunakan untuk merepresentasikan hubungan antar data dalam bentuk simpul (*vertex*) dan sisi (*edge*). Setiap simpul mewakili suatu objek, sedangkan sisi menunjukkan hubungan antara dua simpul. Struktur data graph tidak tersusun secara berurutan seperti array atau linked list, melainkan membentuk relasi yang kompleks antar elemen data. Berdasarkan arah hubungannya, graph dibedakan menjadi graph berarah (*directed graph*) dan graph tidak berarah (*undirected graph*), di mana pada graph tidak berarah hubungan antar simpul bersifat dua arah [1][3].

Graph dapat direpresentasikan dalam beberapa bentuk, di antaranya **adjacency matrix** dan **adjacency list**. Adjacency list merupakan representasi graph yang menyimpan daftar simpul yang terhubung pada setiap simpul, dan umumnya diimplementasikan menggunakan struktur data berbasis pointer seperti linked list. Representasi ini lebih efisien dalam penggunaan memori dibandingkan adjacency matrix, terutama untuk graph dengan jumlah sisi yang relatif sedikit [2][4]. Selain itu, graph juga dapat diklasifikasikan menjadi graph berbobot (*weighted graph*) dan tidak berbobot, tergantung ada atau tidaknya nilai bobot pada sisi yang merepresentasikan jarak atau biaya [1].

Dalam pemrosesan graph, digunakan algoritma penelusuran untuk mengunjungi seluruh simpul secara sistematis, di antaranya **Depth First Search (DFS)** dan **Breadth First Search (BFS)**. DFS melakukan penelusuran dengan mendalami satu jalur hingga mencapai simpul terdalam sebelum berpindah ke jalur lain, sedangkan BFS menelusuri graph secara melebar berdasarkan tingkat kedalaman simpul menggunakan struktur data queue. Algoritma DFS dan BFS banyak diterapkan dalam berbagai permasalahan nyata seperti pencarian rute, analisis jaringan, sistem rekomendasi, dan navigasi digital [3][4].


## Guided

### 1.Graph
#### graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
void ResetVisited(Graph &G);
void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);

#endif
```
#### graph_edge.cpp
```C++
#include "graph.h"

adrNode findNode(Graph G, infoGraph x) {
    adrNode p = G->first;
    while (p != NULL) {
        if (p->info == x) return p;
        p = p->nextNode;
    }
    return NULL;
}

void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge;
        //Insert First di list Edge
        pStart->firstEdge = newEdge;
    }
}
```
#### graph_init.cpp
```C++
#include "graph.h"

void createGraph(Graph &G) {
    G->first = NULL;
}

adrNode allocateNode(infoGraph x) {
    adrNode P = new ElmNode;
    P->info = x;
    P->visited = false;
    P->firstEdge = NULL;
    P->nextNode = NULL;
    return P;
}

void insertNode(Graph &G, infoGraph x) {
    adrNode P = allocateNode(x);
    if (G->first == NULL) {
        G->first = P;
    } else {
        adrNode Q = G->first;
        while (Q->nextNode != NULL) {
            Q = Q->nextNode;
        }
        Q->nextNode = P;
    }
}
```

#### graph_print.cpp
```C++
#include "graph.h"

void printGraph(Graph G) {
    adrNode p = G->first;
    while (p != NULL) {
        cout << "Node " << p->info << " terhubung ke: ";
        adrEdge e = p->firstEdge;
        while (e != NULL) {
            cout << e->node->info << " ";
            e = e->next;
        }
        cout << endl;
        p = p->nextNode;
    }
}
```

#### main.cpp
```C++
#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Create Graph
    Graph G = new elmGraph;
    createGraph(G);

    // 2. Insert Nodes
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    // 3. Connect Nodes (Edges)
    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'C', 'D');

    // 4. Print Graph Structure
    cout << "Isi Graph:" << endl;
    printGraph(G);

    return 0;
}
```
Program ini mengimplementasikan struktur data **Graph** menggunakan pendekatan **Adjacency List** berbasis pointer. Setiap simpul direpresentasikan oleh struktur `ElmNode` yang menyimpan informasi node, status kunjungan, serta pointer ke daftar edge dan node berikutnya. Hubungan antar simpul direpresentasikan oleh struktur `ElmEdge` yang menyimpan pointer ke simpul tujuan. Proses pembentukan graph diawali dengan inisialisasi graph kosong, dilanjutkan dengan penambahan node dan penghubungan node menggunakan edge. Program juga menyediakan fungsi untuk menampilkan struktur graph, sehingga hubungan antar node dapat diamati secara jelas. Implementasi ini memberikan pemahaman dasar mengenai konsep graph serta penggunaan pointer dalam merepresentasikan relasi antar data secara dinamis.

## Unguided 
### 1. Implementasi Graph Tidak Berarah Lengkap dengan DFS dan BFS
#### Graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
void ResetVisited(Graph &G);
void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);

#endif
```
#### Graph.cpp
```C++
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
```
#### main.cpp
```C++
#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    adrNode A = InsertNode(G, 'A');
    adrNode B = InsertNode(G, 'B');
    adrNode C = InsertNode(G, 'C');
    adrNode D = InsertNode(G, 'D');
    adrNode E = InsertNode(G, 'E');
    adrNode F = InsertNode(G, 'F');
    adrNode Gg = InsertNode(G, 'G');
    adrNode H = InsertNode(G, 'H');

    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, Gg);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gg, H);

    cout << " GRAPH \n";
    PrintInfoGraph(G);

    cout << "\nDFS : ";
    PrintDFS(G, A);
    ResetVisited(G);

    cout << "\nBFS : ";
    PrintBFS(G, A);

    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Output Program 1](https://github.com/mhmmdffzz/StrukturData-Muhammad-Fauzan/blob/main/Pertemuan12_Modul14/LAPRAK/Muhammad_Fauzan-Output-Unguided1.png)

**Program C++ ini** mengimplementasikan Graph tidak berarah menggunakan struktur data berbasis pointer, di mana setiap node direpresentasikan oleh struktur `ElmNode` dan setiap sisi direpresentasikan oleh struktur `ElmEdge` yang menyimpan pointer ke node tujuan. Graph dikelola melalui struktur `Graph` yang menyimpan pointer ke node pertama. Proses penelusuran graph dilakukan menggunakan dua metode, yaitu Depth First Search (DFS) dan Breadth First Search (BFS). DFS bekerja secara rekursif dengan menelusuri node hingga ke kedalaman terdalam sebelum berpindah ke node lain, sedangkan BFS menelusuri graph berdasarkan level menggunakan struktur queue berbasis pointer. Variabel `visited` digunakan sebagai penanda untuk memastikan setiap node hanya dikunjungi satu kali selama proses traversal. Hasil dari program ini berupa urutan node yang dikunjungi selama proses DFS dan BFS sesuai dengan struktur graph yang dibentuk.

## Kesimpulan
Berdasarkan praktikum yang telah dilakukan, dapat disimpulkan bahwa struktur data **Graph** merupakan struktur data non-linier yang efektif untuk merepresentasikan hubungan antar data yang bersifat kompleks. Implementasi graph tidak berarah menggunakan adjacency list berbasis pointer memungkinkan pengelolaan simpul dan sisi dilakukan secara dinamis tanpa ketergantungan pada struktur data statis. Proses penelusuran graph menggunakan algoritma **Depth First Search (DFS)** dan **Breadth First Search (BFS)** memberikan pemahaman yang jelas mengenai cara menjelajahi seluruh simpul graph dengan pendekatan yang berbeda, baik secara mendalam maupun berdasarkan level. Praktikum ini memperkuat pemahaman mengenai penggunaan pointer dalam struktur data graph serta menjadi dasar penting dalam mempelajari algoritma dan struktur data lanjutan yang berkaitan dengan graph.

## Referensi
[1]. Trivusi. (2022). *Struktur Data Graph: Pengertian, Jenis, dan Kegunaannya*.  
Artikel ini membahas pengertian graph, karakteristik simpul dan sisi, serta jenis graph berarah dan tak berarah.  
https://www.trivusi.web.id/2022/07/struktur-data-graph.html

[2]. BIF Telkom University. (2025). *Mengenal Struktur Data Graph: Definisi dan Manfaat*.  
Materi ini menjelaskan konsep graph, representasi adjacency list dan matrix, serta manfaatnya dalam pemodelan hubungan data.  
https://bif.telkomuniversity.ac.id/mengenal-struktur-data-graph-definisi-dan-manfaat/

[3]. Ahmad Zipur. (2024). *Struktur Data Graph – Pengertian, Jenis, dan Algoritma*.  
Sumber yang menguraikan definisi graph, representasi matematis G = (V, E), serta gambaran algoritma pemrosesan graph.  
https://ahmadzipur.com/8-struktur-data-graph-pengertian-jenis-dan-algoritma/

[4]. BIF Telkom University. (2025). *Struktur Data Graph – Rahasia di Balik Algoritma Rekomendasi dan Navigasi Digital*.  
Artikel ini memperluas pembahasan graph termasuk representasi adjacency list dan aplikasi graph dalam sistem rekomendasi serta analisis hubungan kompleks.  
https://bif.telkomuniversity.ac.id/struktur-data-graph-rahasia-di-balik-algoritma-rekomendasi-dan-navigasi-digital/