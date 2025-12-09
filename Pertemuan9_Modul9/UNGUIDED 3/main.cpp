#include <iostream>
#include "BST3.h"
using namespace std;

int main() {
    address root = Nil;
    
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 5);
    insertNode(root, 1);
    insertNode(root, 3);
    
    cout << "Pre-Order: ";
    PreOrder(root);
    cout << endl;
    
    cout << "Post-Order: ";
    PostOrder(root);
    cout << endl;
    
    return 0;
}
