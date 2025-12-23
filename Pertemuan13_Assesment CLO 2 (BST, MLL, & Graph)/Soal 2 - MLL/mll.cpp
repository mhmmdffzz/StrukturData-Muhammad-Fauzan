#include "mll.h"
void createListParent(ListParent &LP) {
    LP.first = NULL;
    LP.last = NULL;
}
void createListChild(ListChild &LC) {
    LC.first = NULL;
    LC.last = NULL;
}
NodeParent* alokasiNodeParent(string id, string nama) {
    NodeParent *P = new NodeParent;
    P->idGenre = id;
    P->namaGenre = nama;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->childs);
    return P;
}
NodeChild* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating) {
    NodeChild *C = new NodeChild;
    C->idFilm = id;
    C->judulFilm = judul;
    C->durasiFilm = durasi;
    C->tahunTayang = tahun;
    C->ratingFilm = rating;
    C->next = NULL;
    C->prev = NULL;
    return C;
}
void dealokasiNodeParent(NodeParent *P) {
    delete P;
}
void dealokasiNodeChild(NodeChild *C) {
    delete C;
}
void insertFirstParent(ListParent &LP, NodeParent *P) {
    if (LP.first == NULL) {
        LP.first = P;
        LP.last = P;
    } else {
        P->next = LP.first;
        LP.first->prev = P;
        LP.first = P;
    }
}
void insertLastChild(ListChild &LC, NodeChild *C) {
    if (LC.first == NULL) {
        LC.first = C;
        LC.last = C;
    } else {
        C->prev = LC.last;
        LC.last->next = C;
        LC.last = C;
    }
}
void hapusListChild(ListChild &LC) {
    NodeChild *p = LC.first;
    while (p != NULL) {
        NodeChild *temp = p;
        p = p->next;
        dealokasiNodeChild(temp);
    }
    LC.first = NULL;
    LC.last = NULL;
}
void deleteAfterParent(ListParent &LP, NodeParent *prec, NodeParent *&P) {
    if (prec != NULL && prec->next != NULL) {
        P = prec->next;
        hapusListChild(P->childs); // Otomatis hapus child sesuai ketentuan
        
        prec->next = P->next;
        if (P->next != NULL) {
            P->next->prev = prec;
        } else {
            LP.last = prec;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}
void searchFilmByRatingRange(ListParent LP, float start, float end) {
    NodeParent *p = LP.first;
    int posParent = 1;
    while (p != NULL) {
        NodeChild *c = p->childs.first;
        int posChild = 1;
        while (c != NULL) {
            if (c->ratingFilm >= start && c->ratingFilm <= end) {
                cout << "Data Film ditemukan pada list child dari node parent " << p->namaGenre << " pada posisi ke-" << posChild << "!" << endl;
                cout << "Data Film (Child)" << endl;
                cout << "Judul Film : " << c->judulFilm << endl;
                cout << "Posisi dalam list child : posisi ke-" << posChild << endl;
                cout << "ID Film : " << c->idFilm << endl;
                cout << "Durasi Film : " << c->durasiFilm << " menit" << endl;
                cout << "Tahun Tayang : " << c->tahunTayang << endl;
                cout << "Rating Film : " << c->ratingFilm << endl;
                cout << "Data Genre (Parent)" << endl;
                cout << "ID Genre : " << p->idGenre << endl;
                cout << "Posisi dalam list parent : posisi ke-" << posParent << endl;
                cout << "Nama Genre : " << p->namaGenre << endl;
            }
            c = c->next;
            posChild++;
        }
        p = p->next;
        posParent++;
    }
}
void printStrukturMLL(ListParent LP) {
    NodeParent *p = LP.first;
    int i = 1;
    while (p != NULL) {
        cout << "Parent " << i << endl;
        cout << "ID Genre : " << p->idGenre << endl;
        cout << "Nama Genre : " << p->namaGenre << endl;
        NodeChild *c = p->childs.first;
        int j = 1;
        while (c != NULL) {
            cout << "  - Child " << j << " :" << endl;
            cout << "    ID Film : " << c->idFilm << endl;
            cout << "    Judul Film : " << c->judulFilm << endl;
            cout << "    Durasi Film : " << c->durasiFilm << " menit" << endl;
            cout << "    Tahun Tayang : " << c->tahunTayang << endl;
            cout << "    Rating Film : " << c->ratingFilm << endl;
            c = c->next;
            j++;
        }
        p = p->next;
        i++;
    }
}