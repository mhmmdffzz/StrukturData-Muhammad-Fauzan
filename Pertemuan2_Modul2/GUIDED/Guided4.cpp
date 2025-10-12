#include<iostream>
using namespace std;

void ubahNilai(int *p){
    *p = 20; //mengubah nilai yang ditunjuk oleh pointer
}
int main(){
    int x = 10;
    cout<<"Nilai x sebelum diubah: "<< x <<endl;

    ubahNilai(&x); //mengirim alamat memori x ke fungsi
    cout<<"Nilai x setelah diubah: "<< x <<endl;
    return 0;
}