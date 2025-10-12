#include <iostream>
#include <string>

using namespace std;

// Isi dari pelajaran.h
struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

// Deklarasi fungsi dari pelajaran.h
pelajaran create_pelajaran(string namaMapel, string kodeMapel);
void tampil_pelajaran(pelajaran pel);

// Isi dari pelajaran.cpp
pelajaran create_pelajaran(string namaMapel, string kodeMapel) {
    pelajaran pel;
    pel.namaMapel = namaMapel;
    pel.kodeMapel = kodeMapel;
    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "kode mapel : " << pel.kodeMapel << endl;
}

// Isi dari main.cpp
int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
