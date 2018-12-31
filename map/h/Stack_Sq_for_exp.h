#include<iostream>
#include <iomanip>

#define SElemType char
#define SIZE 100
#define INCREMENTSIZE 20

using namespace std;

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

void DestroyStack_Sq(SqStack &S){
    delete S.elem;
    S.top = -1;
    S.stacksize = 0;
    S.incrementsize = 0;
}

void ClearStack_Sq(SqStack &S){
    S.top = -1;
}

bool StackEmpty_Sq(SqStack S){
    if(S.top == -1){
        return true;
    }
    return false;
}

int StackLength_Sq(SqStack S){
    return S.top + 1;
}

bool GetTop_Sq(SqStack S, SElemType &e){
    if(S.top != -1){
        e = S.elem[S.top];
        return true;
    }
    return false;
}

void Push_Sq(SqStack &S, SElemType &e){
    if(S.top == S.stacksize - 1){
        S.stacksize += S.incrementsize;
        SElemType *tem = new SElemType[S.stacksize];
        for(int i = 0; i <= S.top; i++){
            tem[i] = S.elem[i];
        }
        tem[++S.top] = e;
        delete [] S.elem;
        S.elem = tem;
    }else{
        S.elem[++S.top] = e;
    }
}

bool Pop_Sq(SqStack &S, SElemType &e){
    if(S.top == -1){
        return false;
    }
    e = S.elem[S.top--];
    return true;
}

void StackTraverse_Sq(SqStack S){
    for(int i = S.top; i >= 0; --i){
        cout.setf(ios::left);
        cout << setw(5) << S.elem[i];
    }
}


#define SElemTyped double
#define SIZE 100
#define INCREMENTSIZE 20

using namespace std;

typedef struct{
    SElemTyped *elem;
    int top;
    int stacksize;
    int incrementsize;
} SqStack_d;

void InitStack_Sq_d(SqStack_d &S, int size = SIZE, int incrementsize = INCREMENTSIZE){
    S.elem = new SElemTyped[size];
    S.top = -1;
    S.stacksize = size;
    S.incrementsize = incrementsize;
}

void DestroyStack_Sq_d(SqStack_d &S){
    delete S.elem;
    S.top = -1;
    S.stacksize = 0;
    S.incrementsize = 0;
}

void ClearStack_Sq_d(SqStack_d &S){
    S.top = -1;
}

bool StackEmpty_Sq_d(SqStack_d S){
    if(S.top == -1){
        return true;
    }
    return false;
}

int StackLength_Sq_d(SqStack_d S){
    return S.top + 1;
}

bool GetTop_Sq_d(SqStack_d S, SElemTyped &e){
    if(S.top != -1){
        e = S.elem[S.top];
        return true;
    }
    return false;
}

void Push_Sq_d(SqStack_d &S, SElemTyped &e){
    if(S.top == S.stacksize - 1){
        S.stacksize += S.incrementsize;
        SElemTyped *tem = new SElemTyped[S.stacksize];
        for(int i = 0; i <= S.top; i++){
            tem[i] = S.elem[i];
        }
        tem[++S.top] = e;
        delete [] S.elem;
        S.elem = tem;
    }else{
        S.elem[++S.top] = e;
    }
}

bool Pop_Sq_d(SqStack_d &S, SElemTyped &e){
    if(S.top == -1){
        return false;
    }
    e = S.elem[S.top--];
    return true;
}

void StackTraverse_Sq_d(SqStack_d S){
    for(int i = S.top; i >= 0; --i){
        cout.setf(ios::left);
        cout << setw(5) << S.elem[i];
    }
}
