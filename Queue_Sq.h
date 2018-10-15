#include<iostream>
#include<iomanip>

#define QElemType int

using namespace std;

const int QUEUE_INIT_SIZE = 100;
const int QUEUEINCREMENT = 10;

typedef struct{
    QElemType *elem;
    int front;
    int rear;
    int queuesize;
    int incrementsize;
}SqQueue;

void InitQueue_Sq(SqQueue &Q, int size = QUEUE_INIT_SIZE, int incrementsize = QUEUEINCREMENT){
    Q.elem = new QElemType[size + 1];
    Q.front = Q.rear = 0;
    Q.queuesize = size + 1;
    Q.incrementsize = incrementsize;
}

void DestroyQueue_Sq(SqQueue &Q){
    delete [] Q.elem;
    Q.front = Q.rear = 0;
    Q.queuesize = 0;
    Q.incrementsize = 0;
}

void ClearQueue_Sq(SqQueue &Q){
    Q.front = Q.rear = 0;
}

bool QueueEmpty_Sq(SqQueue Q){
    if(Q.front == Q.rear){
        return true;
    }
    return false;
}

int QueueLength_Sq(SqQueue Q){
    return (Q.rear - Q.front + Q.queuesize) % Q.queuesize;
}

bool GetHead_Sq(SqQueue Q, QElemType &e){
    if(Q.front == Q.rear){
        return false;
    }
    e = Q.elem[Q.front];
    return true;
}

void incrementsizeQueueSize(SqQueue &Q){
    int len = Q.queuesize - 1;
    QElemType *tem = new QElemType[Q.queuesize + Q.incrementsize];
    for(int i = 0; i < len; i++){
        tem[i] = Q.elem[(Q.front + i) % Q.queuesize];
    }
    delete [] Q.elem;
    Q.elem = tem;
    Q.front = 0;
    Q.rear = Q.queuesize - 1;
    Q.queuesize += Q.incrementsize;
}

void EnQueue_Sq(SqQueue &Q, QElemType e){
    if((Q.rear + 1) % Q.queuesize == Q.front){
        incrementsizeQueueSize(Q);
    }
    Q.elem[Q.rear] = e;
    Q.rear = (Q.rear + 1) % Q.queuesize;
}

bool DeQueue_Sq(SqQueue &Q, QElemType &e){
    if(Q.front == Q.rear){
        return false;
    }
    e = Q.elem[Q.front];
    Q.front = (Q.front + 1) % Q.queuesize;
    return true;
}

void QueueTraverse_Sq(SqQueue Q){
    int len = QueueLength_Sq(Q);
    for(int i = 0; i < len; i++){
        cout.setf(ios::left);
        cout << setw(5) << Q.elem[(Q.front + i) % Q.queuesize];
    }
}