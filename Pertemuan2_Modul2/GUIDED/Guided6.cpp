#include<iostream>
using namespace std;

int cariMAX(int arr[], int ukuran) {
    int max = arr[0]; // Inisialisasi nilai maksimum dengan elemen pertama
    for (int i = 1; i < ukuran; i++) {
        if (arr[i] > max) {
            max = arr[i]; // Update nilai maksimum jika ditemukan elemen yang lebih besar
        }
    }
    return max;
}

void operasiAritmatika(int arr[], int ukuran){
    int totaljumlah = 0;
    for(int i = 0; i < ukuran; i++){
        totaljumlah += arr[i];
    }  
    cout << "Total Penjumlahan: " << totaljumlah << endl;
    
    int totalkali = 1;
    for(int i = 0; i < ukuran; i++){
        totalkali *= arr[i];
    }
    cout << "Total Perkalian: " << totalkali << endl;
}

int main(){
    const int ukuran = 5;
    int arr[ukuran];
    for(int i = 0; i < ukuran; i++){
        cout << "Masukkan nilai array ke-" << i << ": ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "Nilai terbesar dalam array: " << cariMAX(arr, ukuran) << endl;
    
    operasiAritmatika(arr, ukuran);
    return 0;
}