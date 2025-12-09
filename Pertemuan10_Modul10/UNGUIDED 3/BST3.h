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
