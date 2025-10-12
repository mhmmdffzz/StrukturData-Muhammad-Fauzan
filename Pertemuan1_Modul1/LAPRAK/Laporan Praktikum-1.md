# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Muhammad Fauzan - 103112400064</p>

## Dasar Teori
Pada pengenalan C++, praktik laboratorium umumnya memperkenalkan struktur program, tipe data, operator aritmetika/relasional, kendali alur (if/else, switch, for/while/do-while), serta I/O konsol melalui std::cin-std::cout pada <iostream>; penggunaan media pembelajaran yang memuat sejarah C++, struktur program, operasi aritmetika, percabangan, perulangan, hingga string dan fungsi dilaporkan membantu pemahaman materi pada tahap awal [1]. Pengembangan e-modul pemrograman dasar dengan metode R&D dinyatakan layak digunakan menurut validasi ahli dan uji coba pengguna sehingga relevan untuk pembelajaran terstruktur [2]. Berdasarkan usability testing, perbaikan antarmuka pada aplikasi Learn C++ membuat tugas lebih mudah diselesaikan, langkah interaksi lebih sedikit, dan pengalaman pengguna lebih memuaskan [3]. Dalam praktik pengembangan, pemakaian Integrated Development Environment (IDE) seperti Code::Blocks mempermudah penulisan, manajemen proyek, kompilasi, dan debugging dalam satu lingkungan terpadu, sehingga uji coba program menjadi lebih efisien baik pada konteks pembelajaran maupun penerapan C++ pada pengembangan alat [4][5].
## Guided 

### 1. Input/Output Dasar

```C++
#include<iostream>
using namespace std;

int main() {
    int angka;
    cout << "Masukkan angka pertama: ";
    cin >> angka;
    cout << "Masukkan yang dimaskukan adalah " << angka << endl;
    return 0;
}
```
Program C++ sederhana yang meminta pengguna untuk memasukkan sebuah angka. Setelah angka dimasukkan, program akan menampilkan kembali angka tersebut ke layar.

### 2. Kalkulator Aritmatika Dasar

```C++
#include<iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    cout << "penjumlahan: " << angka1 + angka2 << endl;
    cout << "pengurangan: " << angka1 - angka2 << endl;
    cout << "perkalian: " << angka1 * angka2 << endl;
    cout << "pembagian: " << angka1 / angka2 << endl;
    cout << "modulus: " << angka1 % angka2 << endl;

    return 0;
}
```
Kalkulator sederhana yang melakukan operasi aritmatika dasar.

### 3. Percabangan If/Else & Switch Menu

```C++
#include<iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    if (angka1 > angka2 ) {
        cout << angka1 << " kurang dari " << angka2 << endl;
    } else {
        cout << angka1 << " lebih dari " << angka2 << endl;
    }

    if (angka1 == angka2) {
        cout << angka1 << " sama dengan " << angka2 << endl;
    } else if (angka1 != angka2) {
        cout << " angka berbeda " << endl;
    }

     int pilihan;
    cout << "MENU" << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "masukan pilihan: ";
    cin >> pilihan;

    switch (Pilihan){
        case 1:
        cout << "Penjumlahan :" << angka1 + angka2 << endl;
        cout << endl;
        break; 
        case 2:
        cout << "Pengurangan :" << angka1 - angka2 << endl;
        cout << endl;
        break;
        default:
        cout << "Pilihan Salah" << endl;

    }
    return 0;
}
```
Program C++ yang menunjukkan cara kerja pengambilan keputusan dalam kode.

### 4. Tiga Jenis Perulangan

```C++
#include <iostream>
using namespace std;

 int main(){
    int angka1;
    cout << "masukan angka1 : ";
    cin >> angka1;

    for (int i = 0; i  < angka1; i++){
      cout << i << " - ";
    }
    cout << endl;

    int j = 10;
    while (j > angka1){
      cout << j << " - ";
      j--;
    }

    cout << endl;
    int k = 10;
    do {
      cout << k << " - ";
    }while (k < angka1);

     return  0;
    
 }
```
Sebuah program C++ yang mendemonstrasikan tiga jenis perulangan (loop) dasar: for, while, dan do-while.

### 5. Array & Struct Rapor Siswa

```C++
#include<iostream>
using namespace std;

int main(){
    const int MAX = 5;
    struct rapot{
        string nama;
        float nilai;
    };
    rapot siswa[MAX];

    for(int i = 0; i < MAX; i++){
        cout << "masukkan nama siswa : ";
        cin >> siswa[i].nama;
        cout << endl;
        cout << "masukkan nilai siswa : ";
        cin >> siswa[i].nilai;
    }

    int j = 0;
    while(j < MAX){
        cout << "nama siswa : " << siswa[j].nama << ", nilai : " << siswa[j].nilai << endl;
        j++;
    }
    return 0;
}

```
Program C++ yang dirancang untuk menyimpan dan menampilkan data rapor sederhana untuk beberapa siswa.

## Unguided 

### 1. Kalkulator Empat Operasi

```C++
#include<iostream>
using namespace std;

int main() {
    float angka1, angka2;
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    cout << "penjumlahan: " << angka1 + angka2 << endl;
    cout << "pengurangan: " << angka1 - angka2 << endl;
    cout << "perkalian: " << angka1 * angka2 << endl;
    cout << "pembagian: " << angka1 / angka2 << endl;

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Output Program 1](https://github.com/mhmmdffzz/103112400064_Muhammad-Fauzan/blob/main/Pertemuan1_Modul1/LAPRAK/Muhammad_Fauzan-Output-Unguided1.png)

program C++ ini adalah sebuah kalkulator sederhana yang melakukan empat operasi matematika dasar (tambah, kurang, kali, bagi) terhadap dua angka yang dimasukkan oleh pengguna.

### 2. Konversi Bilangan 0–100 menjadi Teks

```C++
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
```
### Output Unguided 2 :

##### Output 1
![Output Program 2](https://github.com/mhmmdffzz/103112400064_Muhammad-Fauzan/blob/main/Pertemuan1_Modul1/LAPRAK/Muhammad_Fauzan-Output-Unguided2.png)

Program C++ ini berfungsi untuk Mengonversi angka 0–100 menjadi teks Bahasa Indonesia menggunakan array satuan, belasan, dan puluhan.

### 3. Pola Iterasi Bertingkat

```C++
#include <iostream>
using namespace std;

int main() {
    int N;                                  // Variabel untuk menyimpan tinggi pola
    cout << "Masukkan angka: ";
    cin >> N;                               // Meminta input

    // Loop untuk mencetak bagian utama pola, dari baris teratas (r=N) hingga (r=1)
    for (int r = N; r >= 1; --r) {
        // Cetak spasi di awal setiap baris untuk membuat bentuk segitiga dan alignment
        // Jumlah spasi adalah 2 * (N - r) agar posisi bintang (*) selalu di tengah
        for (int sp = 0; sp < 2 * (N - r); ++sp) {
            cout << " ";
        }

        // Cetak angka secara menurun dari r hingga 1
        for (int i = r; i >= 1; --i) {
            cout << i << " ";
        }

        // Cetak bintang (*) di tengah baris
        cout << "*";

        // Cetak angka secara menaik dari 1 hingga r
        for (int i = 1; i <= r; ++i) {
            cout << " " << i;
        }
        cout << endl;       // Pindah ke baris baru setelah satu baris selesai
    }

    // Cetak bagian bawah pola (garis vertikal dari bintang)
    // Cetak spasi untuk menempatkan bintang di kolom tengah
    for (int s = 0; s < 2 * N; ++s) {
        cout << " ";
    }
    cout << "*" << endl;                    // Cetak bintang terakhir

    return 0;                               // Mengakhiri program
}
```
### Output Unguided 3 :

##### Output 1
![Output Program 3](https://github.com/mhmmdffzz/103112400064_Muhammad-Fauzan/blob/main/Pertemuan1_Modul1/LAPRAK/Muhammad_Fauzan-Output-Unguided3.png)

Program C++ ini berfungsi untuk mencetak pola piramida terbalik yang simetris angka menurun, tanda * di tengah, lalu angka menaik dengan perataan tengah menggunakan spasi.

## Kesimpulan
Setelah menyelesaikan Modul 1 - Code::Blocks IDE & Pengenalan C++, pemahaman berfokus pada alur kerja pengembangan di Code::Blocks (pembuatan proyek, kompilasi, eksekusi, dan peninjauan hasil) serta konsep-konsep fundamental dalam bahasa pemrograman C++.

pembelajaran ini telah memberikan kemampuan untuk:
* **Manajemen proyek di Code::Blocks:** membuat proyek, *compile*, *run*, membaca pesan kompilator, dan *debugging* dasar.
* **Dasar C++:** struktur program, deklarasi variabel/konstanta, pemilihan tipe data.
* **Operator esensial:** aritmetika, logika, dan penugasan untuk manipulasi data.
* **Struktur kondisional:** pengambilan keputusan dengan `if–else` dan `switch`.
* **Perulangan:** implementasi `for`, `while`, dan `do–while`.
* **Struktur data sederhana:** pengelompokan data menggunakan `struct`.
* **Penerapan pada tugas:** kalkulator empat operasi, konversi angka 0–100 menjadi teks, dan pola angka–`*`–angka simetri (*nested loop*).


## Referensi
[1] Dewi, L. J. E. (2010). Media pembelajaran bahasa pemrograman C++. Jurnal Pendidikan Teknologi dan Kejuruan (Undiksha), 7(1), 63–72.
Halaman artikel: https://ejournal.undiksha.ac.id/index.php/JPTK/article/view/31
PDF: https://ejournal.undiksha.ac.id/index.php/JPTK/article/download/31/25/94
<br>[2]Prasetyoadi, E. B., Rokhmawati, R. I., & Wicaksono, S. A. (2019). Pengembangan e-modul pembelajaran “Pemrograman Dasar” dengan metode R&D (Studi SMKN 4 Malang). Jurnal Pengembangan Teknologi Informasi dan Ilmu Komputer (J-PTIIK), 3(10), 10118–10129.
Halaman artikel: https://j-ptiik.ub.ac.id/index.php/j-ptiik/article/view/6646
PDF: https://j-ptiik.ub.ac.id/index.php/j-ptiik/article/download/6646/3193/46603
<br>[3] Asprila, D. A., Wijoyo, S. H., & Az-Zahra, H. M. (2021). Evaluasi usability pada aplikasi Learn C++ (usability testing). Jurnal Pengembangan Teknologi Informasi dan Ilmu Komputer (J-PTIIK), 5(6), 2677–2686.
Halaman artikel: https://j-ptiik.ub.ac.id/index.php/j-ptiik/article/view/9392
PDF: https://j-ptiik.ub.ac.id/index.php/j-ptiik/article/download/9392/4217/66090
<br>[4] Sano, A. N. A. (2020). PENGENALAN CODE::BLOCKS. Academia.edu.
Halaman: https://www.academia.edu/44359359/PENGENALAN_CODE_BLOCKS
<br>[5] Effendi, Q. M. F. Z., dkk. (2024). Penerapan Pemrograman C++ dalam Pengembangan Alat. Jurnal Majemuk, 3(1).
Halaman artikel: https://jurnalilmiah.org/journal/index.php/majemuk/article/view/665