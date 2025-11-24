# <h1 align="center">Laporan Praktikum Modul 8 - Queue </h1>
<p align="center">Muhammad Fauzan - 103112400064</p>

## Dasar Teori
Queue merupakan salah satu struktur data linier yang bekerja dengan prinsip **FIFO (First In, First Out)**, di mana elemen yang pertama masuk akan menjadi elemen pertama yang diproses atau dikeluarkan [1]. Struktur ini menyerupai antrean pada kehidupan nyata, seperti antrean layanan atau pembelian tiket, di mana setiap elemen diproses sesuai urutan kedatangannya. Operasi dasar pada queue meliputi **enqueue** untuk menambahkan elemen ke bagian belakang antrian, **dequeue** untuk menghapus elemen pada bagian depan antrian, serta pemeriksaan kondisi menggunakan **isEmpty** dan **isFull** [1].

Queue dapat diimplementasikan menggunakan **array**, **linked list**, maupun **circular queue**, masing-masing dengan karakteristik berbeda. Implementasi array mudah dipahami namun terbatas kapasitasnya; linked list menawarkan ukuran dinamis tanpa batas; sedangkan circular queue memanfaatkan ruang array secara optimal melalui pergerakan head dan tail menggunakan operasi modulo [2]. Queue banyak digunakan pada sistem operasi (penjadwalan proses), buffer jaringan, antrian printer, hingga simulasi antrean. Pemahaman mengenai alur FIFO, pergerakan head–tail, serta kondisi penuh dan kosong sangat penting agar queue dapat bekerja dengan benar dan efisien [2].

## Guided

### 1. Queue Linked List
#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL    

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct queue{
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(address &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchData(queue Q, int data);

#endif 
```
#### queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}
```
#### main.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enQueue(Q, nodeA);
    enQueue(Q, nodeB);
    enQueue(Q, nodeC);
    enQueue(Q, nodeD);
    enQueue(Q, nodeE);
    cout << endl;

    cout << "--- Queue setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Queue setelah deQueue 2 kali ---" << endl;
    viewQueue(Q);
    cout << endl;
    
    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "--- Queue setelah update ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchData(Q, 4);
    searchData(Q, 9);

    return 0;
}

```
Program C++ ini menunjukkan cara kerja struktur data Queue dengan menggunakan linked list sebagai media penyimpanan elemen. Proses enqueue dilakukan dengan menambahkan node pada bagian akhir antrian, sedangkan dequeue menghapus node dari bagian depan sehingga tetap mengikuti konsep FIFO (First In, First Out). Selain itu, program menyediakan fungsi untuk mengubah nilai pada posisi tertentu, mencari data di dalam antrian, serta menampilkan seluruh isi queue. Dengan memanfaatkan linked list, ukuran queue dapat bertambah secara fleksibel tanpa batasan kapasitas seperti pada array.

### 2. Circular Queue
#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5

struct Queue{
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```
#### queue.cpp
```C++
#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}
```
#### main.cpp
```C++
#include<iostream>
#include "queue.h"
using namespace std;

int main() {
    Queue Q;
    createQueue(Q);
    printInfo(Q);

    cout<<"\n enqueue 3 elemen"<< endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);
    cout<<"\n dequeue 1 elemen"<< endl;
    cout<<"elemen keluar"<< dequeue(Q)<< endl;
    printInfo(Q);
    cout<<"\n enqueue 1 elemen"<< endl;
    enqueue(Q, 4);
    printInfo(Q);
    cout<<"\n dequeue 2 elemen"<<endl;
    cout<< "elemen keluar"<< dequeue(Q) <<endl;
    cout<< "elemen keluar"<<dequeue(Q)<< endl;
    printInfo(Q);
    return 0;

}
```
Program C++ ini menerapkan struktur data Circular Queue dengan memanfaatkan array berkapasitas tetap. Proses enqueue menempatkan data baru pada indeks tail yang bergerak melingkar melalui operasi modulo, sementara dequeue menghapus elemen pada indeks head dengan pola yang sama. Pendekatan circular ini memungkinkan seluruh slot array digunakan tanpa perlu menggeser elemen, sehingga lebih efisien dibandingkan antrian linear biasa. Program juga mencakup pengecekan kondisi penuh atau kosong dan kemampuan untuk menampilkan seluruh isi antrian secara berurutan.

## Unguided 

### 1. Alternatif 1 - Head Diam, Tail Bergerak (Shifting / Geser Elemen)
#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```
#### queue_alt1.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q){
    return (Q.head == -1);
}

bool isFullQueue(Queue Q){
    return (Q.tail == 4);
}

void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = Q.tail = 0;
    } else {
        Q.tail++;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)){
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    // Geser elemen (shifting)
    for (int i = Q.head; i < Q.tail; i++)
        Q.info[i] = Q.info[i + 1];

    Q.tail--;

    // Queue kosong hanya jika tail = -1
    if (Q.tail < 0)
        Q.head = Q.tail = -1;

    return x;
}

void printInfo(Queue Q){
    cout << Q.head << " - " << Q.tail << " \t| ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    for (int i = Q.head; i <= Q.tail; i++)
        cout << Q.info[i] << " ";

    cout << endl;
}

```
#### main.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue Info" << endl;
    cout << "----------------------" << endl;

    printInfo(Q);

    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);

    dequeue(Q);    printInfo(Q);
    enqueue(Q,4);  printInfo(Q);

    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Output Program 1](https://github.com/mhmmdffzz/StrukturData-Muhammad-Fauzan/blob/main/Pertemuan8_Modul8/LAPRAK/Muhammad_Fauzan-Output-Unguided1.png)

Program C++ ini mengimplementasikan queue dengan head tetap di indeks 0, sehingga setiap operasi dequeue membutuhkan penggeseran seluruh elemen satu posisi ke kiri. Pendekatan ini paling mudah dipahami karena perilakunya menyerupai antrean nyata, namun kurang efisien karena proses shifting dilakukan pada setiap penghapusan elemen.

### 2. Alternatif 2 - Head Bergerak, Tail Bergerak (Tanpa Circular)
#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```
#### queue_alt2.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q){
    return Q.head == -1;
}

bool isFullQueue(Queue Q){
    return Q.tail == 4;
}

void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)){
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)){
        Q.head = Q.tail = 0;
    } else {
        Q.tail++;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)){
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];
    Q.head++;

    if (Q.head > Q.tail)
        Q.head = Q.tail = -1;

    return x;
}

void printInfo(Queue Q){
    cout << Q.head << " - " << Q.tail << " \t| ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue\n";
        return;
    }

    for (int i = Q.head; i <= Q.tail; i++)
        cout << Q.info[i] << " ";

    cout << endl;
}
```
#### main.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue Info" << endl;
    cout << "----------------------" << endl;

    printInfo(Q);

    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);

    dequeue(Q);    printInfo(Q);
    enqueue(Q,4);  printInfo(Q);

    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Output Program 1](https://github.com/mhmmdffzz/StrukturData-Muhammad-Fauzan/blob/main/Pertemuan8_Modul8/LAPRAK/Muhammad_Fauzan-Output-Unguided2.png)

Program C++ ini menggunakan queue dengan head dan tail yang bergerak maju tanpa melakukan shifting. Implementasi ini lebih efisien dibanding Alternatif 1, namun dapat mengalami kondisi “penuh semu” ketika tail mencapai akhir array meskipun masih terdapat ruang kosong di awal akibat head sudah maju.

### 3. Alternatif 3 - Circular Queue (Head & Tail Berputar)
#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```
#### queue_alt3.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q){
    return Q.head == -1;
}

bool isFullQueue(Queue Q){
    return ((Q.tail + 1) % 5 == Q.head);
}

void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)){
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)){
        Q.head = Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % 5;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)){
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail){
        Q.head = Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % 5;
    }

    return x;
}

void printInfo(Queue Q){
    cout << Q.head << " - " << Q.tail << " \t| ";

    if (isEmptyQueue(Q)){
        cout << "empty queue" << endl;
        return;
    }

    int i = Q.head;
    while (true){
        cout << Q.info[i] << " ";
        if (i == Q.tail) break;
        i = (i + 1) % 5;
    }

    cout << endl;
}
```
#### main.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue Info" << endl;
    cout << "----------------------" << endl;

    printInfo(Q);

    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);

    dequeue(Q);    printInfo(Q);
    enqueue(Q,4);  printInfo(Q);

    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```

### Output Unguided 3 :

##### Output 1
![Output Program 1](https://github.com/mhmmdffzz/StrukturData-Muhammad-Fauzan/blob/main/Pertemuan8_Modul8/LAPRAK/Muhammad_Fauzan-Output-Unguided3.png)

Program C++ ini menerapkan queue melingkar dengan memanfaatkan operasi modulo sehingga head dan tail dapat berputar kembali ke awal array. Pendekatan circular ini mengatasi penuh semu dan menghilangkan kebutuhan shifting, sehingga menjadi implementasi paling efisien dan optimal dalam penggunaan memori.

## Kesimpulan
Pada praktikum ini dipelajari konsep dan implementasi struktur data **Queue** yang bekerja dengan prinsip FIFO. Beberapa operasi penting seperti enqueue, dequeue, pencarian data, pembaruan elemen, dan penampilan isi antrian telah diuji pada berbagai jenis queue, termasuk linked list, queue linier menggunakan array, dan circular queue. Setiap implementasi menunjukkan cara kerja queue dalam memproses data dari head ke tail secara berurutan.

Dari percobaan yang dilakukan, dapat disimpulkan bahwa queue berperan penting dalam berbagai aplikasi yang membutuhkan pengolahan data secara teratur dan berurutan. Circular queue terbukti lebih efisien dalam penggunaan ruang, sedangkan linked list memberikan fleksibilitas ukuran tanpa batas. Pemahaman terhadap masing-masing metode membantu dalam menentukan implementasi queue yang tepat sesuai kebutuhan. Praktikum ini memberikan dasar pengetahuan yang kuat mengenai antrean dalam sistem komputer serta menjadi bekal untuk mempelajari struktur data yang lebih kompleks.

## Referensi  
[1]. Dicoding. (2023). **Struktur Data Queue: Pengertian, Fungsi, dan Jenisnya.**  
Artikel ini membahas pengertian queue, fungsi, cara kerja FIFO, serta berbagai jenis implementasinya dalam pemrograman.  
HTML: https://www.dicoding.com/blog/struktur-data-queue-pengertian-fungsi-dan-jenisnya/

[2]. Trivusi. (2022, Juli). **Struktur Data Queue.**  
Materi ini menjelaskan teori dasar queue, contoh penggunaan, kelebihan FIFO, serta penerapannya dalam algoritma dan kehidupan nyata.  
HTML: https://www.trivusi.web.id/2022/07/struktur-data-queue.html

