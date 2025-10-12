#include <iostream>
using namespace std;

void jumlahMatriks(int arrA[3][3], int arrB[3][3], int arrC[3][3]){
    for (int i = 0; i < 3; i++){        //Perulangan baris
        for (int j = 0; j < 3; j++){    //Perulangan kolom
            arrC[i][j] = arrA[i][j] + arrB[i][j];   
        }
    }
    cout << "Hasil Penjumlahan: " << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << arrC[i][j] << " ";
        }
        cout << endl;
    }
}
void kurangMatriks(int arrA[3][3], int arrB[3][3], int arrC[3][3]){
    for (int i = 0; i < 3; i++){            //Perulangan baris 
        for (int j = 0; j < 3; j++){        //Perulangan kolom
            arrC[i][j] = arrA[i][j] - arrB[i][j];
        }
    }
    cout << "Hasil Pengurangan: " << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << arrC[i][j] << " ";
        }
        cout << endl;
    }
}
void kaliMatriks(int arrA[3][3], int arrB[3][3], int arrC[3][3]){
    for (int i = 0; i < 3; i++){            //Perulangan baris 
        for (int j = 0; j < 3; j++){        //Perulangan kolom  
            for (int k = 0; k < 3; k++){    //Perulangan perkalian
                arrC[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }
    cout << "Hasil Perkalian: " << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << arrC[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arrA[3][3] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };
    int arrB[3][3] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };
    int arrC[3][3] = {0};
    int pilihan;

    do {
        cout << "--- Menu Program Matriks ---" << endl;
        cout << "1. Penjumlahan matriks" << endl;
        cout << "2. Pengurangan matriks" << endl;
        cout << "3. Perkalian matriks" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukkan pilihan Anda (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                jumlahMatriks(arrA, arrB, arrC);
                break;
            case 2:
                kurangMatriks(arrA, arrB, arrC);
                break;
            case 3:
                kaliMatriks(arrA, arrB, arrC);
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
        cout << endl; // Tambahkan baris kosong untuk pemisah antar menu
    } while (pilihan != 4);

    return 0;
}
