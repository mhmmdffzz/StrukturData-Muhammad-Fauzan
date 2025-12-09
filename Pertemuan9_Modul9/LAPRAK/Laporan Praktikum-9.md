# <h1 align="center">Laporan Praktikum Modul 9 - Tree (Bagian Pertama) </h1>
<p align="center">Muhammad Fauzan - 103112400064</p>

## Dasar Teori
Binary Search Tree (BST) merupakan salah satu bentuk struktur data pohon biner yang digunakan untuk menyimpan data secara terurut berdasarkan nilai tertentu. Pada BST, setiap node memiliki maksimal dua anak, yaitu anak kiri dan anak kanan, dengan ketentuan bahwa nilai pada subtree kiri harus lebih kecil daripada nilai node induknya, sedangkan nilai pada subtree kanan harus lebih besar [1]. Aturan ini memungkinkan BST melakukan penyisipan dan pencarian data dengan lebih cepat dibandingkan struktur data linier karena penelusuran hanya bergerak melalui salah satu cabang sesuai hasil perbandingan nilai [2].

BST memiliki beberapa operasi dasar seperti insert, search, dan traversal. Pada proses insert, nilai baru dibandingkan dengan node yang sedang diperiksa, kemudian diarahkan ke kiri atau ke kanan hingga menemukan pointer kosong tempat nilai baru ditempatkan. Proses search menggunakan langkah yang sama sehingga pencarian data berlangsung secara efisien dan terstruktur [1].

Traversal pada BST digunakan untuk membaca isi tree. InOrder traversal (Left–Root–Right) menghasilkan data dalam urutan menaik sehingga sering digunakan untuk menampilkan data terurut. PreOrder traversal (Root–Left–Right) bermanfaat untuk merekonstruksi struktur tree atau menghasilkan representasi prefix. Sementara PostOrder traversal (Left–Right–Root) sering digunakan untuk menghapus tree atau pada evaluasi ekspresi, karena anak diproses sebelum node induknya [2].

Selain itu, BST dapat dilengkapi dengan fungsi tambahan seperti menghitung jumlah node, menghitung total nilai seluruh node, dan menentukan kedalaman tree. Penghitungan jumlah node dilakukan dengan menjumlahkan node pada setiap subtree secara rekursif. Total nilai node dihitung dengan menjumlahkan info dari masing-masing node, sementara kedalaman tree ditentukan berdasarkan level terdalam yang dapat dicapai dari root [3].

**Contoh Implementasi:**  
Jika data dimasukkan secara berurutan: `6, 4, 7, 2, 5`

Tree yang terbentuk:  
      6
     / \
    4   7
   / 
  25 

Hasil traversal:  
- **InOrder:** 2, 4, 5, 6, 7  
- **PreOrder:** 6, 4, 2, 5, 7  
- **PostOrder:** 2, 5, 4, 7, 6  

Karakteristik tree:  
- **Jumlah node:** 5  
- **Total nilai node:** 24  
- **Kedalaman tree:** 2  

BST banyak digunakan dalam struktur data pada bahasa pemrograman, penyusunan indeks pencarian, serta mekanisme penyimpanan data terurut karena sifatnya yang efisien dan mudah diimplementasikan [1].

## Guided

### 1. Rekursif Pangkat 2
```C++
#include<iostream>
using namespace std;

int pangkat_2(int x) { //adalah pengkatnya
    if(x == 0) { //basis
        return 1;
    } else if (x > 0) { //rekurens
        return 2 * pangkat_2(x - 1);
    }
}

int main() {
    cout << "=== REKURSIF PANGKAT 2 ===" << endl;

    int x;
    cout << "Masukkan nilai x: "; 
    cin >> x;
    cout << endl;
    cout << " pangkat 2 dari " << x << " adalah : " << pangkat_2(x) ;

    return 0;
}

//misal x = 3
//pangkat_2(3)
// 2 * pangkat_2(2);
// 2 * (2 * pangkat_2(1));
// 2 * (2 * (2 * pangkat_2(0)));
// = 2 * 2 * 2
// = 8
```

Program ini digunakan untuk menghitung nilai 2 pangkat x (2^x) menggunakan konsep rekursi.

### 2. Binery Search Tree 1
#### BST1.h
```C++
#ifndef BST1_H
#define BST1_H

#include <iostream>

using namespace std;

typedef int infotype;//alias infotype untuk data integer
typedef struct Node *address;//alias address untuk pointer ke struct Node (*Node)
typedef struct Node {
    infotype info;//data integer yang disimpan
    address left;//pointer ke anak kiri
    address right;//pointer ke anak kanan
} Node;

//isEmpty & createTree
bool isEmpty(address root); //function untuk mengecek apakah tree kosong
void createTree(address &root); //function untuk membuat tree kosong

//alokasi &insertBST
address newNode(infotype x); //function untuk memasukkan data(infotype) ke dalam node baru
address insertNode(address root, infotype x); //function untuk memasukkan node baru ke dalam BST

//Traversal
void preOrder(address root); //function traversal tree secara preOrder (tengah -> kiri -> kanan atau root -> child kiri -> child kanan)
void inOrder(address root); //function traversal tree secara inOrder (kiri -> tengah -> kanan atau child kiri -> root -> child kanan)
void postOrder(address root); //function traversal tree secara postOrder (kiri -> kanan -> tengah atau child kiri -> child kanan -> root)

//Utility
int countNodes(address root); //function untuk menghitung size atau ukurun atau jumlah node yang ada pada tree
int treeDepth(address root); //function untuk menghitung depth atau kedalaman atau level tree

#endif
```

#### BST1.cpp
```C++
#include "BST1.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}

//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```

#### main.cpp
```C++
#include <iostream>
#include "BST1.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}
```
Program C++ ini membuat dan mengelola **Binary Search Tree (BST)** dengan beberapa kemampuan utama, yaitu melakukan insert data, melakukan traversal (preOrder, inOrder, postOrder), menghitung total node dalam tree, serta menentukan kedalaman tree.

Struktur program disusun dalam tiga file terpisah:

- **BST1.h** -> berisi deklarasi struktur data dan prototipe fungsi  
- **BST1.cpp** -> berisi implementasi dari seluruh fungsi BST  
- **main.cpp** -> berisi program utama yang menjalankan proses insert, traversal, dan perhitungan pada tree


### 3. Binery Search Tree 2
#### BST2.h
```C++
#ifndef BST2_H
#define BST2_H

#include <iostream>

using namespace std;

typedef int infotype;//alias infotype untuk data integer
typedef struct Node *address;//alias address untuk pointer ke struct Node (*Node)
typedef struct Node {
    infotype info;//data integer yang disimpan
    address left;//pointer ke anak kiri
    address right;//pointer ke anak kanan
} Node;

//isEmpty & createTree
bool isEmpty(address root); //function untuk mengecek apakah tree kosong
void createTree(address &root); //function untuk membuat tree kosong

//alokasi &insertBST
address newNode(infotype x); //function untuk memasukkan data(infotype) ke dalam node baru
address insertNode(address root, infotype x); //function untuk memasukkan node baru ke dalam BST

//Traversal
void preOrder(address root); //function traversal tree secara preOrder (tengah -> kiri -> kanan atau root -> child kiri -> child kanan)
void inOrder(address root); //function traversal tree secara inOrder (kiri -> tengah -> kanan atau child kiri -> root -> child kanan)
void postOrder(address root); //function traversal tree secara postOrder (kiri -> kanan -> tengah atau child kiri -> child kanan -> root)

//Utility
int countNodes(address root); //function untuk menghitung size atau ukurun atau jumlah node yang ada pada tree
int treeDepth(address root); //function untuk menghitung depth atau kedalaman atau level tree

//FUNCTION & Prosedur Baru
//searching
void searchByData(address root, infotype x); //function untuk melakukan searching data tertentu

// Mostleft & Mostright
address mostLeft(address root); //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
address mostRight(address root); //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
//delete
bool deleteNode(address &root, infotype x); //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
void deleteTree(address &root); //prosedur untuk menghapus seluruh node yang ada didalam BST
#endif
```

#### BST2.cpp
```C++
#include "BST2.h"
#include <iostream>

using namespace std;

//FUNCTION & PROSEDUR SEBELUMNYA
//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}


//FUNCTION & PROSEDUR BARU
//searching
void searchByData(address root, infotype x) { //function untuk melakukan searching data tertentu
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = NULL;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(x < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(x > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(x == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam BST!" << endl;
            cout << "Data Angka : " << nodeBantu->info << endl;

            //menampilkan parentnya & pengecekan sibling
            address sibling = NULL;
            if(parent != NULL){
                cout << "Parent : " << parent->info << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != NULL){
                cout << "Sibling : " << sibling->info << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != NULL){
                cout << "Child kiri : " << nodeBantu->left->info << endl;
            } else if(nodeBantu->left == NULL){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != NULL){
                cout << "Child kanan : " << nodeBantu->right->info << endl;
            } else if(nodeBantu->right == NULL){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}


//mostleft & mostright
address mostLeft(address root) { //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

address mostRight(address root) { //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}


//delete
bool deleteNode(address &root, infotype x) { //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
    if (root == NULL) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (x < root->info) {
            return deleteNode(root->left, x);
        } else if (x > root->info) {
            return deleteNode(root->right, x);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (root->left == NULL && root->right == NULL) {
                address temp = root;
                root = NULL;
                delete temp;
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (root->left == NULL) {
                address temp = root;
                root = root->right;
                delete temp;
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (root->right == NULL) {
                address temp = root;
                root = root->left;
                delete temp;
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                address successor = mostLeft(root->right);
                //salin data successor ke node saat ini
                root->info = successor->info;
                //hapus successor pada subtree kanan
                return deleteNode(root->right, successor->info);
            }
            return true; //berhasil dihapus
        }
    }
}

void deleteTree(address &root) { //prosedur untuk menghapus BST (menghapus seluruh node BST)
    if(root == NULL){
        return;
    } else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}
```
#### main.cpp
```C++
#include <iostream>
#include "BST2.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "=== Binary Search Tree ==" << endl;
    cout << endl;

    root = insertNode(root, 30); // Root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    searchByData(root, 17);
    
    cout << endl;
    cout << "Node mostleft : " << mostLeft(root)->info << endl;
    cout << "Node mostright : " << mostRight(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;
    //misal angka yang dihapus adalah angka 17
    if(deleteNode(root, angkaHapus)){
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl;

    cout << endl;
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
    }
    return 0;
}
```
Program C++ ini mengembangkan implementasi **Binary Search Tree (BST)** dengan fitur tambahan seperti pencarian data, menampilkan node terkiri (mostleft) dan terkanan (mostright), menghapus node tertentu, serta menghapus seluruh tree.

Struktur program dibagi menjadi tiga file:

- **BST2.h** -> deklarasi struktur data & seluruh fungsi BST  
- **BST2.cpp** -> implementasi fungsi insert, traversal, searching, mostleft/mostright, delete node, dan delete tree  
- **main.cpp** -> menjalankan program (insert data, traversal, pencarian, penghapusan node, dan penghapusan tree)


## Unguided 

### 1. ADT - BST
#### BST1.h
```C++
// BST1.h
// Header file untuk Binary Search Tree ADT

#ifndef BST1_H
#define BST1_H

// Type infotype: integer
typedef int infotype;

// Type address: pointer to Node
struct Node;
typedef Node* address;

// Konstanta Nil
#define Nil NULL

// Type Node
struct Node {
    infotype info;
    address left;
    address right;
};

// function alokasi(x : infotype) -> address
// Mengalokasikan node baru dengan nilai x
address alokasi(infotype x);

// procedure insertNode(input/output root : address, input x : infotype)
// Menyisipkan node dengan nilai x ke dalam BST
void insertNode(address &root, infotype x);

// function findNode(x : infotype, root : address) -> address
// Mencari node dengan nilai x dalam BST
address findNode(infotype x, address root);

// procedure printInorder(input root : address)
// Mencetak BST secara inorder (Left-Root-Right)
void printInorder(address root);

// Alias InOrder untuk kompatibilitas dengan main.cpp
void InOrder(address root);

#endif
```

#### BST1.cpp
```C++
// BST1.cpp
// Implementasi Binary Search Tree ADT

#include <iostream>
#include "BST1.h"

using namespace std;

// function alokasi(x : infotype) -> address
// Mengalokasikan node baru dengan nilai x
address alokasi(infotype x) {
    address newNode = new Node;
    newNode->info = x;
    newNode->left = Nil;
    newNode->right = Nil;
    return newNode;
}

// procedure insertNode(input/output root : address, input x : infotype)
// Menyisipkan node dengan nilai x ke dalam BST
void insertNode(address &root, infotype x) {
    if (root == Nil) {
        // Jika tree kosong, buat node baru sebagai root
        root = alokasi(x);
    } else if (x < root->info) {
        // Jika x lebih kecil dari root, insert ke subtree kiri
        insertNode(root->left, x);
    } else if (x > root->info) {
        // Jika x lebih besar dari root, insert ke subtree kanan
        insertNode(root->right, x);
    }
    // Jika x == root->info, tidak insert (menghindari duplikasi)
}

// function findNode(x : infotype, root : address) -> address
// Mencari node dengan nilai x dalam BST
address findNode(infotype x, address root) {
    if (root == Nil) {
        // Jika tree kosong atau tidak ditemukan
        return Nil;
    } else if (x == root->info) {
        // Jika ditemukan
        return root;
    } else if (x < root->info) {
        // Jika x lebih kecil, cari di subtree kiri
        return findNode(x, root->left);
    } else {
        // Jika x lebih besar, cari di subtree kanan
        return findNode(x, root->right);
    }
}

// procedure printInorder(input root : address)
// Mencetak BST secara inorder (Left-Root-Right)
void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

// Alias InOrder untuk kompatibilitas dengan main.cpp
void InOrder(address root) {
    printInorder(root);
}

```

#### main.cpp
```C++
// main.cpp
// Program utama untuk menguji implementasi Binary Search Tree

#include <iostream>
#include "BST1.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;
    
    address root = Nil;
    
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);
    
    InOrder(root);
    
    return 0;
}

```

### Output Unguided 1 :

##### Output 1
![Output Program 1](https://github.com/mhmmdffzz/103112400064_Muhammad-Fauzan/blob/main/Pertemuan9_Modul9/LAPRAK/Muhammad_Fauzan-Output-Unguided1.png)

Program C++ ini membangun dan memanfaatkan **Binary Search Tree (BST)** menggunakan konsep Abstract Data Type (ADT). Di dalamnya terdapat proses pembuatan node, penyisipan nilai ke dalam tree, pencarian nilai tertentu, serta menampilkan isi tree menggunakan traversal inorder.

Kode program disusun ke dalam tiga berkas:
- **BST1.h** -> mendefinisikan tipe data, struktur node, dan deklarasi fungsi-fungsi pada BST  
- **BST1.cpp** -> berisi implementasi fungsi alokasi node, penyisipan data, pencarian node, dan prosedur inorder traversal  
- **main.cpp** -> menjalankan program dengan memasukkan beberapa data ke dalam BST kemudian menampilkan hasil penyusunan tree melalui traversal inorder

Melalui proses insert, nilai ditempatkan sesuai aturan BST, dan hasil traversal **InOrder** menampilkan data dalam urutan yang terurut secara naik.

### 2. BST - Hitung Node, Total dan Kedalam
#### BST2.h
```C++
// BST2.h
// Header file untuk Binary Search Tree ADT

#ifndef BST2_H
#define BST2_H

// Type infotype: integer
typedef int infotype;

// Type address: pointer to Node
struct Node;
typedef Node* address;

// Konstanta Nil
#define Nil NULL

// Type Node
struct Node {
    infotype info;
    address left;
    address right;
};

// function alokasi(x : infotype) -> address
// Mengalokasikan node baru dengan nilai x
address alokasi(infotype x);

// procedure insertNode(input/output root : address, input x : infotype)
// Menyisipkan node dengan nilai x ke dalam BST
void insertNode(address &root, infotype x);

// function findNode(x : infotype, root : address) -> address
// Mencari node dengan nilai x dalam BST
address findNode(infotype x, address root);

// procedure printInorder(input root : address)
// Mencetak BST secara inorder (Left-Root-Right)
void printInorder(address root);

// Alias InOrder untuk kompatibilitas dengan main.cpp
void InOrder(address root);

// ===== FUNGSI TAMBAHAN UNTUK SOAL NOMOR 2 =====

// function hitungJumlahNode(root : address) : integer
// Mengembalikan jumlah banyak node yang ada di dalam BST
int hitungNode(address root);

// function hitungTotalInfo(root : address, start : integer) : integer
// Mengembalikan jumlah (total) info dari node-node yang ada di dalam BST
int hitungTotal(address root);

// function hitungKedalaman(root : address, start : integer) : integer
// Mengembalikan integer kedalaman maksimal dari binary tree
int hitungKedalaman(address root, int level);

#endif
```

#### BST2.cpp
```C++
// BST2.cpp
// Implementasi Binary Search Tree ADT

#include <iostream>
#include "BST2.h"

using namespace std;

// function alokasi(x : infotype) -> address
// Mengalokasikan node baru dengan nilai x
address alokasi(infotype x) {
    address newNode = new Node;
    newNode->info = x;
    newNode->left = Nil;
    newNode->right = Nil;
    return newNode;
}

// procedure insertNode(input/output root : address, input x : infotype)
// Menyisipkan node dengan nilai x ke dalam BST
void insertNode(address &root, infotype x) {
    if (root == Nil) {
        // Jika tree kosong, buat node baru sebagai root
        root = alokasi(x);
    } else if (x < root->info) {
        // Jika x lebih kecil dari root, insert ke subtree kiri
        insertNode(root->left, x);
    } else if (x > root->info) {
        // Jika x lebih besar dari root, insert ke subtree kanan
        insertNode(root->right, x);
    }
    // Jika x == root->info, tidak insert (menghindari duplikasi)
}

// function findNode(x : infotype, root : address) -> address
// Mencari node dengan nilai x dalam BST
address findNode(infotype x, address root) {
    if (root == Nil) {
        // Jika tree kosong atau tidak ditemukan
        return Nil;
    } else if (x == root->info) {
        // Jika ditemukan
        return root;
    } else if (x < root->info) {
        // Jika x lebih kecil, cari di subtree kiri
        return findNode(x, root->left);
    } else {
        // Jika x lebih besar, cari di subtree kanan
        return findNode(x, root->right);
    }
}

// procedure printInorder(input root : address)
// Mencetak BST secara inorder (Left-Root-Right)
void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

// Alias InOrder untuk kompatibilitas dengan main.cpp
void InOrder(address root) {
    printInorder(root);
}

// ===== IMPLEMENTASI FUNGSI TAMBAHAN UNTUK SOAL NOMOR 2 =====

// function hitungNode(root : address) : integer
// Mengembalikan jumlah banyak node yang ada di dalam BST
int hitungNode(address root) {
    if (root == Nil) {
        return 0;
    }
    // Hitung node: 1 (node saat ini) + jumlah node di subtree kiri + jumlah node di subtree kanan
    return 1 + hitungNode(root->left) + hitungNode(root->right);
}

// function hitungTotal(root : address) : integer
// Mengembalikan jumlah (total) info dari node-node yang ada di dalam BST
int hitungTotal(address root) {
    if (root == Nil) {
        return 0;
    }
    // Total = info node saat ini + total info subtree kiri + total info subtree kanan
    return root->info + hitungTotal(root->left) + hitungTotal(root->right);
}

// function hitungKedalaman(root : address, level : integer) : integer
// Mengembalikan integer kedalaman maksimal dari binary tree
// level dimulai dari 0 untuk root
int hitungKedalaman(address root, int level) {
    if (root == Nil) {
        return level;
    }
    
    // Hitung kedalaman maksimal di subtree kiri dan kanan
    int kedalamanKiri = hitungKedalaman(root->left, level + 1);
    int kedalamanKanan = hitungKedalaman(root->right, level + 1);
    
    // Kembalikan kedalaman maksimal
    if (kedalamanKiri > kedalamanKanan) {
        return kedalamanKiri;
    } else {
        return kedalamanKanan;
    }
}

```

#### main.cpp
```C++
// main.cpp
// Program utama untuk menguji implementasi Binary Search Tree
// Soal Nomor 2: hitungJumlahNode, hitungTotalInfo, hitungKedalaman

#include <iostream>
#include "BST2.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;
    
    address root = Nil;
    
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);
    
    InOrder(root);
    cout << "\n";
    
    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah node : " << hitungNode(root) << endl;
    cout << "total : " << hitungTotal(root) << endl;
    
    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Output Program 1](https://github.com/mhmmdffzz/103112400064_Muhammad-Fauzan/blob/main/Pertemuan9_Modul9/LAPRAK/Muhammad_Fauzan-Output-Unguided2.png)

Program C++ ini mengimplementasikan Binary Search Tree (BST) yang tidak hanya mampu melakukan operasi dasar seperti penyisipan data dan pencetakan inorder, tetapi juga dilengkapi dengan fungsi tambahan untuk menghitung jumlah node, menghitung total nilai info dari seluruh node, serta menentukan kedalaman maksimum tree.

Struktur program terdiri dari tiga berkas utama:
- **BST2.h** -> berisi deklarasi struktur node dan prototipe fungsi-fungsi yang digunakan, termasuk fungsi tambahan untuk perhitungan node, total, dan kedalaman  
- **BST2.cpp** -> berisi implementasi fungsi alokasi node, penyisipan data, pencarian, inorder traversal, serta perhitungan jumlah node, total data, dan kedalaman tree  
- **main.cpp** -> menjalankan pengujian dengan memasukkan beberapa data ke dalam BST, lalu menampilkan hasil traversal, jumlah node, total nilai info, dan kedalaman tree

Melalui pemanggilan fungsi-fungsi tersebut, program menghasilkan informasi lengkap mengenai isi dan struktur dari BST yang telah dibangun.

### 3. BST - Pre-Order dan Post-Order Traversal
#### BST3.h
```C++
#ifndef BST3_H
#define BST3_H

typedef int infotype;
struct Node;
typedef Node* address;
#define Nil NULL

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
void InOrder(address root);
void PreOrder(address root);
void PostOrder(address root);

#endif
```

#### BST3.cpp
```C++
#include <iostream>
#include "BST3.h"
using namespace std;

address alokasi(infotype x) {
    address newNode = new Node;
    newNode->info = x;
    newNode->left = Nil;
    newNode->right = Nil;
    return newNode;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

void InOrder(address root) {
    if (root != Nil) {
        InOrder(root->left);
        cout << root->info << " - ";
        InOrder(root->right);
    }
}

void PreOrder(address root) {
    if (root != Nil) {
        cout << root->info << " - ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(address root) {
    if (root != Nil) {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->info << " - ";
    }
}

```

#### main.cpp
```C++
#include <iostream>
#include "BST3.h"
using namespace std;

int main() {
    address root = Nil;
    
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 5);
    insertNode(root, 1);
    insertNode(root, 3);
    
    cout << "Pre-Order: ";
    PreOrder(root);
    cout << endl;
    
    cout << "Post-Order: ";
    PostOrder(root);
    cout << endl;
    
    return 0;
}
```

### Output Unguided 3 :

##### Output 1
![Output Program 1](https://github.com/mhmmdffzz/103112400064_Muhammad-Fauzan/blob/main/Pertemuan9_Modul9/LAPRAK/Muhammad_Fauzan-Output-Unguided3.png)

Program C++ ini mengimplementasikan **Binary Search Tree (BST)** dengan fokus pada dua jenis traversal penting, yaitu **Pre-Order** dan **Post-Order**, selain tetap menyediakan traversal InOrder sebagai referensi. Program membangun tree menggunakan proses insert berbasis aturan BST, kemudian menampilkan hasil traversal sesuai urutan yang diminta.

Struktur program disusun ke dalam tiga file utama:
- **BST3.h** -> mendefinisikan struktur node dan deklarasi fungsi-fungsi traversal (InOrder, PreOrder, PostOrder) serta fungsi insert  
- **BST3.cpp** -> berisi implementasi alokasi node, proses penyisipan data ke dalam BST, dan algoritma traversal secara InOrder, PreOrder, dan PostOrder  
- **main.cpp** -> menguji BST dengan memasukkan beberapa nilai, lalu menampilkan hasil traversal Pre-Order dan Post-Order

Melalui program ini, dapat diamati perbedaan pola penjelajahan tree pada masing-masing traversal, di mana Pre-Order memproses root terlebih dahulu, sedangkan Post-Order memproses root di akhir.

## Kesimpulan
Melalui praktikum ini dipelajari cara kerja dan implementasi **Binary Search Tree (BST)**, terutama pada operasi dasar seperti penyisipan data, pencarian nilai, serta traversal InOrder, PreOrder, dan PostOrder. Percobaan juga mencakup perhitungan jumlah node, total nilai pada tree, dan kedalaman struktur.

Dari hasil yang diperoleh, dapat disimpulkan bahwa BST membantu mengelola data secara lebih teratur dan efisien karena setiap nilai ditempatkan sesuai aturan kiri–kanan berdasarkan besarannya. Berbagai traversal memberikan sudut pandang berbeda dalam membaca data, sehingga dapat digunakan sesuai kebutuhan. Praktikum ini memberikan pemahaman awal yang penting tentang bagaimana data dapat diatur secara hierarkis untuk mendukung proses pencarian dan pengolahan yang lebih cepat.

## Referensi  
[1]. Mahir Koding. (2022). **Struktur Data – Binary Search Tree (BST).**  
HTML: https://www.mahirkoding.com/struktur-data-binary-search-tree-bst/

[2]. Morfotech / Terapan-TI Unesa. (2024). **Binary Search Tree Tutorial: Konsep Dasar hingga Implementasi Praktis.**  
HTML: https://morfotech.id/blog/morfogenesis-binary-search-tree-tutorial-konsep-dasar-implementasi-praktis

[3]. BDS Telkom University. (2022). **Struktur Data Tree: Konsep, Jenis, dan Aplikasinya.**  
HTML: https://bds.telkomuniversity.ac.id/struktur-data-tree-konsep-jenis-dan-aplikasinya/