# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">Muhammad Fauzan - 103112400064</p>

## Dasar Teori

### A. Abstract Data Type (ADT) <br/>

ADT adalah tipe data yang didefinisikan oleh pengguna berisi sekumpulan nilai serta operasi yang dapat dilakukan atas nilai tersebut. ADT menekankan abstraksi, yaitu detail implementasi disembunyikan dan yang diekspos hanya perilaku atau operasinya, sehingga pemrogram fokus pada apa yang dilakukan, bukan bagaimana cara diimplementasikan [3]. Dalam praktik pengembangan, pendekatan berorientasi objek dan modular memudahkan pendefinisian ADT sebagai entitas yang rapi dan dapat digunakan ulang [3].

### B. Struct dan Modularitas Program <br/>

`struct` pada C++ mengelompokkan beberapa atribut dengan tipe berbeda ke dalam satu entitas logis, misalnya entitas mahasiswa yang memiliki `nama` (string), `nim` (string), dan beberapa `nilai` (float). Berbeda dari array yang homogen, `struct` memungkinkan komposisi heterogen yang merepresentasikan objek dunia nyata secara ringkas. Pemisahan antarmuka dan implementasi melalui header `.h` dan source `.cpp` mengikuti prinsip information hiding, sehingga detail yang mudah berubah berada di balik antarmuka yang stabil. Dampaknya, kode lebih mudah diuji, dipelihara, dan dikembangkan [3].

### C. Fungsi dan Parameter Passing <br/>

Fungsi adalah blok kode yang menjalankan tugas spesifik dan dapat dipanggil berulang. Penggunaan fungsi meningkatkan modularitas, keterbacaan, kemudahan debugging, dan reusability. Di C++, parameter dapat dikirim by value atau by reference atau menggunakan pointer. Pemisahan deklarasi dan implementasi, misalnya prototipe di `.h` serta definisi di `.cpp`, membantu menjaga batas antarmuka dan mengurangi ketergantungan antarmodul [3].

### D. Array Multidimensi <br/>

Array multidimensi, misalnya matriks 2D `int a[baris][kolom]`, merepresentasikan data tabular yang diakses dengan dua indeks. Dalam konteks pembelajaran struktur data dan implementasi C atau C++, array 1D dan 2D digunakan luas, termasuk pada contoh implementasi struktur data dan studi komparatif kinerja, karena akses indeksnya langsung dan layout memorinya kontigu [1].

### E. Pointer <br/>

Pointer menyimpan alamat memori dari variabel lain. Di C atau C++, pointer memungkinkan pass by reference, manipulasi struktur data dinamis seperti linked list, serta efisiensi operasi tertentu. Praktik umum pada implementasi struktur data adalah penggunaan pointer untuk membangun node dan relasi antarelemen sehingga struktur bersifat dinamis dan fleksibel [1].

## Guided

### 1. Program Data Mahasiswa dengan Struct
#### Mahasiswa.h
```C++
#include<iostream>
using namespace std;
int main(){
    int arr [5];
    for (int i = 0; i < 5; i++){
        cout<<"Masukkan nilai indeks ke-"<<i<<": ";
        cin>>arr[i];
    }
    int j = 0;
    while (j < 5){
        cout<< "Isi indeks ke-"<< j <<" i "<< arr[j]<< endl;
        j++;
    }
    return 0;
}
```

#### Mahasiswa.cpp
```C++
#include <iostream>
#include "Mahasiswa.h"

using namespace std;

// Realisasi fungsi InputMhs
void inputMhs(mahasiswa &m) {
    cout << "Input NIM: "; 
    cin >> m.nim;
    cout << "Input Nilai 1: "; 
    cin >> m.nilai1;
    cout << "Input Nilai 2: "; 
    cin >> m.nilai2;
}

// Realisasi fungsi rata2
float rata2(mahasiswa m) {
    return (float)(m.nilai1 + m.nilai2) / 2;
}
```

#### Main.cpp
```C++
#include<iostream>
#include "Mahasiswa.h"
#include<cstdlib>

using namespace std;

int main () {
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "Rata-rata: " << rata2(mhs) << endl;
    system("pause");
    
    return 0;
}
```

Program C++ ini menggunakan struct dan fungsi untuk mengelola data mahasiswa, yang dipecah ke dalam tiga file: `Mahasiswa.h` (definisi struct), `Mahasiswa.cpp` (implementasi fungsi), dan `main.cpp` (program utama).

## Unguided 

### 1. Program Menghitung Nilai Akhir Mahasiswa
```C++
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
```
### Output Unguided 1 :

##### Output 1
![Output Program 1](https://github.com/mhmmdffzz/103112400064_Muhammad-Fauzan/blob/main/Pertemuan3_Modul3/LAPRAK/Muhammad_Fauzan-Output-Unguided1.png)

Program ini berfungsi untuk mengelola data nilai mahasiswa. Pengguna dapat memasukkan data untuk beberapa mahasiswa (nama, NIM, dan nilai), dan program akan menghitung nilai akhir berdasarkan bobot nilai UTS, UAS, dan tugas, lalu menampilkannya.

### 2. Program Struct untuk Data Mata Pelajaran
```C++
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
```
### Output Unguided 2 :

##### Output 1
![Output Program 2](https://github.com/mhmmdffzz/103112400064_Muhammad-Fauzan/blob/main/Pertemuan3_Modul3/LAPRAK/Muhammad_Fauzan-Output-Unguided2.png)

Program ini mendemonstrasikan penggunaan struct dan fungsi untuk mengelola data mata pelajaran. Sebuah struct `pelajaran` digunakan untuk menyimpan nama dan kode mapel, yang kemudian diinisialisasi dan ditampilkan melalui fungsi terpisah.

### 3. Program Penukaran Elemen Matriks
```C++
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
    cout << "Baris (0-2): ";
    cin >> baris;
    cout << "Kolom (0-2): ";
    cin >> kolom;

    // Validasi input
    if (baris >= 0 && baris < 3 && kolom >= 0 && kolom < 3) {
        cout << "\nMenukar nilai pada posisi [" << baris << "][" << kolom << "]..." << endl;
        cout << "Nilai awal: Matriks A = " << arrayA[baris][kolom] << ", Matriks B = " << arrayB[baris][kolom] << endl;

        // Menukar nilai
        tukarArray(arrayA, arrayB, baris, kolom);
        cout << "\nArray A Setelah Ditukar:" << endl;
        tampilkanArray(arrayA);
        cout << "Array B Setelah Ditukar:" << endl;
        tampilkanArray(arrayB);
    } else {
        cout << "Posisi yang dimasukkan tidak valid." << endl;
    }

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Output Program 3](https://github.com/mhmmdffzz/103112400064_Muhammad-Fauzan/blob/main/Pertemuan3_Modul3/LAPRAK/Muhammad_Fauzan-Output-Unguided3.png)

Program ini mendemonstrasikan penukaran elemen antara dua matriks 2D berukuran 3x3. Pengguna memasukkan posisi (baris dan kolom), dan program akan menukar nilai pada posisi tersebut di kedua matriks, lalu menampilkan hasilnya.

## Kesimpulan
Praktikum ini membahas konsep lanjutan C++, meliputi penggunaan struct untuk pengelompokan data, fungsi untuk modularisasi kode, dan manipulasi array multidimensi. Tujuannya adalah memahami pengorganisasian data terstruktur dan penggunaan kembali kode melalui fungsi.

## Referensi 

[1]. Setiyawan, R. D., Hermawan, D., Abdillah, A. F., Mujayanah, A., & Vindua, R. (2024). Penggunaan struktur data stack dalam pemrograman C++ dengan pendekatan array dan linked list. *JUTECH: Journal Education and Technology, 5*(2), 484-497).
   **PDF:** [Unduh](https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/download/4263/pdf)  **Laman jurnal:** [JUTECH](https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263)

[2]. Munir, A. Q. (2011). Perancangan sistem informasi geografis penentuan jalur jalan optimum Kodya Yogyakarta menggunakan algoritma Dijkstra. *Jurnal Informatika Mulawarman, 6*(2), 80-84).
   **PDF:** [Unduh](https://e-journals.unmul.ac.id/index.php/JIM/article/download/73/pdf)  **Laman jurnal:** [Jurnal Informatika Mulawarman](https://e-journals.unmul.ac.id/index.php/JIM/article/view/73)

[3]. Putra, R. R. C., Sari, F., & Yulian, R. (2019). Aplikasi peminjaman ruangan rapat Kantor Gubernur Provinsi Kepulauan Bangka Belitung berbasis web. *Jurnal SISFOKOM, 8*(2), 190-197). [https://doi.org/10.32736/sisfokom.v8i2.688](https://doi.org/10.32736/sisfokom.v8i2.688)
   **PDF:** [Unduh](https://jurnal.atmaluhur.ac.id/index.php/sisfokom/article/download/688/598)  **Laman jurnal:** [SISFOKOM](https://jurnal.atmaluhur.ac.id/index.php/sisfokom/article/view/688)

