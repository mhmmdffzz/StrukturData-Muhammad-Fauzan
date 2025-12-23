    #include "mll.h"
int main() {
    ListParent LP;
    createListParent(LP);
    insertFirstParent(LP, alokasiNodeParent("G004", "Romance"));
    insertFirstParent(LP, alokasiNodeParent("G003", "Horror"));
    insertFirstParent(LP, alokasiNodeParent("G002", "Comedy"));
    insertFirstParent(LP, alokasiNodeParent("G001", "Action"));
    NodeParent *curr = LP.first;
    while (curr != NULL) {
        if (curr->idGenre == "G001") {
            insertLastChild(curr->childs, alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6));
        } else if (curr->idGenre == "G002") {
            insertLastChild(curr->childs, alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0));
            insertLastChild(curr->childs, alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8));
        } else if (curr->idGenre == "G003") {
            insertLastChild(curr->childs, alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4));
        } else if (curr->idGenre == "G004") {
            insertLastChild(curr->childs, alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6));
            insertLastChild(curr->childs, alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6));
        }
        curr = curr->next;
    }
    cout << "TAMPILAN AWAL MLL" << endl;
    printStrukturMLL(LP);
    cout << endl;
    cout << "SEARCH RATING 8.0 - 8.5 " << endl;
    searchFilmByRatingRange(LP, 8.0, 8.5);
    cout << endl;
    NodeParent *pG001 = LP.first; 
    NodeParent *deleted;
    deleteAfterParent(LP, pG001, deleted);
    if (deleted != NULL) {
        dealokasiNodeParent(deleted);
    }
    cout << "SETELAH G002 DIHAPUS" << endl;
    printStrukturMLL(LP);
    return 0;
}