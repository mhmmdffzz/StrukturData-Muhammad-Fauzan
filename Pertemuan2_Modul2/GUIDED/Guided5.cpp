#include<iostream>
using namespace std;

void ubahNilai(int& ref) {
    ref = 20; //Mengubah nilai melalui referensi
}

int main() {
    int x = 10;
    cout << "Nilai x sebelum diubah: " << x << endl;

    ubahNilai(x); //Mengirim variabel referensil ke x
    cout << "Nilai x setelah diubah: " << x << endl;

    return 0;
}