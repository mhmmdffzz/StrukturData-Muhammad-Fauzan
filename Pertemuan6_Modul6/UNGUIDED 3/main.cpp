#include "Doublylist.h"
#include <iostream>

using namespace std;

int main() {
    List L;
    CreateList(L);
    address P;
    infotype data;

    data = {"D001", "hitam", 90}; P = alokasi(data); insertLast(L, P);
    data = {"D003", "putih", 70}; P = alokasi(data); insertLast(L, P);
    data = {"D004", "kuning", 90}; P = alokasi(data); insertLast(L, P);

    string hapusNopol;
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapusNopol;

    address beforeDelete = findElm(L, hapusNopol);
    if (beforeDelete != Nil) {
        deleteByNopol(L, hapusNopol);
        cout << endl << "DATA LIST 1" << endl;
        printInfo(L);
    } else {
        cout << "Nomor Polisi " << hapusNopol << " tidak ditemukan." << endl;
    }

    return 0;
}
