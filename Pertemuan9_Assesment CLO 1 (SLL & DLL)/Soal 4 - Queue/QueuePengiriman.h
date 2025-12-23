<<<<<<< HEAD
#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H
#include <iostream>
#include <string>
using namespace std;

struct Paket {
    string KodeResi;
    string Nama Pengiriman;
    int Berat;  
    string Tujuan;
};

const int MAX = 5;

struct Queue ekspedisi {
    Paket dataPaket[MAX];
    int head;
    int tail;
};

bool isEmpty(QueueEkspedisi Q);
bool isFull(QueueEkspedisi Q);
void createQueue(QueueEkspedisi &Q);
void enqueue(QueueEkspedisi &Q, Paket P);
void dequeue(QueueEkspedisi &Q);
void viewQueue(QueueEkspedisi Q);
=======
#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H
#include <iostream>
#include <string>
using namespace std;

struct Paket {
    string KodeResi;
    string Nama Pengiriman;
    int Berat;  
    string Tujuan;
};

const int MAX = 5;

struct Queue ekspedisi {
    Paket dataPaket[MAX];
    int head;
    int tail;
};

bool isEmpty(QueueEkspedisi Q);
bool isFull(QueueEkspedisi Q);
void createQueue(QueueEkspedisi &Q);
void enqueue(QueueEkspedisi &Q, Paket P);
void dequeue(QueueEkspedisi &Q);
void viewQueue(QueueEkspedisi Q);
>>>>>>> c5f8b798a769c9cc7872b0796a5eae31e5e4aba7
#endif