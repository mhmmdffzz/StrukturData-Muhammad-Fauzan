# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua) </h1>
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

## F. Algoritma Pencarian (Linear dan Binary Search) <br/>
Pencarian data merupakan salah satu operasi dasar dalam struktur data yang digunakan untuk menemukan elemen tertentu di dalam kumpulan data. Dua algoritma pencarian yang umum digunakan adalah *Sequential Search* dan *Binary Search*. Sequential Search atau pencarian linear bekerja dengan cara membandingkan setiap elemen satu per satu hingga ditemukan data yang dicari atau sampai seluruh elemen diperiksa. Metode ini sederhana namun kurang efisien untuk data besar. Sementara itu, Binary Search hanya dapat diterapkan pada data yang sudah terurut, dengan membagi data menjadi dua bagian dan membandingkan elemen tengah dengan nilai yang dicari. Jika nilai yang dicari lebih kecil, maka pencarian dilanjutkan ke bagian kiri; jika lebih besar, maka ke bagian kanan. Pendekatan ini jauh lebih efisien karena mengurangi jumlah perbandingan secara logaritmik [4].
    
## Guided

### 1. Linked List Buah dengan Operasi Insert dan Update
#### listbuah.h
```C++
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah; //memberikan nammamalias databuah untuk struct  buah

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct 

struct node{  //node untuk isi dari linked listnya, isi setiap node adalah data dan pointer
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked listnya 
    address first;
};

//semua function dan prosedur yang akan dipakai
//materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
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

//materi modul 5 (part 1 -update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

#endif

```

#### listbuah.cpp
```C++
#include "listbuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if (List.first == Nil) {
        return true;
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah;
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
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
    if (Prev != Nil) {
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
void delFirst(linkedlist &List) {
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List) {
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil) {
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else {
            while (nodeHapus->next != Nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
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
            cout << "Nama Buah : " << nodeBantu->isidata.nama
                 << ", Jumlah : " << nodeBantu->isidata.jumlah
                 << ", Harga : " << nodeBantu->isidata.harga << endl;
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
void deleteList(linkedlist &List) {
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            address nodeBantu = nodePrev->next;
            cout << "Masukkan update data node setelah node "
                 << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

```

#### main.cpp
```C++
#include "listBuah.h"

#include <iostream>
using namespace std;

int main() {
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout <<"--- ISI LIST SETELAH DILAKUKAN INSERT---" << endl;
    printList(List);
    cout <<"jumlah node:" << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout <<"--- ISI LIST SETELAH DILAKUKAN UPDATE---" << endl;
    printList(List);
    cout << "jumlah node:" << nbList(List) << endl;
    cout << endl;

    return 0;


}
```
Program C++ ini mengimplementasikan Single Linked List untuk data buah dengan operasi insert (insertFirst, insertLast, insertAfter) dan update (updateFirst, updateLast, updateAfter).

### 2. Linear & Binary Search pada Linked List
#### linear.cpp
```C++
#include <iostream>
using namespace std;

//Definisi node untuk linked list
struct Node { 
    int data;      // Menyimpan nilai data
    Node* next;    // Pointer ke node selanjutnya
};

// Fungsi linear search untuk mencari nilai dalam linked list
// Parameter: head (pointer awal list), key (nilai yang dicari)
// Return: pointer ke node jika ditemukan, nullptr jika tidak
Node* linearSearch(Node* head, int key) {
    Node* current = head;              // Mulai dari node pertama
    while (current != nullptr) {       // Traverse seluruh list
        if (current->data == key) {    // Jika data ditemukan
            return current;            // Kembalikan pointer node tersebut
        }
        current = current->next;       // Pindah ke node berikutnya
    }
    return nullptr;                    // Tidak ditemukan, return nullptr
}

// Fungsi untuk menambahkan node baru di akhir list
void append(Node* &head, int value){
    Node *newNode = new Node{value, nullptr};
    if(!head) head = newNode;
    else{
        Node *temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;  // Inisialisasi linked list kosong

    // Menambahkan beberapa elemen ke linked list
    append(head, 10);
    append(head, 20);
    append(head, 30);
    
    Node* result = linearSearch(head, 20); // Panggil fungsi linear search

  cout << (result ? "Found" : "Not Found") << endl; // Tampilkan hasil pencarian

    return 0;
}

```
Program C++ ini menggunakan struktur *Singly Linked List* untuk mengimplementasikan algoritma *Linear Search* dalam pencarian data. Fungsi `append()` menambah node baru di akhir list, sedangkan `linearSearch()` menelusuri setiap node dari awal hingga akhir untuk menemukan nilai yang dicari. Jika nilai ditemukan, program menampilkan pesan “Found”, dan jika tidak ditemukan maka menampilkan “Not Found”.

#### binary.cpp
```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node* & head, int value) {
    Node* newNode = new Node {value,nullptr};
    
    if(!head) head = newNode;

    else {
        Node* temp = head;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
};

Node* binarySearch(Node* head, int key) {
    int size = 0;
    for (Node* current = head; current; current = current -> next) size++;
    Node *start = head;
    Node *end = nullptr;

    while (size > 0) {
        int mid = size / 2;
        Node* midNode = start;
        for (int i = 0; i < mid; i++) {
            midNode = midNode -> next;
        }

        if (midNode -> data == key ) return midNode;
        if (midNode -> data < key) {
            start = midNode -> next;
    }
    else {
        end = midNode;
    }
    size -= mid;
}
return nullptr;
}
int main(){
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    
    Node* result = binarySearch(head, 10);
    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}
```
Program C++ ini mengimplementasikan algoritma *Binary Search* untuk mencari data dalam array yang sudah terurut. Proses pencarian dilakukan dengan membagi dua rentang data secara berulang: jika nilai tengah lebih kecil dari target maka pencarian dilanjutkan ke kanan, dan sebaliknya ke kiri. Program menampilkan hasil “Found” bila data ditemukan dan “Not Found” jika tidak ada.

## Unguided 

### 1. Binary Search pada Linked List
```C++
#include <iostream>
using namespace std;
//Unguided1-binary.cpp
// Struktur Node untuk linked list
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambahkan node baru di akhir linked list
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fungsi untuk menampilkan visualisasi linked list
void printList(Node* head) {
    cout << "Linked List yang dibuat: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Fungsi untuk mencari node tengah dalam sub-list
Node* middleNode(Node* start, Node* end) {
    if (start == NULL) {
        return NULL;
    }
    Node* slow = start;
    Node* fast = start->next;
    while (fast != end) {
        fast = fast->next;
        if (fast != end) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

// Fungsi Binary Search pada Linked List
Node* binarySearch(Node* head, int key) {
    Node* start = head;
    Node* end = nullptr;
    int iterasi = 1;

    cout << "Proses Pencarian:" << endl;

    do {
        Node* mid = middleNode(start, end);
        if (mid == nullptr) {
            cout << "Tidak ada elemen tersisa" << endl;
            return nullptr;
        }

        cout << "Iterasi " << iterasi++ << ": Mid = " << mid->data << " (indeks tengah)";

        if (mid->data == key) {
            cout << " - DITEMUKAN!" << endl;
            return mid;
        } else if (mid->data < key) {
            start = mid->next;
            cout << " -> Cari di bagian kanan" << endl;
        } else {
            end = mid;
            cout << " -> Cari di bagian kiri" << endl;
        }
    } while (end == nullptr || end != start);
    
    cout << "Tidak ada elemen tersisa" << endl;
    return nullptr;
}

int main() {
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    cout << "BINARY SEARCH PADA LINKED LIST" << endl;
    printList(head);

    int searchValue1 = 40;
    cout << "\nMencari nilai: " << searchValue1 << endl;
    Node* result1 = binarySearch(head, searchValue1);

    if (result1) {
        cout << "\nHasil: Nilai " << searchValue1 << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << result1 << endl;
        cout << "Data node: " << result1->data << endl;
        if (result1->next) {
            cout << "Node berikutnya: " << result1->next->data << endl;
        } else {
            cout << "Node berikutnya: NULL" << endl;
        }
    }

    int searchValue2 = 25;
    cout << "\nMencari nilai: " << searchValue2 << endl;
    Node* result2 = binarySearch(head, searchValue2);

    if (!result2) {
        cout << "\nHasil: Nilai " << searchValue2 << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }

    return 0;
}

```

### Output Unguided 1 :

##### Output 1
![Output Program 1](https://github.com/mhmmdffzz/103112400064_Muhammad-Fauzan/blob/main/Pertemuan5_Modul5/LAPRAK/Muhammad_Fauzan-Output-Unguided1.png)

Program C++ ini mengimplementasikan algoritma *Binary Search* pada struktur *Singly Linked List* untuk mencari nilai tertentu secara efisien. Fungsi `append()` digunakan untuk menambahkan node di akhir list, `printList()` menampilkan isi list, sedangkan `binarySearch()` memanfaatkan fungsi `middleNode()` untuk menemukan elemen tengah pada setiap iterasi. Proses pencarian dilakukan dengan membandingkan nilai tengah terhadap kunci, lalu membatasi ruang pencarian ke kiri atau kanan hingga elemen ditemukan atau habis. Program menampilkan proses pencarian, hasil, dan informasi node yang ditemukan.

### 2. Linear Search pada Linked List
```C++
#include <iostream>
using namespace std;
////Unguided2-linear.cpp
//Definisi node untuk linked list
struct Node { 
    int data;      // Menyimpan nilai data
    Node* next;    // Pointer ke node selanjutnya
};

// Fungsi untuk menampilkan linked list
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

// Fungsi linear search untuk mencari nilai dalam linked list
// Parameter: head (pointer awal list), key (nilai yang dicari)
// Return: pointer ke node jika ditemukan, nullptr jika tidak
Node* linearSearch(Node* head, int key) {
    cout << "Mencari nilai: " << key << endl;
    cout << "Proses Pencarian:" << endl;
    Node* current = head;
    int position = 1;
    while (current != NULL) {
        cout << "Memeriksa node " << position << ": " << current->data;
        if (current->data == key) {
            cout << " (SAMA) - DITEMUKAN!" << endl;
            return current;
        }
        cout << " (tidak sama)" << endl;
        current = current->next;
        position++;
    }
    cout << "Tidak ada node lagi yang tersisa" << endl;
    return nullptr;
}

// Fungsi untuk menambahkan node baru di akhir list
void append(Node* &head, int value){
    Node *newNode = new Node{value, nullptr};
    if(!head) head = newNode;
    else{
        Node *temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;

    // Membuat linked list
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << "LINEAR SEARCH PADA LINKED LIST" << endl;
    cout << "Linked List yang dibuat: ";
    printList(head);
    cout << endl;

    // Mencari nilai 30
    Node* result = linearSearch(head, 30);
    if (result != NULL) {
        cout << "Hasil: Nilai " << result->data << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << result << endl;
        cout << "Data node: " << result->data << endl;
        if (result->next != NULL) {
            cout << "Node berikutnya: " << result->next->data << endl;
        } else {
            cout << "Node berikutnya: NULL" << endl;
        }
    } else {
        cout << "Hasil: Nilai 30 TIDAK DITEMUKAN dalam linked list!" << endl;
    }

    cout << endl;

    // Mencari nilai 25
    result = linearSearch(head, 25);
    if (result != NULL) {
        cout << "Hasil: Nilai " << result->data << " DITEMUKAN pada linked list!" << endl;
    } else {
        cout << "Hasil: Nilai 25 TIDAK DITEMUKAN dalam linked list!" << endl;
    }

    return 0;
}

```

### Output Unguided 2 :

##### Output 1
![Output Program 1](https://github.com/mhmmdffzz/103112400064_Muhammad-Fauzan/blob/main/Pertemuan5_Modul5/LAPRAK/Muhammad_Fauzan-Output-Unguided2.png)

Program C++ ini menerapkan algoritma *Linear Search* pada struktur *Singly Linked List* untuk mencari nilai tertentu secara berurutan dari node pertama hingga terakhir. Fungsi `append()` digunakan untuk menambah node baru, `printList()` menampilkan isi list, dan `linearSearch()` melakukan pemeriksaan setiap node sambil menampilkan proses pencarian. Jika nilai ditemukan, program menampilkan data node beserta alamat memorinya; jika tidak, ditampilkan pesan bahwa nilai tidak ditemukan.


## Kesimpulan
Pada praktikum modul 5 ini, dipelajari konsep dan implementasi algoritma *searching* yaitu *Linear Search* dan *Binary Search* pada struktur data *Singly Linked List*. Melalui latihan *guided* dan *unguided*, kita dapat memahami perbedaan efisiensi kedua algoritma tersebut dalam proses pencarian data. *Linear Search* mudah diterapkan pada list tidak terurut, sedangkan *Binary Search* lebih efisien pada data yang sudah terurut namun sulit diimplementasikan pada *linked list*. Praktikum ini memberikan pemahaman mengenai analisis kompleksitas waktu pencarian dan pentingnya pemilihan algoritma yang sesuai dengan struktur data dan karakteristik dataset.

## Referensi 
[1]. Politeknik Elektronika Negeri Surabaya (PENS). (t.t.). **Single Linked List - Insert & Delete**. *Materi Struktur Data*.  
**PDF:** [Unduh](https://tita.lecturer.pens.ac.id/ASD/M4_SLL_Insert/Single%20Linked%20List%20INSERT%20%26%20DELETE.pdf)  **Laman materi:** [PENS](https://tita.lecturer.pens.ac.id/ASD/M4_SLL_Insert/Single%20Linked%20List%20INSERT%20%26%20DELETE.pdf)

[2]. Hasdyna, N., & Dinata, R. K. (2021). **Pembelajaran Struktur Data dalam Pemrograman C++**. Sefa Bumi Persada.  
**PDF:** [Unduh](https://repository.unimal.ac.id/6709/1/PEMBELAJARAN%20STRUKTUR%20DATA%20DALAM%20PEMROGRAMAN%20C%2B%2B.pdf)  **Laman buku:** [Repository Unimal](https://repository.unimal.ac.id/6709/)

[3]. Wijaya, H., Wardhono, W. S., & Arwani, I. (2018). **Implementasi Linked List pada Interaksi Antar Marker Augmented Reality untuk Operand dan Operator Aritmetika**. *Jurnal Pengembangan Teknologi Informasi dan Ilmu Komputer, 2*(9), 3328-3332).  
**PDF:** [Unduh](https://j-ptiik.ub.ac.id/index.php/j-ptiik/article/download/2261/840/16799)  **Laman jurnal:** [J-PTIIK UB](https://j-ptiik.ub.ac.id/index.php/j-ptiik/article/view/2261)

[4] Ramadhan, H., Fauziah, & Lantana, D. A. (2023). **Perbandingan Algoritma Binary Search dan Sequential Search untuk Pencarian Persediaan Stok Barang Berbasis Web.” *STRING (Satuan Tulisan Riset dan Inovasi Teknologi)**, 8(2), 125-132.  
**PDF**: [https://www.journal.lppmunindra.ac.id/index.php/STRING/article/download/16475/6178] 
