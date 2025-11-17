#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(const Stack &S) {
    return S.top == -1;
}

bool isFull(const Stack &S) {
    return S.top == MaxEl - 1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh\n";
    }
}

infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        cout << "Stack kosong\n";
        return -1;
    }
}

void printInfo(const Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong\n";
        return;
    }
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; --i) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack T;
    createStack(T);
    while (!isEmpty(S)) {
        push(T, pop(S));
    }
    S = T;
}
