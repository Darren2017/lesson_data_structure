#include"Queue_Sq.h"
#include<iomanip>

void yanghui(int n);
void yanghui_T(int n);

int main(){
    int n;
    cin >> n;
    yanghui_T(n);
    return 0;
}
void yanghui(int n){
    SqQueue Q;
    QElemType s, e;
    for(int i = 0; i < n; i++){
        cout << "   ";
    }
    cout << setw(3) << '1' << endl;
    InitQueue_Sq(Q, n + 3);
    EnQueue_Sq(Q, 0);
    EnQueue_Sq(Q, 1);
    EnQueue_Sq(Q, 1);
    int k = 1;
    while(k < n){
        for(int i = 0; i < n - k; i++){
            cout << "   ";
        }
        EnQueue_Sq(Q, 0);
        do{
            DeQueue_Sq(Q, s);
            GetHead_Sq(Q, e);
            if(e){
                cout << setw(3) << e << "   ";
            }else{
                cout << endl;
            }
            EnQueue_Sq(Q, s + e);
        }while(e != 0);
        k++;
    }
    DeQueue_Sq(Q, e);
    while(!QueueEmpty_Sq(Q)){
        DeQueue_Sq(Q, e);
        cout << setw(3) << e << "   ";
    }
    DestroyQueue_Sq(Q);
}


void yanghui_T(int n){
    SqQueue Q;
    InitQueue_Sq(Q, n + 2);
    QElemType s, e;
    for(int i = 0; i < n; i++){
        cout << "   ";
    }
    cout << setw(3) << '1' << endl;
    EnQueue_Sq(Q, 0);
    EnQueue_Sq(Q, 1);
    EnQueue_Sq(Q, 1);
    int k = 1;
    while(k < n){
        for(int i = 0; i < n - k; i++){
            cout << "   ";
        }
        EnQueue_Sq(Q, 0);
        do{
            DeQueue_Sq(Q, s);
            GetHead_Sq(Q, e);
            EnQueue_Sq(Q, s + e);
            if(e){
                cout << setw(3) << e << "   ";
            }else{
                cout << endl;
            }
        }while(e);
        k++;
    }
    DeQueue_Sq(Q, e);
    while(!QueueEmpty_Sq(Q)){
        DeQueue_Sq(Q, e);
        cout << setw(3) << e << "   ";
    }
    DestroyQueue_Sq(Q);
}