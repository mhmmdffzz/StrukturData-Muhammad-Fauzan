#include "MultiLL.h"

/* ===== EMPTY ===== */
bool isEmptyParent(listParent LParent) {
    return (LParent.first == NULL);
}

bool isEmptyChild(listChild LChild) {
    return (LChild.first == NULL);
}

/* ===== CREATE ===== */
void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

/* ===== ALOKASI ===== */
NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    createListChild(P->L_Child);
    P->next = NULL;
    P->prev = NULL;
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat,
                         bool tail, float weight) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = tail;
    C->isidata.bobot = weight;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

/* ===== DEALOKASI ===== */
void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
    NParent = NULL;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
    NChild = NULL;
}

/* ===== INSERT PARENT ===== */
void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}

/* ===== DELETE PARENT ===== */
void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent P = LParent.first;
        LParent.first = P->next;
        if (LParent.first != NULL)
            LParent.first->prev = NULL;
        else
            LParent.last = NULL;
        deleteListChild(P->L_Child);
        deallocNodeParent(P);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeParent P = NPrev->next;
        NPrev->next = P->next;
        if (P->next != NULL)
            P->next->prev = NPrev;
        else
            LParent.last = NPrev;
        deleteListChild(P->L_Child);
        deallocNodeParent(P);
    }
}

/* ===== INSERT CHILD ===== */
void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}

/* ===== DELETE CHILD ===== */
void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild C = LChild.first;
        LChild.first = C->next;
        if (LChild.first != NULL)
            LChild.first->prev = NULL;
        else
            LChild.last = NULL;
        deallocNodeChild(C);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeChild C = NPrev->next;
        NPrev->next = C->next;
        if (C->next != NULL)
            C->next->prev = NPrev;
        else
            LChild.last = NPrev;
        deallocNodeChild(C);
    }
}

/* ===== PRINT ===== */
void printMLLStructure(listParent LParent) {
    NodeParent P = LParent.first;
    int idxParent = 1;

    while (P != NULL) {
        cout << "=== Parent " << idxParent++ << " ===" << endl;
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;

        NodeChild C = P->L_Child.first;
        if (C == NULL) {
            cout << "(tidak ada child)" << endl;
        } else {
            int idxChild = 1;
            while (C != NULL) {
                cout << " - Child " << idxChild++ << " :" << endl;
                cout << "    ID Hewan : " << C->isidata.idHewan << endl;
                cout << "    Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "    Habitat : " << C->isidata.habitat << endl;
                cout << "    Ekor : " << C->isidata.ekor << endl;
                cout << "    Bobot : " << C->isidata.bobot << endl;
                C = C->next;
            }
        }
        cout << "-------------------------" << endl;
        P = P->next;
    }
}


/* ===== DELETE LIST CHILD ===== */
void deleteListChild(listChild &LChild) {
    while (LChild.first != NULL) {
        deleteFirstChild(LChild);
    }
}
