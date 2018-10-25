#include"List_Sq_Str.h"
#include<cstring>

int compare(SqList A, SqList B);
void InputElem(SqList &L, string input);

int main()
{
    string A, B;
    SqList La, Lb;
    InitList_Sq(La);
    InitList_Sq(Lb);
    cout << "请输入字符串A：" << endl;
    cin >> A;
    InputElem(La, A);
    cout << "请输入字符串B：" << endl;
    cin >> B;
    InputElem(Lb, B);
    int ans = compare(La, Lb);
    if(ans == 0){
        cout << "A = B" << endl;
    }else if(ans == -1){
        cout << "A < B" << endl;
    }else{
        cout << "A > B" << endl;
    }
    DestroyList_Sq(La);
    DestroyList_Sq(Lb);
    return 0;
}

void InputElem(SqList &L, string input){
    int len = input.size();
    for(int i = 1; i <= len; i++){
        ListInsert_Sq(L, i, input[i - 1]);
    }
}

int compare(SqList A, SqList B){
    int j= 0;
    while(j < A.length && j < B.length){
        if(A.elem[j] < B.elem[j]){
            return -1;
        }else if(A.elem[j] > B.elem[j]){
            return 1;
        }else{
            j++;
        }
    }
    if(A.length == B.length){
        return 0;
    }else if(A.length < B.length){
        return -1;
    }else{
        return 1;
    }
}