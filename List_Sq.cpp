#include"List_Sq.h"

using namespace std;

void InputElem(SqList &L, int n);
void union_Sq(SqList &La, SqList &Lb);

int main()
{
    SqList La, Lb;
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
    union_Sq(La, Lb);
    cout << "合并之后列表为：" << endl;
    cout << "{ ";
    ListTraverse_Sq(La);
    cout << "}" << endl;
    DestroyList_Sq(La);

    return 0;
}

void InputElem(SqList &L, int n){                 // 输入    时间复杂度O(n)   空间复杂度O(1)
    ElemType input;
    for(int i = 1; i <= n; i++){
        cin >> input;
        ListInsert_Sq(L, i, input);
    }
}

void union_Sq(SqList &La, SqList &Lb){              //合并     时间复杂度O(n)   空间复杂度O(1)
    int La_len = ListLength_Sq(La);
    ElemType e;
    while(!ListEmpty_Sq(Lb)){
        ListDelete_Sq(Lb, 1, e);
        if(!LocalElem_Sq(La, e)){
            ListInsert_Sq(La, ++La_len, e);
        }
    }
    DestroyList_Sq(Lb);
}

// void show_menu();

// int main()
// {
//     SqList L;
//     InitList_Sq(L);
//     ListInsert_Sq(L, 1, 1);
//     ListInsert_Sq(L, 1, 1);
//     ListInsert_Sq(L, 1, 1);
//     ListTraverse(L);
//     while(false){
//         show_menu();
//         int choice;
//         cin >> choice;
//         switch(choice){
//             case 1:{
//                 InitList_Sq(L);
//                 break;
//             }
//             case 2:{
//                 DestroyList_Sq(L);
//                 break;
//             }
//             case 3:{
//                 ClearList_Sq(L);
//                 break;
//             }
//             case 4:{
//                 bool ans = ListEmpty_Sq(L);
//                 if(ans){
//                     cout << "线性表为空" << endl;
//                 }else{
//                     cout << "线性表不为空" << endl;
//                 }
//                 break;
//             }
//             case 5:{
//                 int len = ListLength_Sq(L);
//                 cout << "线性表的长度是" << len << endl << endl;
//                 break;
//             }
//             case 6:{
//                 int i;
//                 cout << "输入要现实第几个元素的值：  ";
//                 cin >> i;
//                 ElemType e;
//                 GetElem_Sq(L, i, e);;
//                 cout << "第" << i << "个元素是 " << e << endl;
//                 break;
//             }
//             case 7:{
//                 ElemType e;
//                 cout << "输入要查找的元素：" << endl;
//                 cin >> e;
//                 int i = LocalElem_Sq(L, e);
//                 if(i == 0){
//                     cout << "未找到" << e << endl;
//                 }else{
//                     cout << e << "是第" << i << "个元素" << endl;
//                 }
//                 break;
//             }
//         }
//     }
//     return 0;
// }

// void show_menu(){
//     cout << "1: init" << endl <<  "2: destroy" << endl << "3: clear" << endl;
//     cout << "4: isempty" << endl << "5: length" << endl << "6: get_elem" << endl;
//     cout << "7: locate_elem" << endl << "8: prior_elem" << endl <<"9: next_elem" << endl;
//     cout << "10: insert" << endl << "11:delete" << endl << "12: traverse" << endl;
//     cout << "-------------------" << endl << endl << "请输入你的选择" << endl;
// }