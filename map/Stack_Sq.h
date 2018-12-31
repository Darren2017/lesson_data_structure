#include<iostream>
#include <iomanip>

#define SIZE 100
#define INCREMENTSIZE 20

using namespace std;

typedef struct{
    int xpos;
    int ypos;
}PosType;

#define SElemType PosType

typedef struct{
    SElemType *elem;
    int top;
    int stacksize;
    int incrementsize;
} SqStack;

void InitStack_Sq(SqStack &S, int size = SIZE, int incrementsize = INCREMENTSIZE){
    S.elem = new SElemType[size];
    S.top = -1;
    S.stacksize = size;
    S.incrementsize = incrementsize;
}

bool StackEmpty_Sq(SqStack S){
    if(S.top == -1){
        return true;
    }
    return false;
}

void Push_Sq(SqStack &S, SElemType &e){
    if(S.top == S.stacksize - 1){
        S.stacksize += S.incrementsize;
        SElemType *tem = new SElemType[S.stacksize];
        for(int i = 0; i <= S.top; i++){
            tem[i].xpos = S.elem[i].xpos;
            tem[i].ypos = S.elem[i].ypos;
        }
        tem[++S.top] = e;
        delete [] S.elem;
        S.elem = tem;
    }else{
        S.elem[++S.top].xpos = e.xpos;
        S.elem[S.top].ypos = e.ypos;
    }
}

bool GetTop_Sq(SqStack S, SElemType &e){
    if(S.top != -1){
        e.xpos = S.elem[S.top].xpos;
        e.ypos = S.elem[S.top].ypos;
        return true;
    }
    return false;
}

bool Pop_Sq(SqStack &S, SElemType &e){
    if(S.top == -1){
        return false;
    }
    e.xpos = S.elem[S.top].xpos;
    e.ypos = S.elem[S.top--].ypos;
    return true;
}

void StackTraverse_Sq(SqStack S){
    for(int i = S.top; i >= 0; --i){
        cout.setf(ios::left);
        cout << '(' << S.elem[i].ypos << "," << S.elem[i].xpos << ")  ";
    }
}
