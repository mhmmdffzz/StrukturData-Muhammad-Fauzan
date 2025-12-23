<<<<<<< HEAD
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;
};

Node* head = NULL;

void insertEnd(string name) {
    Node* newNode = new Node;
    newNode->name = name;
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

void deleteName(string target) {
    if (head == NULL) {
        cout << "List Kosong!\n";
        return;
    }

    Node* del = head;
    Node* prev = NULL;

    if (del->name == target) {
        head = head->next;
        delete del;
        return;
    }

    while (del != NULL && del->name != target) {
        prev = del;
        del = del->next;
    }

    if (del == NULL) {
        cout << "Nama tidak ditemukan!\n";
    } else {
        prev->next = del->next;
        delete del;
    }
}


void viewList() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->name << " ";
        temp = temp->next;
    }
    cout << endl;
}

void countEven() {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        if (temp->name.length() % 2 == 0)
            count++;
        temp = temp->next;
    }

    cout << "Total Nama: " << count << endl;
}

int main() {
    int menu;
    string name;

    do {
        cout << "Menu: 1 insert, 2 delete, 3 view, 4 Hitung Genap, 0 exit\n";
        cin >> menu;
        switch(menu) {
        case 1:
            cout << "Masukkan Nama: ";
            cin >> name;
            insertEnd(name);
            break;
        case 2:
            cout << "Masukkan nama untuk di delete: ";
            cin >> name;
            deleteName(name);
            break;
        case 3:
            viewList();
            break;
        case 4:
            countEven();
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
    string name;
    Node* next;
};

Node* head = NULL;

void insertEnd(string name) {
    Node* newNode = new Node;
    newNode->name = name;
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

void deleteName(string target) {
    if (head == NULL) {
        cout << "List Kosong!\n";
        return;
    }

    Node* del = head;
    Node* prev = NULL;

    if (del->name == target) {
        head = head->next;
        delete del;
        return;
    }

    while (del != NULL && del->name != target) {
        prev = del;
        del = del->next;
    }

    if (del == NULL) {
        cout << "Nama tidak ditemukan!\n";
    } else {
        prev->next = del->next;
        delete del;
    }
}


void viewList() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->name << " ";
        temp = temp->next;
    }
    cout << endl;
}

void countEven() {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        if (temp->name.length() % 2 == 0)
            count++;
        temp = temp->next;
    }

    cout << "Total Nama: " << count << endl;
}

int main() {
    int menu;
    string name;

    do {
        cout << "Menu: 1 insert, 2 delete, 3 view, 4 Hitung Genap, 0 exit\n";
        cin >> menu;
        switch(menu) {
        case 1:
            cout << "Masukkan Nama: ";
            cin >> name;
            insertEnd(name);
            break;
        case 2:
            cout << "Masukkan nama untuk di delete: ";
            cin >> name;
            deleteName(name);
            break;
        case 3:
            viewList();
            break;
        case 4:
            countEven();
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
