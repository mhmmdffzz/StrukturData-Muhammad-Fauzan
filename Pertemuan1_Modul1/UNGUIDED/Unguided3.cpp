#include <iostream>

// Menggunakan namespace std untuk kemudahan
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
