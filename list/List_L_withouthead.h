#include<iostream>

using namespace std;

# define ElemType int

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

void InitList_L(LinkList &L){
    L = NULL;
}

int LocalElem_L(LinkList L, ElemType e){            //查找
    if(!L){
        return 0;
    }
    int i = 1;
    LNode *p = L;
    while(p && p -> data != e){
        p = p -> next;
        i++;
    }
    if(!p){
        return 0;
    }else{
        return i;
    }
}

void ListInsert_L(LinkList &L, int i, ElemType e){      //插入
    if(i == 1){
        LNode *q = new LNode;
        q -> data = e;
        q -> next = L;
        L = q;
    }else{
        LNode *p = L;
        for(int j = 0; j < i - 2 && p; j++){
            p = p -> next;
        }
        if(p){
            LNode *q = new LNode;
            q -> data = e;
            q -> next = p -> next;
            p -> next = q;
        }else{
            cout << "i值不合法" << endl;
            exit(-1);
        }
    }
}

void ListDelete_L(LinkList &L, int i, ElemType &e){     //删除
    LNode *p = L;
    if(i == 1){
        L = L -> next;
        delete p;
    }else{
        for(int j = 0; j < i  - 2 && p; j++){
            p = p -> next;
        }
        if(!p -> next){
            LNode *q = p -> next;
            p -> next = q -> next;
            e = q -> data;
            delete q;
        }else{
            cout << "i值不合法" << endl;
            exit(-1);
        }
    }
}

void DestroyList_L(LinkList &L){       //销毁
    LNode *p = L;
    LNode *q;
    while(p){
        q = p;
        p = p -> next;
        delete q;
    }
}


void ClearList_L(LinkList &L){         //清空
    LNode *p = L;
    LNode *q;
    while(p){
        q = p;
        p = p -> next;
        delete q;
    }
    L = NULL;
}

bool ListEmpty_L(LinkList L){          //是否为空
    if (L == NULL){
        return true;
    }
    return false;
}

int ListLength_L(LinkList L){      //长度
    int i = 0;
    LNode *p = L;
    while(p){
        i++;
        p = p -> next;
    }
    return i;
}

void GetElem_L(LinkList L, int i, ElemType &e){        //取值    改成先判断i的值是否合法
    LNode *p = L;
    for(int j = 1; j < i && p -> next; j++){
        p = p -> next;
    }
    if(p){
        e = p -> data;
    }else{
        cout << "i值不合法" << endl;
        exit(-1);
    }
}

void PriorElem_L(LinkList L, ElemType cur_e, ElemType &pre_e){     //前驱
    LNode *p = L;
    while(p -> next && p -> next -> data != cur_e){
        p = p -> next;
    }
    if(!p -> next){
        cout << cur_e << " " << "没有前驱" << endl;
        exit(-1);
    }else{
        pre_e = p -> data;
    }
}

void NextElem_L(LinkList L, ElemType cur_e, ElemType &next_e){     //后继
    LNode *p = L;
    while(p && p -> data != cur_e){
        p = p -> next;
    }
    if(p && p -> next){
        next_e = p -> next -> data;
    }else{
        cout << cur_e << " " << "没有后继" << endl;
        exit(-1);
    }
}

void ListTraverse_L(LinkList L){       //输出
    LNode *p = L;
    for(int i = 1; p; i++){
        cout << p -> data << " ";
        if (i % 10 == 0){
            cout << endl;
        }
        p = p -> next;
    }
}