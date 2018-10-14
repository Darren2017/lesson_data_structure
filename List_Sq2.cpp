#include"List_Sq.h"

using namespace std;

void InputElem(SqList &L, int n);
void union_Sq(SqList La, SqList Lb, SqList &Lc);
void and_Sq(SqList La, SqList Lb, SqList &Lc);
void diff_Sq(SqList La, SqList Lb, SqList &Lc);

int main()
{
    SqList La, Lb, Lc;
    InitList_Sq(La);
    InitList_Sq(Lb);
    int n;
    cout << "**********************开始输入第一个列表************************" << endl;
    cout << "请输入第一个列表的大小：" << endl;
    cin >> n;
    cout << "请输入第一个列表的值："  << endl;
    InputElem(La, n);
    cout << "**********************开始输入第二个列表************************" << endl;
    cout << "请输入第二个列表的大小：" << endl;
    cin >> n;
    cout << "请输入第二个列表的值："  << endl;
    InputElem(Lb, n);
    while(1){
        cout << "并集： 1" << endl << "交集： 2" << endl << "差集1：3" << endl << "差集2：4" << endl << "退出： 5" << endl;
        int select;
        cin >> select;
        switch(select){
            case 1:{
                InitList_Sq(Lc);
                union_Sq(La, Lb, Lc);
                cout << "A = ";
                cout << "{ ";
                ListTraverse_Sq(La);
                cout << "}" << endl;
                cout << "B = ";
                cout << "{ ";
                ListTraverse_Sq(Lb);
                cout << "}" << endl;
                cout << "A ∪ B = { ";
                ListTraverse_Sq(Lc);
                cout << "}" << endl;
                DestroyList_Sq(Lc);
                break;
            }
            case 2:{
                InitList_Sq(Lc);
                and_Sq(La, Lb, Lc);
                cout << "A = ";
                cout << "{ ";
                ListTraverse_Sq(La);
                cout << "}" << endl;
                cout << "B = ";
                cout << "{ ";
                ListTraverse_Sq(Lb);
                cout << "}" << endl;
                cout << "A ∩ B = { ";
                ListTraverse_Sq(Lc);
                cout << "}" << endl;
                DestroyList_Sq(Lc);
                break;
            }
            case 3:{
                InitList_Sq(Lc);
                diff_Sq(La, Lb, Lc);
                cout << "A = ";
                cout << "{ ";
                ListTraverse_Sq(La);
                cout << "}" << endl;
                cout << "B = ";
                cout << "{ ";
                ListTraverse_Sq(Lb);
                cout << "}" << endl;
                cout << "A - B = { ";
                ListTraverse_Sq(Lc);
                cout << "}" << endl;
                DestroyList_Sq(Lc);
                break;
            }
            case 4:{
                InitList_Sq(Lc);
                diff_Sq(Lb, La, Lc);
                cout << "A = ";
                cout << "{ ";
                ListTraverse_Sq(La);
                cout << "}" << endl;
                cout << "B = ";
                cout << "{ ";
                ListTraverse_Sq(Lb);
                cout << "}" << endl;
                cout << "B - A = { ";
                ListTraverse_Sq(Lc);
                cout << "}" << endl;
                DestroyList_Sq(Lc);
                break;
            }
            case 5:{
                return 0;
            }
        }
    }
    DestroyList_Sq(La);
    DestroyList_Sq(Lb);
    return 0;
}

void InputElem(SqList &L, int n){
    ElemType input;
    for(int i = 1; i <= n; i++){
        cin >> input;
        ListInsert_Sq(L, i, input);
    }
}

void union_Sq(SqList La, SqList Lb, SqList &Lc){
    int Lc_len = ListLength_Sq(Lc);
    int La_len = ListLength_Sq(La);
    int Lb_len = ListLength_Sq(Lb);
    ElemType e;
    for(int i = 1; i <= La_len; i++){
        GetElem_Sq(La, i, e);
        if(!LocalElem_Sq(Lc, e)){
            ListInsert_Sq(Lc, ++Lc_len, e);
        }
    }
    for(int i = 1; i <= Lb_len; i++){
        GetElem_Sq(Lb, i, e);
        if(!LocalElem_Sq(Lc, e)){
            ListInsert_Sq(Lc, ++Lc_len, e);
        }
    }
}

void and_Sq(SqList La, SqList Lb, SqList &Lc){
    int Lc_len = ListLength_Sq(Lc);
    int La_len = ListLength_Sq(La);
    ElemType e;
    for(int i = 1; i <= La_len; i++){
        GetElem_Sq(La, i, e);
        if(LocalElem_Sq(Lb, e)){
            ListInsert_Sq(Lc, ++Lc_len, e);
        }
    }
}

void diff_Sq(SqList La, SqList Lb, SqList &Lc){
    int Lc_len = ListLength_Sq(Lc);
    int La_len = ListLength_Sq(La);
    ElemType e;
    for(int i = 1; i <= La_len; i++){
        GetElem_Sq(La, i, e);
        if(!LocalElem_Sq(Lb, e)){
            ListInsert_Sq(Lc, ++Lc_len, e);
        }
    }
}