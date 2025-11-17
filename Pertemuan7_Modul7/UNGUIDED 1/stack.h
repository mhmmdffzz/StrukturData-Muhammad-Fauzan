#ifndef STACK1_H
#define STACK1_H

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

#endif // STACK1_H
