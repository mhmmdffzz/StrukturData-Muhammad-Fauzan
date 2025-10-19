#include "Singlylist.h"

int main() {
    init();

    // Soal 1
    std::cout << "Soal 1:" << std::endl;
    insertFirst(9);
    insertLast(12);
    insertLast(2);
    insertAfter(8, 12);
    insertAfter(0, 8);
    printList();

    // Soal 2
    std::cout << "\nSoal 2:" << std::endl;
    deleteFirst();
    deleteLast();
    deleteAfter(12);
    printList();
    std::cout << "Jumlah node : " << nbList() << std::endl;
    deleteList();
    std::cout << "- List Berhasil Terhapus -" << std::endl;
    std::cout << "Jumlah node : " << nbList() << std::endl;

    return 0;
}
