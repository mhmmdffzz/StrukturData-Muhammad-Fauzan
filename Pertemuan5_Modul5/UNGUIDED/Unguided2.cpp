#include <iostream>
using namespace std;
////Unguided2-linear.cpp
//Definisi node untuk linked list
struct Node { 
    int data;      // Menyimpan nilai data
    Node* next;    // Pointer ke node selanjutnya
};

// Fungsi untuk menampilkan linked list
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

// Fungsi linear search untuk mencari nilai dalam linked list
// Parameter: head (pointer awal list), key (nilai yang dicari)
// Return: pointer ke node jika ditemukan, nullptr jika tidak
Node* linearSearch(Node* head, int key) {
    cout << "Mencari nilai: " << key << endl;
    cout << "Proses Pencarian:" << endl;
    Node* current = head;
    int position = 1;
    while (current != NULL) {
        cout << "Memeriksa node " << position << ": " << current->data;
        if (current->data == key) {
            cout << " (SAMA) - DITEMUKAN!" << endl;
            return current;
        }
        cout << " (tidak sama)" << endl;
        current = current->next;
        position++;
    }
    cout << "Tidak ada node lagi yang tersisa" << endl;
    return nullptr;
}

// Fungsi untuk menambahkan node baru di akhir list
void append(Node* &head, int value){
    Node *newNode = new Node{value, nullptr};
    if(!head) head = newNode;
    else{
        Node *temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;

    // Membuat linked list
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << "LINEAR SEARCH PADA LINKED LIST" << endl;
    cout << "Linked List yang dibuat: ";
    printList(head);
    cout << endl;

    // Mencari nilai 30
    Node* result = linearSearch(head, 30);
    if (result != NULL) {
        cout << "Hasil: Nilai " << result->data << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << result << endl;
        cout << "Data node: " << result->data << endl;
        if (result->next != NULL) {
            cout << "Node berikutnya: " << result->next->data << endl;
        } else {
            cout << "Node berikutnya: NULL" << endl;
        }
    } else {
        cout << "Hasil: Nilai 30 TIDAK DITEMUKAN dalam linked list!" << endl;
    }

    cout << endl;

    // Mencari nilai 25
    result = linearSearch(head, 25);
    if (result != NULL) {
        cout << "Hasil: Nilai " << result->data << " DITEMUKAN pada linked list!" << endl;
    } else {
        cout << "Hasil: Nilai 25 TIDAK DITEMUKAN dalam linked list!" << endl;
    }

    return 0;
}
