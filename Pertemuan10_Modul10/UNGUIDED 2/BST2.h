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
