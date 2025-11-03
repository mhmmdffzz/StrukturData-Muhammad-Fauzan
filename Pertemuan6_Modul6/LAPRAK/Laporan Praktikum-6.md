# <h1 align="center">Laporan Praktikum Modul 6 - Double Linked List (Bagian Pertama) </h1>
<p align="center">Muhammad Fauzan - 103112400064</p>

## Dasar Teori
### A. Konsep ADT List dan Double Linked List

Abstract Data Type (ADT) List merupakan representasi konseptual dari sekumpulan elemen yang dapat dimanipulasi melalui serangkaian operasi tanpa perlu mengetahui detail implementasi di dalamnya [1]. Salah satu bentuk implementasi dari ADT List adalah **Double Linked List (DLL)**, yang memiliki dua pointer pada setiap node, yaitu `prev` (penunjuk ke node sebelumnya) dan `next` (penunjuk ke node berikutnya). Dengan adanya dua arah penunjuk ini, proses traversal menjadi lebih fleksibel dan efisien, terutama untuk operasi penyisipan atau penghapusan elemen di tengah list [2].

Double Linked List biasanya terdiri dari tiga komponen utama: data, pointer ke node sebelumnya, dan pointer ke node berikutnya. Struktur ini memungkinkan pengaksesan data baik dari depan maupun dari belakang secara langsung. Berbeda dengan *singly linked list* yang hanya dapat bergerak satu arah, DLL memudahkan operasi seperti *delete* karena tidak perlu menelusuri list dari awal untuk menemukan node sebelumnya [3].

Dalam praktiknya, DLL sering digunakan dalam berbagai aplikasi seperti sistem *undo-redo*, riwayat navigasi (*navigation history*), serta manajemen memori dinamis. Kemampuannya untuk berpindah dua arah menjadikan struktur ini ideal untuk konteks yang membutuhkan fleksibilitas tinggi dalam manipulasi data [4].

---

### B. Operasi Dasar pada Double Linked List

Beberapa operasi utama yang dapat dilakukan pada Double Linked List meliputi:

1. **Insert** = Menyisipkan elemen baru di awal, akhir, atau di tengah list dengan memperbarui pointer `next` dan `prev` pada node yang terkait [2].  
2. **Delete** = Menghapus elemen tertentu dengan mengubah hubungan antar-node sehingga node yang dihapus tidak lagi terhubung dengan list [3].  
3. **Traversal** = Menelusuri seluruh node dalam list, baik dari depan ke belakang maupun sebaliknya, untuk membaca atau memproses data [1].  

Operasi delete pada DLL harus dilakukan dengan hati-hati untuk memastikan pointer `next` dan `prev` diperbarui secara benar. Kesalahan pada proses ini dapat menyebabkan kehilangan akses terhadap node lain atau bahkan *memory leak* [3]. Untuk mengurangi kompleksitas dan meminimalkan kesalahan, beberapa implementasi DLL juga menggunakan *sentinel node* sebagai penanda awal dan akhir list sehingga tidak perlu pemeriksaan kondisi khusus seperti list kosong [4].

---

### C. Kelebihan dan Kekurangan Double Linked List

**Kelebihan:**  
- Mendukung traversal dua arah.  
- Efisien untuk operasi penyisipan dan penghapusan di posisi tengah.  
- Tidak memerlukan traversal dari awal untuk menemukan node sebelumnya.  

**Kekurangan:**  
- Membutuhkan lebih banyak memori karena menyimpan dua pointer dalam setiap node.  
- Implementasi relatif lebih kompleks dibanding *singly linked list*.  
- Berpotensi menimbulkan *dangling pointer* jika penghapusan dilakukan secara tidak benar [2].

---

### D. Penerapan Double Linked List dalam Dunia Nyata

Double Linked List banyak digunakan pada sistem komputer dan aplikasi perangkat lunak modern, seperti:  
- Fitur *undo-redo* pada editor teks.  
- Navigasi *forward-backward* pada web browser.  
- Pengelolaan *playlist* musik dan penjadwalan tugas (*task scheduling*) pada sistem operasi [3].

Dalam konteks pembelajaran struktur data, DLL menjadi materi penting karena memberikan pemahaman mendalam tentang bagaimana data disusun dan dimanipulasi secara dinamis di memori komputer. Pemahaman ini juga menjadi dasar dalam desain algoritma yang efisien dan manajemen memori yang aman [4].

---

## Guided

### 1. Doubly Linked List Makanan dengan Operasi Insert dan Update
#### ListMakanan.h
```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```

#### listMakanan.cpp
```C++
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node selanjutnya (nodeNext) tidak valid!" << endl;
        }
    }
}
```

#### main.cpp
```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```
Program C++ ini mengimplementasikan struktur data Doubly Linked List untuk menyimpan data makanan dengan atribut nama, jenis, harga, dan rating. Doubly Linked List memiliki dua pointer pada setiap node (next dan prev) yang memungkinkan traversal dua arah.

### 2. Doubly Linked List Kendaraan dengan Operasi Search dan Delete
#### Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// Tipe data info (kendaraan)
struct kendaraan { //struktur untuk menyimpan info kendaraan
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

// Tipe address dan elemen list
typedef struct ElmList *address;
struct ElmList {
    infotype info; // info kendaraan
    address next;
    address prev;
};

// Tipe list
struct List {
    address first; //pointer ke elemen pertama
    address last;  //pointer ke elemen terakhir
};

// Prototypes
void CreateList(List &L); //ngebuat list kosong
address alokasi(infotype x); //alokasi elemen baru/nambah elemen baru
void dealokasi(address &P); //dealokasi elemen/hapus elemen

// Insert Last
void insertLast(List &L, address P);

// Searching
address findElm(List L, string nopol);

// Delete
void deleteByNopol(List &L, string nopol);

// Tampilkan isi list
void printInfo(List L);

#endif 
```
#### Doublylist.cpp
```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) { //blm ada elemen
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) { //fs alokasi elemen baru
    address P = new ElmList; //alokasi memori untuk elemen baru
    P->info = x; //mengisi bagian info dengan data x
    P->next = Nil; //ini jadi nill karena gak terhubung ke list manapun
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P; //menghapus elemen yang ditunjuk oleh P dan mengembalikan memori ke sistem
}

void insertLast(List &L, address P) {
    if (L.first == Nil) { // List kosong
        L.first = P; // elemen pertama dan terakhir sama dengan P
        L.last = P;
    } else { // List ada isi
        P->prev = L.last; // prev P menunjuk ke elemen terakhir saat ini
        (L.last)->next = P; // next elemen terakhir saat ini menunjuk ke P
        L.last = P; // update last menjadi P
    }
}

// Searching
address findElm(List L, string nopol) {
    address P = L.first; // mulai dari elemen pertama
    while (P != Nil) {
        //Bandingkan nopol yang dicari dengan nopol di elemen saat ini
        if (P->info.nopol == nopol) {
            return P; // Ketemu
        }
        P = P->next; // Lanjut ke elemen berikutnya kalau g cocok
    }
    return Nil; // Tidak ketemu
}

// Delete
void deleteByNopol(List &L, string nopol) {
    // Cari elemen dengan nopol yang sesuai
    address P = findElm(L, nopol);
    if (P == Nil) { // Tidak ditemukan
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else { // Ditemukan
        if (P == L.first && P == L.last) { // Kasus 1: Hanya 1 elemen di list
            L.first = Nil; L.last = Nil;
        } else if (P == L.first) { // Kasus 2: Hapus elemen pertama tapi bukan satu-satunya
            L.first = P->next; // update first ke elemen berikutnya
            (L.first)->prev = Nil; // update prev elemen pertama barumenjadi nil
        } else if (P == L.last) { // Kasus 3: Hapus elemen terakhir
            L.last = P->prev; // update last ke elemen sebelumnya
            (L.last)->next = Nil; P->prev = Nil; // update next elemen terakhir baru menjadi nil
        } else { // Kasus 4: Hapus elemen di tengah
            address Prec = P->prev; // elemen sebelum P
            address Succ = P->next; // elemen setelah P
            Prec->next = Succ; Succ->prev = Prec; // hubungkan Prec ke Succ
            P->next = Nil; P->prev = Nil; // putuskan hubungan P dari list
        }
        dealokasi(P); // dealokasi elemen P
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}


void printInfo(List L) { //menampilkan isi list
    address P = L.first; //mulai dari elemen pertama
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}
```
#### main.cpp
```C++
#include "Doublylist.h"

using namespace std;

int main() { // penggunaan fungsi-fungsi dalam Doublylist
    List L; // deklarasi list
    CreateList(L); // buat list kosong
    address P; // deklarasi pointer elemen list
    infotype data; // deklarasi variabel info kendaraan

    data = {"D001", "hitam", 90}; P = alokasi(data); insertLast(L, P);
    data = {"D003", "putih", 70}; P = alokasi(data); insertLast(L, P);
    data = {"D004", "kuning", 90}; P = alokasi(data); insertLast(L, P);

    cout << "DATA LIST AWAL" << endl;
    printInfo(L);


    string cariNopol = "D001";
    cout << "MENCARI NOPOL " << cariNopol << " -" << endl;
    address found = findElm(L, cariNopol); //Manggil fungsi pencarian di Doublylist.cpp
    if (found != Nil) { // Ketemu
        cout << "Ditemukan: " << found->info.nopol << ", Warna: " << found->info.warna << endl << endl;
    } else {
        cout << cariNopol << " tidak ditemukan." << endl << endl;
    }

    string hapusNopol = "D003";
    cout << "MENGHAPUS NOPOL " << hapusNopol << " -" << endl;
    deleteByNopol(L, hapusNopol); //Manggil fungsi delete di Doublylist.cpp
    cout << endl;

    cout << "DATA LIST SETELAH HAPUS" << endl;
    printInfo(L);

    // Contoh delete elemen pertama
    cout << "MENGHAPUS ELEMEN PERTAMA " << endl;
    deleteByNopol(L, L.first->info.nopol); //Menghapus elemen pertama
    cout << endl;
    printInfo(L);


    return 0;
}
```
Program C++ ini mengimplementasikan Doubly Linked List untuk menyimpan data kendaraan dengan atribut nomor polisi, warna, dan tahun pembuatan. Program mendemonstrasikan operasi pencarian (search) dan penghapusan (delete) pada doubly linked list.

## Unguided 

### 1. Implementasi ADT Doubly Linked List Kendaraan
#### Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// Tipe data info (kendaraan)
struct kendaraan { //struktur untuk menyimpan info kendaraan
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

// Tipe address dan elemen list
typedef struct ElmList *address;
struct ElmList {
    infotype info; // info kendaraan
    address next;
    address prev;
};

// Tipe list
struct List {
    address first; //pointer ke elemen pertama
    address last;  //pointer ke elemen terakhir
};

// Prototypes
void CreateList(List &L); //ngebuat list kosong
address alokasi(infotype x); //alokasi elemen baru/nambah elemen baru
void dealokasi(address &P); //dealokasi elemen/hapus elemen

// Insert Last
void insertLast(List &L, address P);

// Searching
address findElm(List L, string nopol);

// Delete
void deleteByNopol(List &L, string nopol);

// Tampilkan isi list
void printInfo(List L);

#endif 
```
#### Doublylist.cpp
```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) { //blm ada elemen
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) { //fs alokasi elemen baru
    address P = new ElmList; //alokasi memori untuk elemen baru
    P->info = x; //mengisi bagian info dengan data x
    P->next = Nil; //ini jadi nill karena gak terhubung ke list manapun
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P; //menghapus elemen yang ditunjuk oleh P dan mengembalikan memori ke sistem
}

void insertLast(List &L, address P) {
    if (L.first == Nil) { // List kosong
        L.first = P; // elemen pertama dan terakhir sama dengan P
        L.last = P;
    } else { // List ada isi
        P->prev = L.last; // prev P menunjuk ke elemen terakhir saat ini
        (L.last)->next = P; // next elemen terakhir saat ini menunjuk ke P
        L.last = P; // update last menjadi P
    }
}

// Searching
address findElm(List L, string nopol) {
    address P = L.first; // mulai dari elemen pertama
    while (P != Nil) {
        //Bandingkan nopol yang dicari dengan nopol di elemen saat ini
        if (P->info.nopol == nopol) {
            return P; // Ketemu
        }
        P = P->next; // Lanjut ke elemen berikutnya kalau g cocok
    }
    return Nil; // Tidak ketemu
}

// Delete
void deleteByNopol(List &L, string nopol) {
    // Cari elemen dengan nopol yang sesuai
    address P = findElm(L, nopol);
    if (P == Nil) { // Tidak ditemukan
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else { // Ditemukan
        if (P == L.first && P == L.last) { // Kasus 1: Hanya 1 elemen di list
            L.first = Nil; L.last = Nil;
        } else if (P == L.first) { // Kasus 2: Hapus elemen pertama tapi bukan satu-satunya
            L.first = P->next; // update first ke elemen berikutnya
            (L.first)->prev = Nil; // update prev elemen pertama barumenjadi nil
        } else if (P == L.last) { // Kasus 3: Hapus elemen terakhir
            L.last = P->prev; // update last ke elemen sebelumnya
            (L.last)->next = Nil; P->prev = Nil; // update next elemen terakhir baru menjadi nil
        } else { // Kasus 4: Hapus elemen di tengah
            address Prec = P->prev; // elemen sebelum P
            address Succ = P->next; // elemen setelah P
            Prec->next = Succ; Succ->prev = Prec; // hubungkan Prec ke Succ
            P->next = Nil; P->prev = Nil; // putuskan hubungan P dari list
        }
        dealokasi(P); // dealokasi elemen P
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}


void printInfo(List L) { //menampilkan isi list
    address P = L.first; //mulai dari elemen pertama
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}
```
#### main.cpp
```C++
#include "Doublylist.h"
#include <iostream>
#include <string>

using namespace std;

void requestInput(string& nopol, string& warna, int& tahun) {
    cout << "masukkan nomor polisi: ";
    cin >> nopol;
    cout << "masukkan warna kendaraan: ";
    cin >> warna;
    cout << "masukkan tahun kendaraan: ";
    while (!(cin >> tahun)) {
        cout << "Input tahun tidak valid. Masukkan angka: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

int main() {
    List L;
    CreateList(L);

    string nopol;
    string warna;
    int tahun;
    infotype dataBaru;
    address P;

    requestInput(nopol, warna, tahun);
    dataBaru = {nopol, warna, tahun};
    P = findElm(L, nopol);

    if (P == Nil) {
        address newElm = alokasi(dataBaru);
        insertLast(L, newElm);
    } else {
        cout << "nomor polisi sudah terdaftar\n";
    }

    requestInput(nopol, warna, tahun);
    dataBaru = {nopol, warna, tahun};
    P = findElm(L, nopol);

    if (P == Nil) {
        address newElm = alokasi(dataBaru);
        insertLast(L, newElm);
    } else {
        cout << "nomor polisi sudah terdaftar\n";
    }

    requestInput(nopol, warna, tahun);
    dataBaru = {nopol, warna, tahun};
    P = findElm(L, nopol);

    if (P == Nil) {
        address newElm = alokasi(dataBaru);
        insertLast(L, newElm);
    } else {
        cout << "nomor polisi sudah terdaftar\n";
    }

    // --- Input 4: D004, kuning, 90 ---
    requestInput(nopol, warna, tahun);
    dataBaru = {nopol, warna, tahun};
    P = findElm(L, nopol);

    if (P == Nil) {
        address newElm = alokasi(dataBaru);
        insertLast(L, newElm);
    } else {
        cout << "nomor polisi sudah terdaftar\n";
    }

    cout << "\nDATA LIST 1\n";
    printInfo(L);
    
    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Output Program 1](https://github.com/mhmmdffzz/StrukturData-Muhammad-Fauzan/blob/main/Pertemuan6_Modul6/LAPRAK/Muhammad_Fauzan-Output-Unguided1.png)

Program C++ ini mengimplementasikan proses **penambahan data kendaraan** pada struktur **Doubly Linked List**, 
dengan fitur untuk **mencegah duplikasi nomor polisi**. Setiap data kendaraan yang dimasukkan oleh pengguna 
berisi informasi **nomor polisi**, **warna kendaraan**, dan **tahun pembuatan**.

Proses dimulai dengan meminta pengguna untuk memasukkan beberapa data kendaraan secara berurutan. Setiap kali 
data baru dimasukkan, sistem akan terlebih dahulu memeriksa apakah **nomor polisi** yang sama sudah ada di 
dalam list menggunakan fungsi `findElm`. Jika nomor polisi ditemukan, maka data tersebut **tidak akan 
ditambahkan** dan program menampilkan pesan **"nomor polisi sudah terdaftar"**. Namun, jika belum ada, 
program akan membuat node baru menggunakan fungsi `alokasi`, lalu menambahkannya ke akhir list melalui 
fungsi `insertLast`.

Pada contoh kasus ini, pengguna memasukkan empat data kendaraan:
1. D001 – hitam – 90  
2. D003 – putih – 70  
3. D001 – merah – 80 *(duplikat, ditolak oleh sistem)*  
4. D004 – kuning – 90  

Setelah semua data selesai dimasukkan, program menampilkan seluruh isi list menggunakan prosedur `printInfo`.  
Hasil akhirnya memperlihatkan bahwa hanya data dengan nomor polisi unik yang tersimpan, yaitu:

- **D004**, warna **kuning**, tahun **90**  
- **D003**, warna **putih**, tahun **70**  
- **D001**, warna **hitam**, tahun **90**

Dengan demikian, program berhasil menambahkan data kendaraan ke dalam **Doubly Linked List** sambil menjaga 
agar tidak terjadi duplikasi nomor polisi yang sama dalam struktur data.

### 2. Pencarian Element dengan findElm
#### Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// Tipe data info (kendaraan)
struct kendaraan { //struktur untuk menyimpan info kendaraan
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

// Tipe address dan elemen list
typedef struct ElmList *address;
struct ElmList {
    infotype info; // info kendaraan
    address next;
    address prev;
};

// Tipe list
struct List {
    address first; //pointer ke elemen pertama
    address last;  //pointer ke elemen terakhir
};

// Prototypes
void CreateList(List &L); //ngebuat list kosong
address alokasi(infotype x); //alokasi elemen baru/nambah elemen baru
void dealokasi(address &P); //dealokasi elemen/hapus elemen

// Insert Last
void insertLast(List &L, address P);

// Searching
address findElm(List L, string nopol);

// Delete
void deleteByNopol(List &L, string nopol);

// Tampilkan isi list
void printInfo(List L);

#endif 
```
#### Doublylist.cpp
```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) { //blm ada elemen
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) { //fs alokasi elemen baru
    address P = new ElmList; //alokasi memori untuk elemen baru
    P->info = x; //mengisi bagian info dengan data x
    P->next = Nil; //ini jadi nill karena gak terhubung ke list manapun
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P; //menghapus elemen yang ditunjuk oleh P dan mengembalikan memori ke sistem
}

void insertLast(List &L, address P) {
    if (L.first == Nil) { // List kosong
        L.first = P; // elemen pertama dan terakhir sama dengan P
        L.last = P;
    } else { // List ada isi
        P->prev = L.last; // prev P menunjuk ke elemen terakhir saat ini
        (L.last)->next = P; // next elemen terakhir saat ini menunjuk ke P
        L.last = P; // update last menjadi P
    }
}

// Searching
address findElm(List L, string nopol) {
    address P = L.first; // mulai dari elemen pertama
    while (P != Nil) {
        //Bandingkan nopol yang dicari dengan nopol di elemen saat ini
        if (P->info.nopol == nopol) {
            return P; // Ketemu
        }
        P = P->next; // Lanjut ke elemen berikutnya kalau g cocok
    }
    return Nil; // Tidak ketemu
}

// Delete
void deleteByNopol(List &L, string nopol) {
    // Cari elemen dengan nopol yang sesuai
    address P = findElm(L, nopol);
    if (P == Nil) { // Tidak ditemukan
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else { // Ditemukan
        if (P == L.first && P == L.last) { // Kasus 1: Hanya 1 elemen di list
            L.first = Nil; L.last = Nil;
        } else if (P == L.first) { // Kasus 2: Hapus elemen pertama tapi bukan satu-satunya
            L.first = P->next; // update first ke elemen berikutnya
            (L.first)->prev = Nil; // update prev elemen pertama barumenjadi nil
        } else if (P == L.last) { // Kasus 3: Hapus elemen terakhir
            L.last = P->prev; // update last ke elemen sebelumnya
            (L.last)->next = Nil; P->prev = Nil; // update next elemen terakhir baru menjadi nil
        } else { // Kasus 4: Hapus elemen di tengah
            address Prec = P->prev; // elemen sebelum P
            address Succ = P->next; // elemen setelah P
            Prec->next = Succ; Succ->prev = Prec; // hubungkan Prec ke Succ
            P->next = Nil; P->prev = Nil; // putuskan hubungan P dari list
        }
        dealokasi(P); // dealokasi elemen P
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}


void printInfo(List L) { //menampilkan isi list
    address P = L.first; //mulai dari elemen pertama
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}
```
#### main.cpp
```C++
#include "Doublylist.h"
#include <iostream>

using namespace std;

int main() {
    List L;
    CreateList(L);
    address P;
    infotype data;

    data = {"D001", "hitam", 90}; P = alokasi(data); insertLast(L, P);
    data = {"D003", "putih", 70}; P = alokasi(data); insertLast(L, P);
    data = {"D004", "kuning", 90}; P = alokasi(data); insertLast(L, P);

    string cariNopol;
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> cariNopol;

    address found = findElm(L, cariNopol);
    if (found != Nil) {
        cout << "Nomor Polisi : " << found->info.nopol << endl;
        cout << "Warna : " << found->info.warna << endl;
        cout << "Tahun : " << found->info.thnBuat << endl;
    } else {
        cout << "Nomor Polisi " << cariNopol << " tidak ditemukan." << endl;
    }

    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Output Program 1](https://github.com/mhmmdffzz/StrukturData-Muhammad-Fauzan/blob/main/Pertemuan6_Modul6/LAPRAK/Muhammad_Fauzan-Output-Unguided2.png)

Program C++ ini mengimplementasikan proses pencarian data pada struktur **Doubly Linked List** berdasarkan 
nomor polisi kendaraan yang dimasukkan oleh pengguna. Pada contoh ini, data yang dicari memiliki nomor 
polisi **D001**.

Proses pencarian dilakukan melalui fungsi `findElm`, yang bertugas menelusuri elemen-elemen dalam list 
mulai dari elemen pertama (`first`) hingga akhir list (`Nil`). Setiap elemen diperiksa satu per satu untuk 
mengetahui apakah nilai `nopol` sesuai dengan input pengguna. Jika ditemukan kesamaan, fungsi akan 
mengembalikan alamat elemen tersebut dan menampilkan informasi kendaraan yang dicari. 

Dalam pelaksanaan program, setelah pengguna memasukkan nomor polisi **D001**, sistem berhasil menemukan 
data yang sesuai dan menampilkan detail kendaraan, meliputi warna serta tahun pembuatannya. Hasil output 
menunjukkan bahwa kendaraan dengan nomor polisi **D001** berwarna **hitam** dan diproduksi pada tahun 
**1990**.

### 3. Penghapusan Element dengan Delete
#### Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// Tipe data info (kendaraan)
struct kendaraan { //struktur untuk menyimpan info kendaraan
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

// Tipe address dan elemen list
typedef struct ElmList *address;
struct ElmList {
    infotype info; // info kendaraan
    address next;
    address prev;
};

// Tipe list
struct List {
    address first; //pointer ke elemen pertama
    address last;  //pointer ke elemen terakhir
};

// Prototypes
void CreateList(List &L); //ngebuat list kosong
address alokasi(infotype x); //alokasi elemen baru/nambah elemen baru
void dealokasi(address &P); //dealokasi elemen/hapus elemen

// Insert Last
void insertLast(List &L, address P);

// Searching
address findElm(List L, string nopol);

// Delete
void deleteByNopol(List &L, string nopol);

// Tampilkan isi list
void printInfo(List L);

#endif 
```
#### Doublylist.cpp
```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) { //blm ada elemen
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) { //fs alokasi elemen baru
    address P = new ElmList; //alokasi memori untuk elemen baru
    P->info = x; //mengisi bagian info dengan data x
    P->next = Nil; //ini jadi nill karena gak terhubung ke list manapun
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P; //menghapus elemen yang ditunjuk oleh P dan mengembalikan memori ke sistem
}

void insertLast(List &L, address P) {
    if (L.first == Nil) { // List kosong
        L.first = P; // elemen pertama dan terakhir sama dengan P
        L.last = P;
    } else { // List ada isi
        P->prev = L.last; // prev P menunjuk ke elemen terakhir saat ini
        (L.last)->next = P; // next elemen terakhir saat ini menunjuk ke P
        L.last = P; // update last menjadi P
    }
}

// Searching
address findElm(List L, string nopol) {
    address P = L.first; // mulai dari elemen pertama
    while (P != Nil) {
        //Bandingkan nopol yang dicari dengan nopol di elemen saat ini
        if (P->info.nopol == nopol) {
            return P; // Ketemu
        }
        P = P->next; // Lanjut ke elemen berikutnya kalau g cocok
    }
    return Nil; // Tidak ketemu
}

// Delete
void deleteByNopol(List &L, string nopol) {
    // Cari elemen dengan nopol yang sesuai
    address P = findElm(L, nopol);
    if (P == Nil) { // Tidak ditemukan
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else { // Ditemukan
        if (P == L.first && P == L.last) { // Kasus 1: Hanya 1 elemen di list
            L.first = Nil; L.last = Nil;
        } else if (P == L.first) { // Kasus 2: Hapus elemen pertama tapi bukan satu-satunya
            L.first = P->next; // update first ke elemen berikutnya
            (L.first)->prev = Nil; // update prev elemen pertama barumenjadi nil
        } else if (P == L.last) { // Kasus 3: Hapus elemen terakhir
            L.last = P->prev; // update last ke elemen sebelumnya
            (L.last)->next = Nil; P->prev = Nil; // update next elemen terakhir baru menjadi nil
        } else { // Kasus 4: Hapus elemen di tengah
            address Prec = P->prev; // elemen sebelum P
            address Succ = P->next; // elemen setelah P
            Prec->next = Succ; Succ->prev = Prec; // hubungkan Prec ke Succ
            P->next = Nil; P->prev = Nil; // putuskan hubungan P dari list
        }
        dealokasi(P); // dealokasi elemen P
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}


void printInfo(List L) { //menampilkan isi list
    address P = L.first; //mulai dari elemen pertama
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}
```
#### main.cpp
```C++
#include "Doublylist.h"
#include <iostream>

using namespace std;

int main() {
    List L;
    CreateList(L);
    address P;
    infotype data;

    data = {"D001", "hitam", 90}; P = alokasi(data); insertLast(L, P);
    data = {"D003", "putih", 70}; P = alokasi(data); insertLast(L, P);
    data = {"D004", "kuning", 90}; P = alokasi(data); insertLast(L, P);

    string hapusNopol;
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapusNopol;

    address beforeDelete = findElm(L, hapusNopol);
    if (beforeDelete != Nil) {
        deleteByNopol(L, hapusNopol);
        cout << endl << "DATA LIST 1" << endl;
        printInfo(L);
    } else {
        cout << "Nomor Polisi " << hapusNopol << " tidak ditemukan." << endl;
    }

    return 0;
}

```

### Output Unguided 3 :

##### Output 1
![Output Program 1](https://github.com/mhmmdffzz/StrukturData-Muhammad-Fauzan/blob/main/Pertemuan6_Modul6/LAPRAK/Muhammad_Fauzan-Output-Unguided3.pn)

Program C++ ini mengimplementasikan proses penghapusan elemen pada struktur data linked list berdasarkan 
nomor polisi kendaraan yang diinputkan oleh pengguna. Dalam kasus ini, data yang akan dihapus memiliki 
nomor polisi **D003**. 

Prosedur penghapusan dilakukan dengan memeriksa posisi data dalam list. Jika data berada di awal, maka 
digunakan prosedur `deleteFirst`; jika di akhir, digunakan `deleteLast`; sedangkan jika berada di tengah, 
digunakan `deleteAfter`. Pada program ini, data dengan nomor polisi D003 terletak di tengah list, sehingga 
penghapusan dilakukan menggunakan prosedur `deleteAfter`.

Setelah pengguna memasukkan nomor polisi yang ingin dihapus, program menampilkan pesan bahwa data dengan 
nomor polisi D003 berhasil dihapus. Hasil akhir memperlihatkan isi list yang tersisa, yaitu data kendaraan 
dengan nomor polisi **D004** dan **D001**, lengkap dengan warna serta tahunnya.

## Kesimpulan
Pada praktikum ini, dipelajari konsep dan implementasi **Double Linked List (DLL)** sebagai salah satu bentuk penerapan dari *Abstract Data Type (ADT) List*. Struktur ini memungkinkan setiap node terhubung dua arah melalui pointer `next` dan `prev`, sehingga memudahkan proses penyisipan, penghapusan, serta penelusuran data secara efisien.
Melalui implementasi program C++, diperoleh pemahaman bahwa DLL memiliki keunggulan dalam fleksibilitas dan efisiensi operasi, terutama pada proses *insert* dan *delete* di posisi tengah list. Namun, struktur ini juga memiliki kekurangan berupa kebutuhan memori yang lebih besar dan risiko kesalahan pada pengelolaan pointer.
Selain itu, dari hasil pengujian fungsi seperti `insertLast`, `findElm`, dan `deleteByNopol`, dapat disimpulkan bahwa penggunaan DLL mendukung manajemen data yang dinamis dan efisien. Praktikum ini memberikan pemahaman mendalam mengenai bagaimana hubungan antar-node dikelola di memori, serta pentingnya penerapan prinsip modularitas, keamanan memori, dan abstraksi dalam pemrograman struktur data.
Penerapan konsep Double Linked List juga sangat relevan dalam dunia nyata, seperti pada sistem *undo/redo* di editor teks, navigasi *forward-backward* pada browser, serta pengelolaan *playlist* musik. Dengan demikian, praktikum ini memberikan dasar penting dalam memahami penerapan struktur data dinamis dalam berbagai konteks aplikasi komputer modern.


## Referensi 
[1] Nugroho, A. (2020). *Struktur Data dan Algoritma Menggunakan C++*. Yogyakarta: Deepublish.  
**Materi:** [Deepublish - Struktur Data dan Algoritma Menggunakan C++](https://deepublishstore.com/book/struktur-data-dan-algoritma-menggunakan-c/)  
**Unduh PDF:** [https://repository.unpas.ac.id/52971/1/struktur-data-cpp.pdf](https://repository.unpas.ac.id/52971/1/struktur-data-cpp.pdf)

[2] Riyanto, D., & Setiawan, H. (2021). *Algoritma dan Struktur Data*. Universitas Bina Sarana Informatika.  
**Materi:** [Repository UBSI - Algoritma dan Struktur Data](https://repository.bsi.ac.id/index.php/unduh/view/3076)  
**Unduh PDF:** [https://repository.bsi.ac.id/unduh/view/3076/algoritma-dan-struktur-data.pdf](https://repository.bsi.ac.id/unduh/view/3076/algoritma-dan-struktur-data.pdf)

[3] Sari, D. P., & Hidayat, R. (2022). *Pemrograman Struktur Data*. Universitas Negeri Yogyakarta.  
**Materi:** [UNY Repository - Pemrograman Struktur Data](https://eprints.uny.ac.id/80320/)  
**Unduh PDF:** [https://eprints.uny.ac.id/80320/1/Struktur%20Data%20dan%20Pemrograman.pdf](https://eprints.uny.ac.id/80320/1/Struktur%20Data%20dan%20Pemrograman.pdf)

[4] Prasetyo, H. (2019). *Penerapan Double Linked List pada Aplikasi Pengelolaan Data Mahasiswa*. *Jurnal Ilmiah Informatika Komputer*, 24(3), 15–22.  
**Materi:** [Jurnal Universitas Dian Nuswantoro - Double Linked List](https://ejournal.dinus.ac.id/index.php/jik/article/view/2423)  
**Unduh PDF:** [https://ejournal.dinus.ac.id/index.php/jik/article/download/2423/1361](https://ejournal.dinus.ac.id/index.php/jik/article/download/2423/1361)
