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
