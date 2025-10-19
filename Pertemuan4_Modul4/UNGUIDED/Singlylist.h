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
