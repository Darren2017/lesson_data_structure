#include<iostream>

using namespace std;

# define ElemType int

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

void InitList_L(LinkList &L){           //初始化
    L = new LNode;
    L -> next = NULL;
    L -> data = 0;
}

int LocalElem_L(LinkList L, ElemType e){            //查找
    if(!L){
        return 0;
    }
    int i = 1;
    LNode *p = L -> next;
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
    LNode *p = L;
    for(int j = 0; j < i - 1 && p; j++){
        p = p -> next;
    }
    if(p){
        LNode *q = new LNode;
        q -> data = e;
        q -> next = p -> next;
        p -> next = q;
        L -> data += 1;
    }else{
        cout << "i值不合法" << endl;
        exit(-1);
    }

}

void ListDelete_L(LinkList &L, int i, ElemType &e){     //删除
    LNode *p = L;
    for(int j = 0; j < i  - 1 && p; j++){
        p = p -> next;
    }
    if(!p && !p -> next){
        LNode *q = p -> next;
        p -> next = q -> next;
        delete q;
        L -> data -= 1;
    }else{
        cout << "i值不合法" << endl;
        exit(-1);
    }
}

void DestroyList_L(LinkList &L){       //销毁
    LNode *p = L -> next;
    LNode *q;
    while(p){
        q = p;
        p = p -> next;
        delete q;
    }
    delete L;
}


void ClearList_L(LinkList &L){         //清空
    LNode *p = L -> next;
    LNode *q;
    while(p){
        q = p;
        p = p -> next;
        delete q;
    }
    L -> data = 0;
}

bool ListEmpty_L(LinkList L){          //是否为空
    if (L -> data == 0){
        return true;
    }
    return false;
}

int ListLength_L(LinkList L){      //长度
    return L -> data;
}

void GetElem_L(LinkList L, int i, ElemType &e){        //取值
    LNode *p = L;
    for(int j = 0; j < i && p -> next; j++){
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
    if(!p -> next || p == L){
        cout << cur_e << " " << "没有前驱" << endl;
        exit(-1);
    }else{
        pre_e = p -> data;
    }
}

void NextElem_L(LinkList L, ElemType cur_e, ElemType &next_e){     //后继
    LNode *p = L -> next;
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
    LNode *p = L -> next;
    for(int i = 1; p; i++){
        cout << p -> data << " ";
        p = p -> next;
        if (i % 10 == 0){
            cout << endl;
        }
    }
}