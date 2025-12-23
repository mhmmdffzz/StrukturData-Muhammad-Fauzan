#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string namaMember, tierMember;
    float beratBadan;
    Node *left, *right;
};

extern Node* root;

void createTree();
bool isEmpty();
Node* newNode(string nama, float berat, string tier);
Node* insertNode(Node* current, string nama, float berat, string tier);
void inOrder(Node* current);
void mostLeft();
void mostRight();
void cetak(Node* n);
void searchByBeratBadan(float cari);

#endif
