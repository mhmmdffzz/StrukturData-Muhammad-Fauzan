#ifndef STACK3_H
#define STACK3_H

#define MaxEl 20
typedef int infotype;

struct Stack {
    infotype info[MaxEl];
    int top;
};

void createStack(Stack &S);
bool isEmpty(const Stack &S);
bool isFull(const Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);
void getInputStream(Stack &S); // baca satu baris, tiap digit menjadi satu angka

#endif // STACK3_H
