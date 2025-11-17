#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    createStack(S);

    getInputStream(S);

    printInfo(S);

    cout << "balik stack\n";
    balikStack(S);
    printInfo(S);

    return 0;
}
