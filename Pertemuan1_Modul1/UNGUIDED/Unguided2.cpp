#include <iostream>
#include <string> 

using namespace std;

int main() {
    int n;
    cout << "Masukkan angka (0 s.d 100): ";
    cin >> n;

    if (n < 0 || n > 100) {
        cout << "luar jangkauan!" << endl;
        return 0;
    }

    string hasil;
    // Indeks 0 dikosongkan agar indeks array sesuai dengan angkanya (misal: satuan[1] untuk "satu")
    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    // indeks 0 untuk sepuluh, indeks 1 untuk sebelas
    string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
    // Indeks 0 dan 1 dikosongkan karena puluhan dimulai dari 20
    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    if (n == 100) {
        hasil = "seratus";
    } else if (n == 0) {
        hasil = "nol";
    } else if (n < 10) {
        hasil = satuan[n];
    } else if (n < 20) {
        hasil = belasan[n - 10];
    } else { // n >= 20
        hasil = puluhan[n / 10];
        if (n % 10 != 0) {
            hasil += " " + satuan[n % 10];
        }
    }

    cout << hasil << endl;

    return 0;
}
