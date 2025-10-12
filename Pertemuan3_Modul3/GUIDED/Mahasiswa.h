#ifndef MAHASISWA_H
#define MAHASISWA_H

//Definisi tipe (struct)
struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

//Deklarasi Primitif (Fungsi)
void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif
