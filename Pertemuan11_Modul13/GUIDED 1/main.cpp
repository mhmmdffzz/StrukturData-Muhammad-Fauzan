#include "multilist.h"
#include <iostream>
using namespace std;

int main(){
    //1.instalasi List
    listInduk LInduk;
    createListInduk(LInduk);

    //2.membuat Data Parent (kategori makanan)
    NodeParent k01 = alokasiNodeParent("K01", "Makanan Berat");
    insertLastParent(LInduk, k01);
    NodeParent k02 = alokasiNodeParent("K02", "Minuman");
    insertLastParent(LInduk, k02);
    NodeParent k03 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(LInduk, k03);
    cout<<endl;

    //3.masukkan Data Child (menu makanan) ke kategori tertentu
    //-->isi kategori makanan berat (k01)
    NodeChild M01 = alokasiNodeChild("M01", "Nasi Goreng");
    insertLastChild(k01->L_Anak, M01);
    NodeChild M02 = alokasiNodeChild("M02", "Ayam Bakar Madu");
    insertLastChild(k01->L_Anak, M02);  
    //--> isi kategori minuman (k02)
    NodeChild D02 = alokasiNodeChild("D02", "Jus Alpukat");
    insertLastChild(k02->L_Anak, D02);
    NodeChild D03 = alokasiNodeChild("D03", "Jus Alpukat");
    insertLastChild(k02->L_Anak, D03);
    //--> isi kategori dessert (k03)
    NodeChild S01 = alokasiNodeChild("DS01", "Puding Coklat");
    insertLastChild(k03->L_Anak, S01);
    cout << endl;  

    //4.print mll setelah insert-insert
    printStrukturMLL(LInduk);
    cout << endl;

    //5.searching node child
    findChildByID(LInduk, "D01");
    cout << endl;
    //6.delete node child
    deleteAfterChild(k01->L_Anak, M01);//menghapus node child ayam bakar madu
    cout<< endl;
    //7.delete node parent
    deleteAfterParent(LInduk, k02); //menghapus node parent minuman
    cout << endl;
    //8.print mll setelah delete
    printStrukturMLL(LInduk);
    cout << endl;
    return 0;
}
