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
