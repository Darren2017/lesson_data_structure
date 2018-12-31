#include<iostream>
#include"Stack_Sq.h"

using namespace std;

typedef struct{
    int weight;
    int lchild, rchild;
}HTNode;

typedef struct{
    HTNode *HTree;
    int root;
}HuffmanTree;

typedef char **HuffmanCode;

void Select(HTNode * HTree, int n, int &s1, int &s2, bool se[]){
    int m1 = 10000, m2 = 10000;
    for(int i = 0; i <= n; i++){
        if(HTree[i].weight < m1 && se[i]){
            s1 = i;
            m1 = HTree[i].weight;
        }
    }
    for(int i = 0; i <= n; i++){
        if(HTree[i].weight < m2 && i != s1 && se[i]){
            s2 = i;
            m2 = HTree[i].weight;
        }
    }
    se[s1] = false;
    se[s2] = false;
}

void CreateHuffmanTree(HuffmanTree &HT, int *w, int n){
    if(n <= 1){
        return;
    }else{
        int m = 2 * n - 1, i, s1, s2;
        HT.HTree = new HTNode[m];
        bool se[m];
        for(int i = 0; i < m; i++){
            se[i] = true;
        }
        HTNode *p = HT.HTree;
        for(i = 0; i < n; i++){
            p[i].weight = w[i];
            p[i].lchild = -1;
            p[i].rchild = -1;
        }
        for(; i < m; i++){
            p[i].weight = 0;
            p[i].lchild = -1;
            p[i].rchild = -1;
        }
        for(i = n; i< m; i++){
            Select(HT.HTree, i - 1, s1, s2, se);
            HT.HTree[i].lchild = s1;
            HT.HTree[i].rchild = s2;
            HT.HTree[i].weight = HT.HTree[s1].weight + HT.HTree[s2].weight;
        }
        HT.root = m - 1;
    }
}


void Coding(HuffmanTree T, int i, SqStack &S, HuffmanCode &HC){
    if(T.HTree){
        if((T.HTree[i].lchild == -1) && (T.HTree[i].rchild == -1)){
            HC[i] = new char[StackLength_Sq(S)];
            StackCopytoArray(S,HC[i]);
        }else{
            char e = '0';
            Push_Sq(S, e);
            Coding(T, T.HTree[i].lchild, S, HC);
            Pop_Sq(S, e);
            e = '1';
            Push_Sq(S, e);
            Coding(T, T.HTree[i].rchild, S, HC);
            Pop_Sq(S, e);
        }
    }
}

void HuffmanCoding(HuffmanTree HT, HuffmanCode &HC, int n){
    SqStack S;
    HC = new char*[n];
    InitStack_Sq(S);
    Coding(HT, HT.root, S, HC);
}