#include<iostream>
#include <iomanip>

using namespace std;

# define QElemType int

typedef struct LNode{
    QElemType data;
    struct LNode *next;
}LNode, *QueuePtr;

typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

void InitQueue_L(LinkQueue &Q){
    Q.front = Q.rear = new LNode;
    Q.front -> data = 0;
    Q.front -> next = NULL;
}

void DestroyQueue_L(LinkQueue &Q){
    while(Q.front){
        Q.rear = Q.front;
        Q.front = Q.front -> next;
        delete Q.rear;
    }
}

void ClearQueue_L(LinkQueue &Q){
    Q.rear = Q.front;
    Q.front = Q.front -> next;
    Q.rear -> next = NULL;
    Q.rear -> data = 0;
    while(Q.front){
        Q.rear = Q.front;
        Q.front = Q.front -> next;
        delete Q.rear;
    }
}

bool QueueEmpty_L(LinkQueue Q){
    if(Q.front == Q.rear){
        return true;
    }
    return false;
}

int QueueLength_L(LinkQueue Q){
    return Q.front -> data;
}

bool GetHead_L(LinkQueue Q, QElemType &e){
    if(Q.front == Q.rear){
        return false;
    }
    e = Q.front -> next -> data;
    return true;
}

void EnQueue_L(LinkQueue &Q, QElemType e){
    QueuePtr tem = new LNode;
    tem -> data = e;
    tem -> next = NULL;
    Q.rear -> next = tem;
    Q.rear = tem;
    Q.front -> data += 1;
}

bool DeQueue_L(LinkQueue &Q, QElemType &e){
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
    Q.front -> data -= 1;
    return true;
}

void QueueTraverse_L(LinkQueue Q){
    QueuePtr q = Q.front -> next;
    while(q){
        cout.setf(ios::left);
        cout << setw(5) << q -> data;
        q = q -> next;
    }
}