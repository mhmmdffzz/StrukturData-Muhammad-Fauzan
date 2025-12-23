#include <iostream>
#include "BST.h"

using namespace std;

int main() {
    createTree();

    float berat[] = {60, 50, 65, 47, 56, 70, 52, 68, 81};
    string nama[] = {
        "Rizkina Azizah", "Hakan Ismail", "Olivia Saevali",
        "Felix Pedrosa", "Gamel Al Ghifari", "Hanif Al Faiz",
        "Mutiara Fauziah", "Davi Ilyas", "Abdad Mubarok"
    };
    string tier[] = {
        "Basic", "Bronze", "Silver", "Gold", "Platinum",
        "Basic", "Bronze", "Silver", "Gold"
    };

    for (int i = 0; i < 9; i++)
        root = insertNode(root, nama[i], berat[i], tier[i]);

    cout << "In-order traversal: ";
    inOrder(root);
    cout << endl << endl;

    mostLeft();
    mostRight();
    searchByBeratBadan(70);
    return 0;
}
