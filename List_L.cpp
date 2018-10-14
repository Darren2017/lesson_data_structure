#include"List_L_withouthead.h"
// #include"List_L_withhead.h"

using namespace std;

void InputElem(LinkList &L, int n);
void union_L(LinkList La, LinkList Lb, LinkList &Lc);
void and_L(LinkList La, LinkList Lb, LinkList &Lc);
void diff_L(LinkList La, LinkList Lb, LinkList &Lc);

int main()
{
    LNode *La, *Lb, *Lc;
    InitList_L(La);
    InitList_L(Lb);
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
                InitList_L(Lc);
                union_L(La, Lb, Lc);
                cout << "A = ";
                cout << "{ ";
                ListTraverse_L(La);
                cout << "}" << endl;
                cout << "B = ";
                cout << "{ ";
                ListTraverse_L(Lb);
                cout << "}" << endl;
                cout << "A ∪ B = { ";
                ListTraverse_L(Lc);
                cout << "}" << endl;
                DestroyList_L(Lc);
                break;
            }
            case 2:{
                InitList_L(Lc);
                and_L(La, Lb, Lc);
                cout << "A = ";
                cout << "{ ";
                ListTraverse_L(La);
                cout << "}" << endl;
                cout << "B = ";
                cout << "{ ";
                ListTraverse_L(Lb);
                cout << "}" << endl;
                cout << "A ∩ B = { ";
                ListTraverse_L(Lc);
                cout << "}" << endl;
                DestroyList_L(Lc);
                break;
            }
            case 3:{
                InitList_L(Lc);
                diff_L(La, Lb, Lc);
                cout << "A = ";
                cout << "{ ";
                ListTraverse_L(La);
                cout << "}" << endl;
                cout << "B = ";
                cout << "{ ";
                ListTraverse_L(Lb);
                cout << "}" << endl;
                cout << "A - B = { ";
                ListTraverse_L(Lc);
                cout << "}" << endl;
                DestroyList_L(Lc);
                break;
            }
            case 4:{
                InitList_L(Lc);
                diff_L(Lb, La, Lc);
                cout << "A = ";
                cout << "{ ";
                ListTraverse_L(La);
                cout << "}" << endl;
                cout << "B = ";
                cout << "{ ";
                ListTraverse_L(Lb);
                cout << "}" << endl;
                cout << "B - A = { ";
                ListTraverse_L(Lc);
                cout << "}" << endl;
                DestroyList_L(Lc);
                break;
            }
            case 5:{
                return 0;
            }
        }
    }
    DestroyList_L(La);
    DestroyList_L(Lb);
    return 0;
}

void InputElem(LinkList &L, int n){
    ElemType input;
    for(int i = 1; i <= n; i++){
        cin >> input;
        ListInsert_L(L, i, input);
    }
}

void union_L(LinkList La, LinkList Lb, LinkList &Lc){
    int Lc_len = ListLength_L(Lc);
    int La_len = ListLength_L(La);
    int Lb_len = ListLength_L(Lb);
    ElemType e;
    for(int i = 1; i <= La_len; i++){
        GetElem_L(La, i, e);
        if(!LocalElem_L(Lc, e)){
            ListInsert_L(Lc, ++Lc_len, e);
        }
    }
    for(int i = 1; i <= Lb_len; i++){
        GetElem_L(Lb, i, e);
        if(!LocalElem_L(Lc, e)){
            ListInsert_L(Lc, ++Lc_len, e);
        }
    }
}

void and_L(LinkList La, LinkList Lb, LinkList &Lc){
    int Lc_len = ListLength_L(Lc);
    int La_len = ListLength_L(La);
    ElemType e;
    for(int i = 1; i <= La_len; i++){
        GetElem_L(La, i, e);
        if(LocalElem_L(Lb, e)){
            ListInsert_L(Lc, ++Lc_len, e);
        }
    }
}

void diff_L(LinkList La, LinkList Lb, LinkList &Lc){
    int Lc_len = ListLength_L(Lc);
    int La_len = ListLength_L(La);
    ElemType e;
    for(int i = 1; i <= La_len; i++){
        GetElem_L(La, i, e);
        if(!LocalElem_L(Lb, e)){
            ListInsert_L(Lc, ++Lc_len, e);
        }
    }
}