#include <iostream>
using namespace std;

//Definisi node untuk linked list
struct Node { 
    int data;      // Menyimpan nilai data
    Node* next;    // Pointer ke node selanjutnya
};

// Fungsi linear search untuk mencari nilai dalam linked list
// Parameter: head (pointer awal list), key (nilai yang dicari)
// Return: pointer ke node jika ditemukan, nullptr jika tidak
Node* linearSearch(Node* head, int key) {
    Node* current = head;              // Mulai dari node pertama
    while (current != nullptr) {       // Traverse seluruh list
        if (current->data == key) {    // Jika data ditemukan
            return current;            // Kembalikan pointer node tersebut
        }
        current = current->next;       // Pindah ke node berikutnya
    }
    return nullptr;                    // Tidak ditemukan, return nullptr
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
    Node* head = nullptr;  // Inisialisasi linked list kosong

    // Menambahkan beberapa elemen ke linked list
    append(head, 10);
    append(head, 20);
    append(head, 30);
    
    Node* result = linearSearch(head, 20); // Panggil fungsi linear search

  cout << (result ? "Found" : "Not Found") << endl; // Tampilkan hasil pencarian

    return 0;
}
