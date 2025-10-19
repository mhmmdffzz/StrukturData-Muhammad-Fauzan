# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama) </h1>
<p align="center">Muhammad Fauzan - 103112400064</p>

## Dasar Teori

### A. Konsep ADT List dan Singly Linked List <br/>
Abstract Data Type (ADT) List mendeskripsikan himpunan nilai beserta operasi tanpa mengekspos detail implementasi. Pada singly linked list, struktur direpresentasikan sebagai rangkaian simpul yang terhubung satu arah melalui pointer `next`. Operasi dasar yang relevan dengan kode adalah pembuatan list, penyisipan di awal/tengah/akhir (`insertFirst`, `insertAfter`, `insertLast`), penghapusan di awal/tengah/akhir (`delFirst`, `delAfter`, `delLast`), traversal untuk menampilkan isi (`printList`) dan menghitung jumlah simpul (`nbList`). Kepala list (head) direpresentasikan oleh pointer `first` yang menunjuk simpul pertama atau `NULL` jika kosong [1].

### B. Node, Pointer, dan Representasi Struktur <br/>
Setiap simpul (node) menyimpan data dan pointer `next` ke simpul berikutnya. Pada C++, node umum didefinisikan dengan `struct` berisi bidang data dan pointer, misalnya:
```cpp
struct node { dataMahasiswa isidata; address next; };
```
List kosong diinisialisasi dengan `first = NULL`. Karena alokasi bersifat dinamis, simpul tidak harus kontigu di memori; keterurutan dijaga oleh pointer `next` [2].

### C. Operasi Dasar dan Penanganan Kasus Batas <br/>
**Penyisipan**  
1) Awal: set `nodeBaru->next = first`, lalu `first = nodeBaru`.  
2) Setelah simpul tertentu: validasi `Prev != NULL`, set `nodeBaru->next = Prev->next`, lalu `Prev->next = nodeBaru`.  
3) Akhir: bila kosong, `first = nodeBaru`; bila tidak, telusuri hingga `next == NULL` lalu tautkan.

**Penghapusan**  
1) Awal: simpan `first` ke penampung, geser `first = first->next`, putuskan `next` simpul yang dihapus, lalu dealokasi.  
2) Setelah simpul tertentu: validasi `Prev` dan `Prev->next`, putuskan tautan, lalu dealokasi.  
3) Akhir: telusuri dengan penunjuk previous untuk memutus simpul terakhir.

Kasus batas penting: list kosong, list berisi satu simpul, serta validasi argumen `Prev` [3].

### D. Kompleksitas dan Perbandingan dengan Array <br/>
Pada singly linked list, insert/delete di awal berbiaya O(1), sedangkan operasi yang memerlukan penelusuran posisi (misalnya menuju simpul terakhir atau mencari kunci tertentu) berbiaya O(n). Dibanding array, linked list unggul untuk operasi sisip/hapus yang sering karena tidak perlu shifting, tetapi memiliki biaya akses acak O(n) dan overhead pointer [1].

### E. Modularitas, Manajemen Memori, dan Keamanan <br/>
Pemisahan berkas header (.h) dan implementasi (.cpp) menjaga batas antarmuka, memudahkan pengujian, serta pemeliharaan. Di C++, simpul dialokasikan dengan `new` dan dibebaskan dengan `delete`. Memutus pointer (`node->next = NULL`) sebelum `delete` membantu mencegah dangling pointer. Prosedur seperti `deleteList` melakukan iterasi dan dealokasi seluruh simpul untuk mencegah memory leak. Pada variasi implementasi, kepala list bisa berupa field `first` di dalam `struct linkedlist` atau pointer global `head`, keduanya sah asalkan konsisten [1].
    
## Guided

### 1. Implementasi Singly Linked List pada Data Mahasiswa
#### list.h
```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif // LIST_H

```

#### list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}  
```

#### Main.cpp
```C++
#include "list.h"
#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
Program C++ ini menggunakan struktur `singly linked list` untuk mengelola data mahasiswa. Implementasinya dibagi menjadi tiga file: `list.h` sebagai header yang mendefinisikan struktur `mahasiswa`, `node`, dan `linkedlist` beserta prototipe fungsi; `list.cpp` yang berisi implementasi detail dari fungsi-fungsi tersebut seperti `alokasi`, `insertFirst`, `insertLast`, `insertAfter`, dan `printList`; serta `main.cpp` yang menjadi program utama untuk membuat list, menambahkan data mahasiswa, dan menampilkannya. Program ini mendemonstrasikan operasi dasar penyisipan pada `singly linked list`.

### 2. Operasi Tambahan pada Singly Linked List Mahasiswa
#### list.h
```C++
// list.h

//Header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif

```

#### list.cpp
```C++
// list.cpp
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {

    List.first = Nil;
}

//pembuatan node baru
address alokasi(string nama, string nim, int umur) { 

    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {

    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {

    if (Prev != Nil) { //Previous (sebelumnya) tidak boleh NULL
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {

    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){

    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){

    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){

    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {

    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {

    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){

    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}  
```

#### Main.cpp
```C++
// main.cpp

#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;
    return 0;
}
```
Program C++ ini merupakan pengembangan dari program sebelumnya dengan menambahkan operasi penghapusan pada `singly linked list` data mahasiswa. Selain fungsi-fungsi yang sudah ada, ditambahkan fungsi `delFirst`, `delLast`, `delAfter` untuk menghapus node dari awal, akhir, dan setelah node tertentu. Terdapat juga fungsi `nbList` untuk menghitung jumlah node dan `deleteList` untuk menghapus keseluruhan list. Program utama di `main.cpp` menunjukkan alur lengkap mulai dari pembuatan list, penambahan data, penampilan data, penghapusan beberapa data, hingga penghapusan seluruh list, sambil menampilkan jumlah node setelah setiap operasi.

## Unguided 

### 1. Implementasi Singly Linked List Sederhana
#### Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>

// Definisikan struktur Node
struct Node {
    int data;
    Node* next;
};

// Deklarasikan pointer head global
extern Node* head;

// Prototype fungsi
void init();
bool isEmpty();
void insertFirst(int value);
void insertLast(int value);
void insertAfter(int value, int key);
void deleteFirst();
void deleteLast();
void deleteAfter(int key);
void printList();
int nbList();
void deleteList();

#endif // SINGLYLIST_H
```

#### Singlylist.cpp
```C++
#include "Singlylist.h"

Node* head;

void init() {
    head = nullptr;
}

bool isEmpty() {
    return head == nullptr;
}

void insertFirst(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertLast(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (isEmpty()) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAfter(int value, int key) {
    Node* newNode = new Node();
    newNode->data = value;
    Node* temp = head;
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }
    if (temp != nullptr) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteFirst() {
    if (!isEmpty()) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteLast() {
    if (!isEmpty()) {
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
    }
}

void deleteAfter(int key) {
    Node* temp = head;
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }
    if (temp != nullptr && temp->next != nullptr) {
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }
}

void printList() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int nbList() {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void deleteList() {
    while (!isEmpty()) {
        deleteFirst();
    }
}
```

#### main.cpp
```C++
#include "Singlylist.h"

int main() {
    init();

    // Soal 1
    std::cout << "Soal 1:" << std::endl;
    insertFirst(9);
    insertLast(12);
    insertLast(2);
    insertAfter(8, 12);
    insertAfter(0, 8);
    printList();

    // Soal 2
    std::cout << "\nSoal 2:" << std::endl;
    deleteFirst();
    deleteLast();
    deleteAfter(12);
    printList();
    std::cout << "Jumlah node : " << nbList() << std::endl;
    deleteList();
    std::cout << "- List Berhasil Terhapus -" << std::endl;
    std::cout << "Jumlah node : " << nbList() << std::endl;

    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Output Program 1](https://github.com/mhmmdffzz/StrukturData-Muhammad-Fauzan/blob/main/Pertemuan4_Modul4/LAPRAK/Muhammad_Fauzan-Output-Unguided1.png)

Program C++ ini mengimplementasikan `singly linked list` sederhana untuk menyimpan data integer. Berbeda dengan contoh sebelumnya, program ini menggunakan pointer global `head` untuk mengelola list. File `Singlylist.h` berisi definisi struktur `Node` dan prototipe fungsi, sedangkan `Singlylist.cpp` berisi implementasi fungsi-fungsi seperti `init`, `isEmpty`, `insertFirst`, `insertLast`, `insertAfter`, `deleteFirst`, `deleteLast`, `deleteAfter`, `printList`, `nbList`, dan `deleteList`. Program utama di `main.cpp` mendemonstrasikan penggunaan fungsi-fungsi tersebut untuk melakukan operasi penyisipan dan penghapusan pada list, serta menampilkan hasilnya sesuai dengan skenario soal.

## Kesimpulan
Pada praktikum modul 4 ini, dipelajari konsep dan implementasi `Singly Linked List` sebagai salah satu struktur data dinamis. Melalui latihan `guided` dan `unguided`, telah dipraktikkan operasi-operasi fundamental pada `linked list`, seperti inisialisasi, penyisipan (di awal, tengah, dan akhir), penghapusan (di awal, tengah, dan akhir), serta traversal untuk menampilkan data dan menghitung jumlah node. Implementasi yang modular dengan memisahkan file header (`.h`) dan file source (`.cpp`) juga diterapkan untuk meningkatkan keterbacaan dan pemeliharaan kode. Praktikum ini memberikan pemahaman yang kuat tentang bagaimana `linked list` bekerja, manajemen memori dinamis menggunakan `new` dan `delete`, serta keunggulannya dalam hal fleksibilitas ukuran dibandingkan dengan struktur data statis seperti array.

## Referensi 
[1]. Politeknik Elektronika Negeri Surabaya (PENS). (t.t.). **Single Linked List - Insert & Delete**. *Materi Struktur Data*.  
**PDF:** [Unduh](https://tita.lecturer.pens.ac.id/ASD/M4_SLL_Insert/Single%20Linked%20List%20INSERT%20%26%20DELETE.pdf)  **Laman materi:** [PENS](https://tita.lecturer.pens.ac.id/ASD/M4_SLL_Insert/Single%20Linked%20List%20INSERT%20%26%20DELETE.pdf)

[2]. Hasdyna, N., & Dinata, R. K. (2021). **Pembelajaran Struktur Data dalam Pemrograman C++**. Sefa Bumi Persada.  
**PDF:** [Unduh](https://repository.unimal.ac.id/6709/1/PEMBELAJARAN%20STRUKTUR%20DATA%20DALAM%20PEMROGRAMAN%20C%2B%2B.pdf)  **Laman buku:** [Repository Unimal](https://repository.unimal.ac.id/6709/)

[3]. Wijaya, H., Wardhono, W. S., & Arwani, I. (2018). **Implementasi Linked List pada Interaksi Antar Marker Augmented Reality untuk Operand dan Operator Aritmetika**. *Jurnal Pengembangan Teknologi Informasi dan Ilmu Komputer, 2*(9), 3328-3332).  
**PDF:** [Unduh](https://j-ptiik.ub.ac.id/index.php/j-ptiik/article/download/2261/840/16799)  **Laman jurnal:** [J-PTIIK UB](https://j-ptiik.ub.ac.id/index.php/j-ptiik/article/view/2261)
