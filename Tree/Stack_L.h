#include<iostream>
#include <iomanip>

#define ElemType char

using namespace std;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkStack;

void InitStack_L(LinkStack &S){
    S = NULL;
}

void DestroyStack(LinkStack &S){
    LinkStack q;
    while(S){
        q = S;
        S = S -> next;
        delete q;
    }
}

void ClearStack(LinkStack &S){
    LinkStack q;
    while(S){
        q = S;
        S = S -> next;
        delete q;
    }
}

bool StackEmpty(LinkStack S){
    if(!S){
        return true;
    }
    return false;
}

int StackLength(LinkStack S){
    int i = 0;
    LinkStack q;
    while(S){
        i++;
        q = S;
        S = S -> next;
    }
    return i;
}

bool GetTop(LinkStack S, ElemType &e){
    if(S){
        e = S -> data;
        return true;
    }
    return false;
}

void Push(LinkStack &S, ElemType e){
    LinkStack q = new LNode;
    q -> data = e;
    q -> next = S;
    S = q;
}

bool Pop(LinkStack &S, ElemType &e){
    if(!S){
        return false;
    }
    e = S -> data;
    LinkStack q = S;
    S = S -> next;
    delete q;
    return true;
}

void StackTraverse(LinkStack S){
    LinkStack q = S;
    while(q){
        cout.setf(ios::left);
        cout << setw(5) << q -> data;
        q = q -> next;
    }
}

void StackCopytoArray(LinkStack S, char* &HC){
    int i = StackLength(S) - 1;
    for(; i >= 0; i--){
        HC[i] = S -> data;
        S = S -> next;
    }
}