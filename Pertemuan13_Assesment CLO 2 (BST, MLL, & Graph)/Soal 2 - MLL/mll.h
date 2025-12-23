#ifndef MLL_H
#define MLL_H
#include <iostream>
#include <string>
using namespace std;
struct NodeChild;
struct ListChild {
    NodeChild *first;
    NodeChild *last;
};
struct NodeParent {
    string idGenre;
    string namaGenre;
    NodeParent *next;
    NodeParent *prev;
    ListChild childs; 
};
struct NodeChild {
    string idFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    NodeChild *next;
    NodeChild *prev;
};
struct ListParent {
    NodeParent *first;
    NodeParent *last;
};
void createListParent(ListParent &LP);
void createListChild(ListChild &LC);
NodeParent* alokasiNodeParent(string id, string nama);
NodeChild* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating);
void dealokasiNodeParent(NodeParent *P);
void dealokasiNodeChild(NodeChild *C);
void insertFirstParent(ListParent &LP, NodeParent *P);
void insertLastChild(ListChild &LC, NodeChild *C);
void hapusListChild(ListChild &LC);
void deleteAfterParent(ListParent &LP, NodeParent *prec, NodeParent *&P);
void searchFilmByRatingRange(ListParent LP, float start, float end);
void printStrukturMLL(ListParent LP);
#endif