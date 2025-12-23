#include "BST.h"
using namespace std;

Node* root;

void createTree() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

Node* newNode(string nama, float berat, string tier) {
    Node* n = new Node;
    n->namaMember = nama;
    n->beratBadan = berat;
    n->tierMember = tier;
    n->left = n->right = NULL;
    return n;
}

Node* insertNode(Node* current, string nama, float berat, string tier) {
    if (current == NULL)
        return newNode(nama, berat, tier);

    if (berat < current->beratBadan)
        current->left = insertNode(current->left, nama, berat, tier);
    else if (berat > current->beratBadan)
        current->right = insertNode(current->right, nama, berat, tier);

    return current;
}

void inOrder(Node* current) {
    if (current != NULL) {
        inOrder(current->left);
        cout << current->beratBadan << " - ";
        inOrder(current->right);
    }
}

void mostLeft() {
    Node* b = root;
    while (b && b->left)
        b = b->left;
    if (b)
        cout << "Node most left  : " << b->beratBadan << endl;
}

void mostRight() {
    Node* b = root;
    while (b && b->right)
        b = b->right;
    if (b)
        cout << "Node most right : " << b->beratBadan << endl;
}

void cetak(Node* n) {
    if (!n) {
        cout << "Tidak Ada Data\n";
        return;
    }
    cout << "Nama Member : " << n->namaMember << endl;
    cout << "Berat Badan : " << n->beratBadan << endl;
    cout << "Tier Member : " << n->tierMember << endl;
}

void searchByBeratBadan(float cari) {
    Node *curr = root, *parent = NULL;

    while (curr && curr->beratBadan != cari) {
        parent = curr;
        curr = (cari < curr->beratBadan) ? curr->left : curr->right;
    }

    if (!curr) {
        cout << "Data tidak ditemukan!\n";
        return;
    }

    cout << "\n DATA PARENT \n";
    if (parent) cetak(parent);
    else cout << "Root (tidak memiliki parent)\n";

    cout << "\n DATA SIBLING \n";
    if (parent) {
        Node* sibling = (parent->left == curr) ? parent->right : parent->left;
        cetak(sibling);
    } else {
        cout << "Tidak memiliki sibling\n";
    }

    cout << "\n CHILD KIRI \n";
    cetak(curr->left);
    cout << "\n CHILD KANAN \n";
    cetak(curr->right);
}
