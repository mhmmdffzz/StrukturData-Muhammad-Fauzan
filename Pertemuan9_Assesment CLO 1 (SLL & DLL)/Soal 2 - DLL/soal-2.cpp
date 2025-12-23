<<<<<<< HEAD
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nilai;
    Node* next;
};

Node* head = NULL;

void insertEnd(string nilai) {
    Node* newNode = new Node;
    newNode->nilai = nilai;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void deleteLast() {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    delete temp;
}

void viewList() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->nilai << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseList() {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main() {
    int menu;
    string nilai;

    do {
        cout << "Menu: 1 insert (end), 2 delete (last), 3 view (depan), 4 reverse & view (depan), 0 exit\n";
        cin >> menu;
        switch(menu) {
        case 1:
            cout << "Masukkan nilai: ";
            cin >> nilai;
            insertEnd(nilai);
            break;
        case 2:
            deleteLast();
            break;
        case 3:
            viewList();
            break;
        case 4:
            reverseList();
            cout << "List setelah di-reverse: ";
            viewList();
            break;
        case 0:
            break;
        default:
            cout << "Menu tidak valid!\n";
        }

    } while (menu != 0);

    return 0;
}
=======
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nilai;
    Node* next;
};

Node* head = NULL;

void insertEnd(string nilai) {
    Node* newNode = new Node;
    newNode->nilai = nilai;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void deleteLast() {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    delete temp;
}

void viewList() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->nilai << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseList() {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main() {
    int menu;
    string nilai;

    do {
        cout << "Menu: 1 insert (end), 2 delete (last), 3 view (depan), 4 reverse & view (depan), 0 exit\n";
        cin >> menu;
        switch(menu) {
        case 1:
            cout << "Masukkan nilai: ";
            cin >> nilai;
            insertEnd(nilai);
            break;
        case 2:
            deleteLast();
            break;
        case 3:
            viewList();
            break;
        case 4:
            reverseList();
            cout << "List setelah di-reverse: ";
            viewList();
            break;
        case 0:
            break;
        default:
            cout << "Menu tidak valid!\n";
        }

    } while (menu != 0);

    return 0;
}
>>>>>>> c5f8b798a769c9cc7872b0796a5eae31e5e4aba7
