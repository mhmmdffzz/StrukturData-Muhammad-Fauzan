# <h1 align="center">Laporan Praktikum Modul 6 - Double Linked List (Bagian Pertama) </h1>
<p align="center">Muhammad Fauzan - 103112400064</p>

## Dasar Teori
### A. Konsep ADT List dan Double Linked List

Abstract Data Type (ADT) List merupakan representasi abstrak dari kumpulan elemen yang dapat dikelola melalui operasi tertentu tanpa memperhatikan detail implementasi penyimpanan datanya [1]. Salah satu implementasi dari ADT List adalah **Double Linked List (DLL)**, yaitu struktur data dinamis yang setiap node-nya memiliki dua pointer: `prev` yang menunjuk ke node sebelumnya dan `next` yang menunjuk ke node berikutnya. Dengan dua arah penunjuk ini, proses traversal menjadi lebih fleksibel dan memudahkan pengaksesan data baik dari awal maupun dari akhir list [2].

Struktur DLL terdiri dari tiga komponen utama pada setiap node, yaitu data, pointer ke node sebelum, dan pointer ke node setelahnya. Struktur ini memberikan efisiensi lebih tinggi terutama pada operasi penghapusan dan penyisipan di tengah list, karena tidak memerlukan pencarian node sebelumnya seperti pada *singly linked list* [3]. Dalam berbagai implementasi praktis, DLL juga sering digunakan untuk mendukung fitur-fitur seperti *undo-redo*, navigasi dua arah, dan pengelolaan data yang membutuhkan fleksibilitas tinggi [5].

---

### B. Operasi Dasar pada Double Linked List

Beberapa operasi penting pada Double Linked List meliputi:

1. **Insert** — Digunakan untuk menambahkan elemen di awal, akhir, atau di posisi tertentu dalam list. Penyisipan dilakukan dengan mengatur ulang pointer `prev` dan `next` pada node terkait agar tetap konsisten [2].  
2. **Delete** — Menghapus elemen tertentu dengan memutus hubungan node tersebut terhadap node sebelumnya dan berikutnya. Kesalahan dalam memperbarui pointer dapat menyebabkan *dangling pointer* atau kehilangan akses ke node tertentu [3].  
3. **Traversal** — Menelusuri elemen list dari depan ke belakang atau sebaliknya. Traversal dua arah menjadi salah satu keunggulan utama DLL dibandingkan *singly linked list* [1].

Dalam implementasi penghapusan, pointer `next` pada node sebelumnya dan pointer `prev` pada node setelahnya harus diperbarui secara tepat. Jika tidak, struktur list dapat rusak dan menyebabkan *memory leak* atau kehilangan referensi terhadap data [4]. Beberapa implementasi juga menggunakan *sentinel node* untuk menyederhanakan pemeriksaan kondisi awal atau akhir list.

---

### C. Kelebihan dan Kekurangan Double Linked List

**Kelebihan:**  
- Mendukung traversal dua arah yang mempermudah proses pengaksesan data.  
- Efisien untuk operasi penyisipan dan penghapusan di tengah list, karena tidak perlu mencari node sebelumnya [2].  
- Lebih fleksibel dalam berbagai manipulasi data dinamis.  

**Kekurangan:**  
- Membutuhkan memori lebih besar karena setiap node memiliki dua pointer.  
- Implementasinya lebih kompleks dibanding *singly linked list*.  
- Risiko *dangling pointer* lebih besar apabila pengelolaan pointer tidak dilakukan dengan benar [3].

---

### D. Penerapan Double Linked List dalam Dunia Nyata

Double Linked List banyak digunakan pada sistem yang membutuhkan navigasi dua arah atau perubahan data secara dinamis. Contohnya meliputi:  
- Sistem *undo/redo* pada aplikasi editor dokumen atau gambar.  
- Navigasi *forward-backward* pada web browser.  
- Struktur *playlist* musik yang memungkinkan perpindahan lagu ke depan dan belakang.  
- Pengelolaan data perpustakaan dan sistem antrian dinamis [5].

Dalam pembelajaran struktur data, DLL menjadi materi penting untuk memahami bagaimana data diatur secara dinamis dalam memori serta bagaimana pointer bekerja dalam menghubungkan antar-node [2][5].

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
![Output Program 1](https://github.com/mhmmdffzz/StrukturData-Muhammad-Fauzan/blob/main/Pertemuan6_Modul6/LAPRAK/Muhammad_Fauzan-Output-Unguided3.png)

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
[1]. Politeknik Elektronika Negeri Surabaya (PENS). (t.t.). **Single Linked List - Insert & Delete**. *Materi Struktur Data*.  
**PDF:** [Unduh](https://tita.lecturer.pens.ac.id/ASD/M4_SLL_Insert/Single%20Linked%20List%20INSERT%20%26%20DELETE.pdf)  
**Laman materi:** [PENS](https://tita.lecturer.pens.ac.id/ASD/M4_SLL_Insert/Single%20Linked%20List%20INSERT%20%26%20DELETE.pdf)  

[2]. Hasdyna, N., & Dinata, R. K. (2021). **Pembelajaran Struktur Data dalam Pemrograman C++**. Sefa Bumi Persada.  
**PDF:** [Unduh](https://repository.unimal.ac.id/6709/1/PEMBELAJARAN%20STRUKTUR%20DATA%20DALAM%20PEMROGRAMAN%20C%2B%2B.pdf)  
**Laman buku:** [Repository Unimal](https://repository.unimal.ac.id/6709/)  

[3]. Wijaya, H., Wardhono, W. S., & Arwani, I. (2018). **Implementasi Linked List pada Interaksi Antar Marker Augmented Reality untuk Operand dan Operator Aritmetika**. *Jurnal Pengembangan Teknologi Informasi dan Ilmu Komputer, 2*(9), 3328–3332.  
**PDF:** [Unduh](https://j-ptiik.ub.ac.id/index.php/j-ptiik/article/download/2261/840/16799)  
**Laman jurnal:** [J-PTIIK UB](https://j-ptiik.ub.ac.id/index.php/j-ptiik/article/view/2261)  

[4]. Ramadhan, H., Fauziah, & Lantana, D. A. (2023). **Perbandingan Algoritma Binary Search dan Sequential Search untuk Pencarian Persediaan Stok Barang Berbasis Web.** *STRING (Satuan Tulisan Riset dan Inovasi Teknologi)*, 8(2), 125–132.  
**PDF:** [Unduh](https://www.journal.lppmunindra.ac.id/index.php/STRING/article/download/16475/6178)  
**Laman jurnal:** [STRING Journal](https://www.journal.lppmunindra.ac.id/index.php/STRING/article/view/16475)  

[5]. Rosalia, N. (2020). **Implementasi Struktur Data Doubly Linked List pada Pengelolaan Data Buku Perpustakaan Menggunakan C++**. *Jurnal Teknologi dan Sistem Informasi, 6*(1), 45–52.  
**PDF:** [Unduh](https://ejournal.bsi.ac.id/ejurnal/index.php/teknosi/article/download/8431/5511)  
**Laman jurnal:** [Jurnal TeknoSI](https://ejournal.bsi.ac.id/ejurnal/index.php/teknosi/article/view/8431)  
