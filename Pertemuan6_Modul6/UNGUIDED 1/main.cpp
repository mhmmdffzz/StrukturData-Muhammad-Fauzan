#include "Doublylist.h"
#include <iostream>
#include <string>

using namespace std;

void requestInput(string& nopol, string& warna, int& tahun) {
    cout << "masukkan nomor polisi: ";
    cin >> nopol;
    cout << "masukkan warna kendaraan: ";
    cin >> warna;
    cout << "masukkan tahun kendaraan: ";
    while (!(cin >> tahun)) {
        cout << "Input tahun tidak valid. Masukkan angka: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

int main() {
    List L;
    CreateList(L);

    string nopol;
    string warna;
    int tahun;
    infotype dataBaru;
    address P;

    requestInput(nopol, warna, tahun);
    dataBaru = {nopol, warna, tahun};
    P = findElm(L, nopol);

    if (P == Nil) {
        address newElm = alokasi(dataBaru);
        insertLast(L, newElm);
    } else {
        cout << "nomor polisi sudah terdaftar\n";
    }

    requestInput(nopol, warna, tahun);
    dataBaru = {nopol, warna, tahun};
    P = findElm(L, nopol);

    if (P == Nil) {
        address newElm = alokasi(dataBaru);
        insertLast(L, newElm);
    } else {
        cout << "nomor polisi sudah terdaftar\n";
    }

    requestInput(nopol, warna, tahun);
    dataBaru = {nopol, warna, tahun};
    P = findElm(L, nopol);

    if (P == Nil) {
        address newElm = alokasi(dataBaru);
        insertLast(L, newElm);
    } else {
        cout << "nomor polisi sudah terdaftar\n";
    }

    // --- Input 4: D004, kuning, 90 ---
    requestInput(nopol, warna, tahun);
    dataBaru = {nopol, warna, tahun};
    P = findElm(L, nopol);

    if (P == Nil) {
        address newElm = alokasi(dataBaru);
        insertLast(L, newElm);
    } else {
        cout << "nomor polisi sudah terdaftar\n";
    }

    cout << "\nDATA LIST 1\n";
    printInfo(L);
    
    return 0;
}