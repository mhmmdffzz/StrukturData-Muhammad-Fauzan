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