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
