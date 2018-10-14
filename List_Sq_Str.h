#include<iostream>


using namespace std;

# define ElemType char


const int LIST_INIT_SIZE = 100;
const int LISTINCREAMENT = 10;


typedef struct my_SqList{
    ElemType *elem;
    int length;
    int listsize;
    int incrementsize;
} SqList;

void InitList_Sq(SqList &L){            //初始化  时间复杂度O(1)   空间复杂度O(1)
    L.elem = new ElemType[LIST_INIT_SIZE];
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    L.incrementsize = LISTINCREAMENT;
}

int LocalElem_Sq(SqList L, ElemType e){            //查找  时间复杂度O(1)   空间复杂度O(1)
    int i = 1;
    ElemType *p = L.elem;
    while(i <= L.length && *p++ != e){
        i++;
    }
    if(i <= L.length){
        return i;
    }else{
        return 0;
    }
}

void increment(SqList &L){
    ElemType *a = new ElemType[L.incrementsize + L.listsize];  //时间复杂度O(n)   空间复杂度O(1)
    for(int i = 0; i < L.length; i++){
        a[i] = L.elem[i];
    }
    delete [] L.elem;
    L.elem = a;
    L.listsize += L.incrementsize;
}

void ListInsert_Sq(SqList &L, int i, ElemType e){          //插入  时间复杂度O(n)   空间复杂度O(1)
    if(i < 1 || i > L.length + 1){
        cout << "i值不合法" << endl;
    }
    if(L.length >= L.listsize){
        increment(L);
    }
    ElemType *q = &(L.elem[i - 1]);
    for(ElemType *p = &(L.elem[L.length - 1]); p >= q; --p){
        *(p + 1) = *p;
    }
    *q = e;
    L.length ++;
}

void ListDelete_Sq(SqList &L, int i, ElemType &e){             //删除  时间复杂度O(n)   空间复杂度O(1)
    if(i < 1 || (i > L.length)){
        cout << "i值不合法" << endl;
        exit(-1);
    }
    ElemType *p = &(L.elem[i - 1]);
    e = *p;
    ElemType *q = L.elem + L.length - 1;
    for(++p; p <= q; ++p){
        *(p - 1) = *p;
    }
    L.length --;
}

void DestroyList_Sq(SqList &L){                             //销毁  时间复杂度O(1)   空间复杂度O(1)
    delete [] L.elem;
    L.listsize = 0;
    L.length = 0;
}


void ClearList_Sq(SqList &L){                               //清空  时间复杂度O(1)   空间复杂度O(1)
    L.length = 0;
}

bool ListEmpty_Sq(SqList L){                                //判断是否为空  时间复杂度O(1)   空间复杂度O(1)
    if (L.length == 0){
        return true;
    }
    return false;
}

int ListLength_Sq(SqList L){                           //长度  时间复杂度O(1)   空间复杂度O(1)
    return L.length;
}

void GetElem_Sq(SqList L, int i, ElemType &e){            //取值  时间复杂度O(1)   空间复杂度O(1)
    if(i < 1 || i > L.length){
        cout << "i值不合法" << endl;
        exit(-1);
    }else{
        e =  L.elem[i - 1];
    }
}

void PriorElem_Sq(SqList L, ElemType cur_e, ElemType &pre_e){        //前驱  时间复杂度O(1)   空间复杂度O(1)
    int i = LocalElem_Sq(L, cur_e);
    if(i == 1 || i == 0){
        cout << cur_e << " " << "没有前驱" << endl;
        exit(-1);
    }else{
        pre_e = L.elem[i - 2];
    }
}

void NextElem_Sq(SqList L, ElemType cur_e, ElemType &next_e){            //后继  时间复杂度O(1)   空间复杂度O(1)
    int i = LocalElem_Sq(L, cur_e);
    if(i == L.length || i ==0){
        cout << cur_e << " " << "没有后继" << endl;
        exit(-1);
    }else{
        next_e = L.elem[i];
    }
}

void ListTraverse_Sq(SqList L){                        //输出  时间复杂度O(n)   空间复杂度O(1)
    for(int i = 1; i <= L.length; i++){
        cout << L.elem[i - 1] << " ";
        if (i % 10 == 0){
            cout << endl;
        }
    }
}