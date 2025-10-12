#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3f*uts + 0.4f*uas + 0.3f*tugas;
}

int main() {
    Mahasiswa m[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (1-10): ";
    cin >> n;
    if (n < 1) return 0;
    if (n > 10) n = 10;

    for (int i = 0; i < n; i++) {
        cout << "\nData Mahasiswa ke-" << (i+1) << endl;
        cout << "Nama  : ";
        cin >> m[i].nama;     // sederhana: tidak pakai spasi
        cout << "NIM   : ";
        cin >> m[i].nim;
        cout << "UTS   : ";
        cin >> m[i].uts;
        cout << "UAS   : ";
        cin >> m[i].uas;
        cout << "Tugas : ";
        cin >> m[i].tugas;

        m[i].nilaiAkhir = hitungNilaiAkhir(m[i].uts, m[i].uas, m[i].tugas);
    }
    
    cout << "\n=== Daftar Nilai Akhir ===\n";
    for (int i = 0; i < n; i++) {
        cout << (i+1) << ". "
             << m[i].nim << "     "
             << m[i].nama << "     "
             << m[i].uts << "   "
             << m[i].uas << "   "
             << m[i].tugas << "   "
             << "   " << m[i].nilaiAkhir << "\n";
    }
    return 0;
}
