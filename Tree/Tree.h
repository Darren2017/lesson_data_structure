#include<iostream>
#include"Queue_L.h"

using namespace std;

void InitBiTree(BiTree &T){
    T -> lchild = NULL;
    T -> rchild = NULL;
}

void CreateBiTree(BiTree &T){
    TElemType ch;
    cin >> ch;
    if(ch == '#'){
        T = NULL;
    }else{
        T = new BiTNode;
        T -> data = ch;
        CreateBiTree(T -> lchild);
        CreateBiTree(T -> rchild);
    }
}

void Preorder(BiTree T, void(*visit)(BiTree)){
    if(T){
        visit(T);
        Preorder(T -> lchild, visit);
        Preorder(T -> rchild, visit);
    }
}

void InOrder_iter(BiTree T, void(*visit)(BiTree)){
    if(T){
        InOrder_iter(T -> lchild, visit);
        visit(T);
        InOrder_iter(T -> rchild, visit);
    }
}

void Postorder(BiTree T, void(*visit)(BiTree)){
    if(T){
        Postorder(T -> lchild, visit);
        Postorder(T -> rchild, visit);
        visit(T);
    }
}

void Hierarchical(BiTree T, void(*visit)(BiTree)){
    LinkQueue Q;
    InitQueue_L(Q);
    EnQueue_L(Q, T);
    while(!QueueEmpty_L(Q)){
        BiTNode *p;
        DeQueue_L(Q, p);
        visit(p);
        if(p -> lchild){
            EnQueue_L(Q, p -> lchild);
        }
        if(p -> rchild){
            EnQueue_L(Q, p -> rchild);
        }
    }
}


void BiTreeDepth(BiTree T, int h, int &depth){
    if(T){
        if(h > depth){
            depth = h;
        }
        BiTreeDepth(T -> lchild, h + 1, depth);
        BiTreeDepth(T -> rchild, h + 1, depth);
    }
}

int BiTreeDepth(BiTree T){
    if(T){
        return 1 + max(BiTreeDepth(T -> lchild), BiTreeDepth(T -> rchild));
    }
    return 0;
}

BiTNode *GetTreeNode(TElemType item, BiTNode *lptr, BiTNode *rptr){
    BiTNode *T;
    T = new BiTNode;
    T -> data = item;
    T -> lchild = lptr;
    T -> rchild = rptr;
    return T;
}

BiTNode *CopyTree(BiTNode *T){
    BiTNode *newlptr, *newrptr, *newnode;
    if(!T){
        return NULL;
    }
    if(T -> lchild){
        newlptr = CopyTree(T -> lchild);
    }else{
        newlptr = NULL;
    }
    if(T -> rchild){
        newrptr = CopyTree(T -> rchild);
    }else{
        newrptr = NULL;
    }
    newnode = GetTreeNode(T -> data, newlptr, newrptr);
    return newnode;
}