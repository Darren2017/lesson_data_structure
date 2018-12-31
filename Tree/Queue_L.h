#include<iostream>
#include <iomanip>

#define TElemType char

using namespace std;

typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

#define QElemTpye BiTree

typedef struct LNode{
    QElemTpye data;
    struct LNode *next;
}LNode, *QueuePtr;

typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

void InitQueue_L(LinkQueue &Q){
    Q.front = Q.rear = new LNode;
    Q.front -> next = NULL;
}

bool QueueEmpty_L(LinkQueue Q){
    if(Q.front == Q.rear){
        return true;
    }
    return false;
}

void EnQueue_L(LinkQueue &Q, QElemTpye e){
    QueuePtr tem = new LNode;
    tem -> data = e;
    tem -> next = NULL;
    Q.rear -> next = tem;
    Q.rear = tem;
}

bool DeQueue_L(LinkQueue &Q, QElemTpye &e){
    if(Q.front == Q.rear){
        return false;
    }
    e = Q.front -> next -> data;
    QueuePtr tem = Q.front -> next;
    Q.front -> next = tem -> next;
    if(Q.rear == tem){
        Q.rear = Q.front;
    }
    delete tem;
    return true;
}