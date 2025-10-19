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
