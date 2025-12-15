#include "MultiLL.h"

int main() {
    listParent LP;
    createListParent(LP);

    NodeParent G1 = allocNodeParent("G001", "Aves");
    NodeParent G2 = allocNodeParent("G002", "Mamalia");
    NodeParent G3 = allocNodeParent("G003", "Pisces");
    NodeParent G4 = allocNodeParent("G004", "Amfibi");
    NodeParent G5 = allocNodeParent("G005", "Reptil");

    insertLastParent(LP, G1);
    insertLastParent(LP, G2);
    insertLastParent(LP, G3);
    insertLastParent(LP, G4);
    insertLastParent(LP, G5);

    insertLastChild(G1->L_Child,
        allocNodeChild("AV001","Cendrawasih","Hutan",1,0.3));
    insertLastChild(G1->L_Child,
        allocNodeChild("AV002","Bebek","Air",1,2));

    insertLastChild(G2->L_Child,
        allocNodeChild("M001","Harimau","Hutan",1,200));
    insertLastChild(G2->L_Child,
        allocNodeChild("M003","Gorila","Hutan",0,160));
    insertLastChild(G2->L_Child,
        allocNodeChild("M002","Kucing","Darat",1,4));

    insertLastChild(G4->L_Child,
        allocNodeChild("AM001","Kodok","Sawah",0,0.2));

    // ✅ DELETE G004 (Amfibi)
    deleteAfterParent(LP, G3);

    printMLLStructure(LP);
    return 0;
}
