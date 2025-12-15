#include "MultiLL.h"

int main() {
    listParent LP;
    createListParent(LP);

    NodeParent G2 = allocNodeParent("G002", "Mamalia");
    NodeParent G4 = allocNodeParent("G004", "Amfibi");

    insertLastParent(LP, G2);
    insertLastParent(LP, G4);

    insertLastChild(G2->L_Child, allocNodeChild("M001","Harimau","Hutan",1,200));
    insertLastChild(G2->L_Child, allocNodeChild("M003","Gorila","Hutan",0,160));
    insertLastChild(G4->L_Child, allocNodeChild("AM001","Kodok","Sawah",0,0.2));

    NodeParent P = LP.first;
    int posParent = 1;

    while (P != NULL) {
        NodeChild C = P->L_Child.first;
        int posChild = 1;

        while (C != NULL) {
            if (C->isidata.ekor == false) {
                cout << "Data ditemukan pada list anak dari node parent "
                     << P->isidata.namaGolongan
                     << " pada posisi ke-" << posChild << "!" << endl;

                cout << "--- Data Child ---" << endl;
                cout << "ID Child : " << C->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << posChild << endl;
                cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "Habitat : " << C->isidata.habitat << endl;
                cout << "Ekor : " << C->isidata.ekor << endl;
                cout << "Bobot : " << C->isidata.bobot << endl;

                cout << "------------------------" << endl;
                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent : " << P->isidata.idGolongan << endl;
                cout << "Posisi dalam list induk : posisi ke-" << posParent << endl;
                cout << "Nama golongan : " << P->isidata.namaGolongan << endl;
                cout << "------------------------" << endl;
            }
            C = C->next;
            posChild++;
        }
        P = P->next;
        posParent++;
    }

    return 0;
}
