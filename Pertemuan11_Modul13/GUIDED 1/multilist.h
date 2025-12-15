#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>
using namespace std;

typedef struct nodeParent *NodeParent; //alias pointer ke struct nodeParent
typedef struct nodeChild *NodeChild;   //alias pointer ke struct nodeChild

struct  nodeChild{ //node child
    string idMakanan;
    string namaMakanan;
    NodeChild next;
    NodeChild prev;
};

struct listAnak{ //list child
    NodeChild first;    
    NodeChild last;
};

struct nodeParent{ //node parent
 string idKategoriMakanan;
 string namaKategoriMakanan;
 NodeParent next;
 NodeParent prev;
 listAnak L_Anak; //list child
};

struct listInduk{ //list parent
    NodeParent first;
    NodeParent last;
};

//create list 
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &Lanak);

//alokasi &d elokasi parent
NodeParent alokasiNodeParent(string idkategoriMakanan, string namaKategoriMakanan);
void dealokasiNodeParent(NodeParent &NodeInduk);

//alokasi & delokasi child
NodeChild alokasiNodeChild(string idmakanan, string namamakanan);
void dealokasiNodeChild(NodeChild &NodeAnak);

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void hapusListAnak(listAnak &LAnak);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev); 
void findChildByID(listInduk &LInduk, string IDCari);

//operasi print
void printStrukturMLL(listInduk &LInduk);

#endif