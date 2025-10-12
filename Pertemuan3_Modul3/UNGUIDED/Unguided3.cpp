#include <iostream>

using namespace std;

// Fungsi untuk menampilkan isi array 2D
void tampilkanArray(const int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Fungsi untuk menukar isi dari 2 array 2D pada posisi tertentu
void tukarArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

// Fungsi untuk menukar isi dari variabel yang ditunjuk oleh 2 buah pointer
void tukarPointer(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    // 2 buah array 2D integer berukuran 3x3
    int arrayA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arrayB[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int baris, kolom;

    cout << "Array A Awal:" << endl;
    tampilkanArray(arrayA);
    cout << "Array B Awal:" << endl;
    tampilkanArray(arrayB);
    cout << endl;

    // Meminta input dari pengguna
    cout << "Masukkan posisi yang akan ditukar:" << endl;
    cout << "Baris (1-3): ";
    cin >> baris;
    cout << "Kolom (1-3): ";
    cin >> kolom;

    // Validasi input
    if (baris >= 1 && baris <= 3 && kolom >= 1 && kolom <= 3) {
        cout << "\nMenukar nilai pada posisi [" << baris << "][" << kolom << "]..." << endl;
        cout << "Nilai awal: Matriks A = " << arrayA[baris-1][kolom-1] << ", Matriks B = " << arrayB[baris-1][kolom-1] << endl;

        // Menukar nilai (konversi dari 1-based ke 0-based index)
        tukarArray(arrayA, arrayB, baris-1, kolom-1);

        cout << "\nArray A Setelah Ditukar:" << endl;
        tampilkanArray(arrayA);
        cout << "Array B Setelah Ditukar:" << endl;
        tampilkanArray(arrayB);
    } else {
        cout << "Posisi yang dimasukkan tidak valid." << endl;
    }

    return 0;
}
