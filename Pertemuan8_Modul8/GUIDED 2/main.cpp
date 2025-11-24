#include<iostream>
#include "queue.h"
using namespace std;

int main() {
    Queue Q;
    createQueue(Q);
    printInfo(Q);

    cout<<"\n enqueue 3 elemen"<< endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);
    cout<<"\n dequeue 1 elemen"<< endl;
    cout<<"elemen keluar"<< dequeue(Q)<< endl;
    printInfo(Q);
    cout<<"\n enqueue 1 elemen"<< endl;
    enqueue(Q, 4);
    printInfo(Q);
    cout<<"\n dequeue 2 elemen"<<endl;
    cout<< "elemen keluar"<< dequeue(Q) <<endl;
    cout<< "elemen keluar"<<dequeue(Q)<< endl;
    printInfo(Q);
    return 0;

}