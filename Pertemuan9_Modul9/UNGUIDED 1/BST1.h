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
