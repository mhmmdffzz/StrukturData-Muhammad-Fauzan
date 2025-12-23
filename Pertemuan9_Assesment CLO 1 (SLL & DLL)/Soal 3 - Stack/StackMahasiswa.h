<<<<<<< HEAD
#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

const int MAX = 6;

struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX];
    int Top;
};

bool isEmpty(StackMahasiswa S);
bool isFull(StackMahasiswa S);
void createStack(StackMahasiswa &S);
void Push(StackMahasiswa &S, Mahasiswa M);
Mahasiswa Pop(StackMahasiswa &S);
void Update(StackMahasiswa &S, int pos);
void View(StackMahasiswa S);
void SearchNilaiAkhir(StackMahasiswa S, float minR, float maxR);
float HitungNilaiAkhir(Mahasiswa M);
void MaxNilaiAkhir(StackMahasiswa S); 
#endif
=======
#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

const int MAX = 6;

struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX];
    int Top;
};

bool isEmpty(StackMahasiswa S);
bool isFull(StackMahasiswa S);
void createStack(StackMahasiswa &S);
void Push(StackMahasiswa &S, Mahasiswa M);
Mahasiswa Pop(StackMahasiswa &S);
void Update(StackMahasiswa &S, int pos);
void View(StackMahasiswa S);
void SearchNilaiAkhir(StackMahasiswa S, float minR, float maxR);
float HitungNilaiAkhir(Mahasiswa M);
void MaxNilaiAkhir(StackMahasiswa S); 
#endif
>>>>>>> c5f8b798a769c9cc7872b0796a5eae31e5e4aba7
