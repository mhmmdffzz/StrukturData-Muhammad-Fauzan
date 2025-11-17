# <h1 align="center">Laporan Praktikum Modul 7 - Stack </h1>
<p align="center">Muhammad Fauzan - 103112400064</p>

## Dasar Teori
Stack merupakan salah satu struktur data dasar yang bekerja menyerupai tumpukan barang, di mana elemen yang dimasukkan paling akhir akan menjadi elemen pertama yang dikeluarkan. Secara umum, stack adalah struktur data linier untuk menyimpan kumpulan nilai atau objek dan seluruh operasinya dilakukan di bagian atas tumpukan **(LIFO – Last In, First Out)** [1]. Operasi dasar seperti **push** untuk menambah elemen dan **pop** untuk menghapus elemen terjadi pada satu sisi saja. Penggunaan stack sangat umum dalam pemanggilan fungsi dan proses rekursi, karena setiap fungsi yang dipanggil akan disimpan sebagai frame baru di dalam stack eksekusi [1]. Dalam penggunaannya, terdapat dua kondisi penting yang harus dihindari yaitu **stack underflow**, yaitu saat operasi pop dilakukan pada stack kosong, serta **stack overflow**, yaitu ketika operasi push dilakukan padahal kapasitas stack sudah penuh [2].

Karakteristik stack sangat dipengaruhi oleh aturan LIFO. Operasi yang biasa digunakan antara lain **push**, **pop**, **peek/top**, **isEmpty**, dan **size**, yang semuanya dilakukan dari satu ujung stack [1]. Tidak seperti struktur data lain, stack tidak mendukung akses acak sehingga untuk mengambil elemen tertentu, elemen-elemen di atasnya harus dikeluarkan terlebih dahulu. Stack dapat diimplementasikan menggunakan **array** atau **linked list**, tergantung kebutuhan ruang dan fleksibilitas struktur [1]. Berdasarkan kapasitas penyimpanan, stack dibedakan menjadi **register stack** yang berkapasitas kecil dan **memory stack** yang dapat menampung lebih banyak elemen karena pemanfaatan memori yang lebih luas [2]. Stack banyak digunakan dalam berbagai algoritma seperti Tower of Hanoi, tree traversal, dan mekanisme rekursi. Dalam penerapannya, prinsip **LIFO**, operasi pada satu ujung tumpukan, serta risiko **overflow** dan **underflow** menjadi ciri penting yang membedakan stack dari struktur data lainnya [2].

## Guided

### 1. Stack dengan Linked List
#### stack.h
```C++
#ifndef STACK_H
#define STACK_H
#define Nil NULL    

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif 
```

#### stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

#### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
Program C++ ini mengelola sebuah stack dengan memanfaatkan struktur Linked List. Stack bekerja menggunakan prinsip LIFO (Last In, First Out), yaitu elemen yang masuk paling akhir akan diambil terlebih dahulu. Implementasi ini menggunakan pointer untuk menghubungkan setiap node, di mana setiap node berisi sebuah nilai dan pointer yang mengarah ke node berikutnya. Program ini juga menyediakan beberapa fungsi inti seperti createStack() untuk inisialisasi, alokasi() untuk membuat node baru, push() untuk menambahkan elemen, pop() untuk menghapus elemen teratas, update() untuk memperbarui nilai pada posisi tertentu, view() untuk menampilkan semua elemen, dan searchData() untuk mencari nilai yang ada di dalam stack.

### 2. Stack dengan Array (Membalik Stack)
#### stack.h
```C++
#ifndef STACK_H
#define STACK_H
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct stack {
    infotype info[MaxEl];//Array unutk menyimpan elemen stack
    int top;
};

void createStack(stack &S);
bool isEmpty(stack S);
bool isFull(stack S);
void push(stack &S, infotype X); //Menambahkan elemen ke dalam stack
infotype pop(stack &S); //Mengambil elemn teratas dari stack
void printinfo(stack S); //Menampilkan isi stack
void balikStack(stack &S); //Membalik urutan elemen dalam stack
#endif
```
#### stack.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;
// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void createStack(stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printinfo(stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        stack temp1, temp2;  // Deklarasi dua stack temporary
        createStack(temp1); createStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}
```
#### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    stack S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printinfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printinfo(S);

    return 0;
}
```
Program C++ ini mengimplementasikan struktur data stack menggunakan array statis dengan kapasitas maksimal 20 elemen. Stack tetap bekerja berdasarkan prinsip LIFO, sehingga elemen terakhir yang masuk menjadi elemen pertama yang diambil. Program menyediakan fungsi untuk menambah elemen, menghapus elemen teratas, menampilkan isi stack, serta membalik urutannya, sehingga menunjukkan cara kerja stack berbasis array secara ringkas dan teratur.

## Unguided 

### 1. Push, Pop, Balik Stack
#### stack.h
```C++
#ifndef STACK1_H
#define STACK1_H

#define MaxEl 20
typedef int infotype;

struct Stack {
    infotype info[MaxEl];
    int top;
};

void createStack(Stack &S);
bool isEmpty(const Stack &S);
bool isFull(const Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);

#endif // STACK1_H
```
#### stack.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(const Stack &S) {
    return S.top == -1;
}

bool isFull(const Stack &S) {
    return S.top == MaxEl - 1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh\n";
    }
}

infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        cout << "Stack kosong\n";
        return -1;
    }
}

void printInfo(const Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong\n";
        return;
    }
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; --i) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack T;
    createStack(T);
    while (!isEmpty(S)) {
        push(T, pop(S));
    }
    S = T;
}
```
#### main.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    printInfo(S);

    cout << "balik stack\n";
    balikStack(S);
    printInfo(S);

    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Output Program 1](https://github.com/mhmmdffzz/StrukturData-Muhammad-Fauzan/blob/main/Pertemuan7_Modul7/LAPRAK/Muhammad_Fauzan-Output-Unguided1.png)

Program C++ ini membuat sebuah stack berbasis array dan menjalankan operasi dasar seperti menambah data, menghapus data, menampilkan isi, dan membalik urutan elemen. Program mulai dengan membentuk stack kosong, lalu memasukkan beberapa nilai sesuai urutan yang sudah ditentukan. Setelah itu sebagian nilai diambil kembali menggunakan operasi pop. Program menampilkan seluruh isi stack, kemudian membalik susunan elemen menggunakan stack bantu untuk menunjukkan perubahan posisi data.

### 2. Push Ascending
#### stack.h
```C++
#ifndef STACK2_H
#define STACK2_H

#define MaxEl 20
typedef int infotype;

struct Stack {
    infotype info[MaxEl];
    int top;
};

void createStack(Stack &S);
bool isEmpty(const Stack &S);
bool isFull(const Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);

#endif // STACK2_H
```
#### stack.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) { S.top = -1; }
bool isEmpty(const Stack &S) { return S.top == -1; }
bool isFull(const Stack &S) { return S.top == MaxEl - 1; }

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh\n";
    }
}

infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        cout << "Stack kosong\n";
        return -1;
    }
}

void printInfo(const Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong\n";
        return;
    }
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; --i) cout << S.info[i] << " ";
    cout << endl;
}

void balikStack(Stack &S) {
    Stack T;
    createStack(T);
    while (!isEmpty(S)) push(T, pop(S));
    S = T;
}

void pushAscending(Stack &S, infotype x) {
    Stack Temp;
    createStack(Temp);

    while (!isEmpty(S) && S.info[S.top] > x) {
        push(Temp, pop(S));
    }

    push(S, x);

    while (!isEmpty(Temp)) {
        push(S, pop(Temp));
    }
}
```
#### main.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    printInfo(S);

    cout << "balik stack\n";
    balikStack(S);
    printInfo(S);

    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Output Program 1](https://github.com/mhmmdffzz/StrukturData-Muhammad-Fauzan/blob/main/Pertemuan7_Modul7/LAPRAK/Muhammad_Fauzan-Output-Unguided2.png)

Program C++ ini menambahkan aturan penyisipan terurut dalam stack melalui fungsi pushAscending. Setiap nilai yang dimasukkan akan ditempatkan pada posisi yang benar agar isi stack tersusun naik tanpa memerlukan proses pengurutan tambahan. Program memakai stack sementara untuk menampung elemen yang lebih besar dari nilai baru. Setelah nilai baru berada pada posisi yang tepat, elemen yang disimpan sementara dikembalikan lagi ke stack utama. Hasil akhirnya menunjukkan susunan data yang selalu teratur sebelum dan sesudah proses pembalikan dilakukan.

### 3. Input Stream
#### stack.h
```C++
#ifndef STACK3_H
#define STACK3_H

#define MaxEl 20
typedef int infotype;

struct Stack {
    infotype info[MaxEl];
    int top;
};

void createStack(Stack &S);
bool isEmpty(const Stack &S);
bool isFull(const Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);
void getInputStream(Stack &S); // baca satu baris, tiap digit menjadi satu angka

#endif // STACK3_H
```
#### stack.cpp
```C++
#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

void createStack(Stack &S) { S.top = -1; }
bool isEmpty(const Stack &S) { return S.top == -1; }
bool isFull(const Stack &S) { return S.top == MaxEl - 1; }

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh\n";
    }
}

infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        cout << "Stack kosong\n";
        return -1;
    }
}

void printInfo(const Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong\n";
        return;
    }
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; --i) cout << S.info[i] << " ";
    cout << endl;
}

void balikStack(Stack &S) {
    Stack T;
    createStack(T);
    while (!isEmpty(S)) push(T, pop(S));
    S = T;
}

void getInputStream(Stack &S) {
    string line;
    cout << "";

    getline(cin, line);
    if (line.size() == 0) getline(cin, line);

    for (char c : line) {
        if (c >= '0' && c <= '9') push(S, c - '0');
    }
}
```
#### main.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    createStack(S);

    getInputStream(S);

    printInfo(S);

    cout << "balik stack\n";
    balikStack(S);
    printInfo(S);

    return 0;
}
```

### Output Unguided 3 :

##### Output 1
![Output Program 1](https://github.com/mhmmdffzz/StrukturData-Muhammad-Fauzan/blob/main/Pertemuan7_Modul7/LAPRAK/Muhammad_Fauzan-Output-Unguided3.png)

Program C++ ini membaca satu baris masukan dari pengguna dan memasukkan setiap karakter angka ke dalam stack. Setiap digit yang terbaca diubah menjadi bilangan lalu disimpan dalam urutan masuknya. Setelah input selesai diproses, program menampilkan isi stack dan kemudian membalik urutannya dengan fungsi balikStack. Proses ini memperlihatkan bagaimana data dari input pengguna dapat disimpan, diolah, dan disusun ulang menggunakan konsep stack.

## Kesimpulan
Pada praktikum ini dipelajari konsep dan penerapan struktur data Stack sebagai salah satu bentuk ADT yang bekerja dengan prinsip LIFO. Melalui beberapa latihan, digunakan berbagai operasi seperti push, pop, pembalikan urutan elemen, penyisipan data secara terurut, serta pembacaan input pengguna. Setiap operasi menunjukkan bagaimana data diatur dan diproses melalui satu titik akses, sehingga memberi pemahaman yang jelas tentang alur masuk dan keluarnya elemen dalam stack. Praktikum ini juga membantu melihat bagaimana perubahan pada stack terjadi secara bertahap sesuai perintah yang diberikan.

Melalui implementasi program C++, diperoleh gambaran bahwa struktur Stack memiliki keunggulan dalam kesederhanaan dan efisiensi ketika pengolahan data hanya membutuhkan satu arah akses. Penggunaan stack juga relevan untuk berbagai kebutuhan seperti mekanisme undo, evaluasi ekspresi, navigasi data, dan proses rekursif. Praktikum ini menegaskan pentingnya memahami cara kerja setiap operasi pada stack agar pengelolaan data tetap teratur dan sesuai tujuan, serta memberikan dasar kuat untuk mempelajari struktur data lain yang lebih kompleks.

## Referensi  
[1]. CodePolitan. (2023). **Apa Itu Stack dalam Ilmu Pemrograman?**  
Materi membahas konsep stack, operasinya, dan contoh implementasi dalam pemrograman.  
HTML: https://www.codepolitan.com/blog/apa-itu-stack-dalam-ilmu-pemrograman/

[2]. Trivusi. (2022, Juli). **Struktur Data Stack**.  
Penjelasan teori stack, karakteristik LIFO, serta contoh penggunaan sehari-hari dan dalam algoritma.  
HTML: https://www.trivusi.web.id/2022/07/struktur-data-stack.html
