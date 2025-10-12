#include <iostream>

using namespace std;

int main() {
    // 1) Buat 3 variabel integer
    int panjang = 10;
    int lebar = 5;
    int luas = 0;
    int keliling = 0;

    // Menampilkan Nilai Awal
    cout << "--- Nilai Awal ---" << endl;
    cout << "Panjang: " << panjang << endl;
    cout << "Lebar: " << lebar << endl;

    // 2) Deklarasikan dua pointer
    int *ptrPanjang = &panjang;
    int *ptrLebar = &lebar;

    // 3) Hitung luas dan keliling menggunakan pointer
    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    // 4) Cetak nilai luas dan keliling
    cout << "\n--- Hasil Perhitungan ---" << endl;
    cout << "Luas Persegi Panjang: " << luas << endl;
    cout << "Keliling Persegi Panjang: " << keliling << endl;

    // 5) Ubah nilai panjang dan lebar melalui pointer
    *ptrPanjang = 12;
    *ptrLebar = 6;

    // Hitung kembali luas dan keliling dengan nilai baru
    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    // 6) Cetak nilai panjang dan lebar yang baru
    cout << "\n--- Nilai Setelah Diubah Melalui Pointer ---" << endl;
    cout << "Panjang Baru: " << panjang << endl;
    cout << "Lebar Baru: " << lebar << endl;
    cout << "Luas Baru: " << luas << endl;
    cout << "Keliling Baru: " << keliling << endl;

    return 0;
}
