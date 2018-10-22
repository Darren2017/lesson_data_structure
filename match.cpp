#include"Queue_Sq.h"

void division(int **R, int n, int result[], int &sum);

int main()
{
    int n, cnt, **R;
    cout << "please input number of match:  ";
    cin >> n;
    R = new int *[n];
    for(int i = 0; i < n; i++){
        R[i] = new int [n];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
             R[i][j]  = 0;
        }
    }
    cout << "please input number of athlete:  ";
    cin >> cnt;
    for(int i = 0; i < cnt; i++){
        int count;
        cout << "please input number of match which athlete" << i + 1 << " enter:  ";
        cin >> count;
        int a[count];
        cout << "please input matchs athlete" << i + 1 << "  enter   ";
        for(int j = 0; j < count; j++){
            cin >> a[j];
        }
        for(int m = 0; m < count; m++){
            for(int n = m + 1; n < count; n++){
                cout << a[m] << "  "  << a[n]  << endl;
                R[a[m]][a[n]] = 1;
                R[a[n]][a[m]] = 1;
            }
        }
    }

    int result[n], sum = 0;
    division(R, n, result, sum);
    for(int i = 1; i <= sum; i++){
        cout << "第" << i << "组的比赛有第：";
        for(int j = 0; j < n; j++){
            if(result[j] == i){
                cout << j << "  ";
            }
        }
        cout << "组" << endl;
    }

    return 0;
}

//9 7 3 1 4 8 2 1 7 2 8 3 3 1 0 5 2 3 4 3 5 6 2 2 6 4


void division(int **R, int n, int result[], int &sum){
    int pre = n, group = 0, clash[n];
    QElemType i;
    SqQueue Q;
    InitQueue_Sq(Q, n + 1, 10);
    for(int e = 0; e < n; e++){
        EnQueue_Sq(Q, e);
    }
    while(!QueueEmpty_Sq(Q)){
        DeQueue_Sq(Q, i);
        if(i <= pre){
            group++;
            for(int j = 0; j < n; j++){
                clash[j] = 0;
            }
        }
        if(clash[i] == 0){
            result[i] = group;
            for(int j = 0; j < n; j++){
                clash[j] += R[i][j];
            }
        }else{
            EnQueue_Sq(Q, i);
        }
        pre = i;
    }
    sum = group;
}