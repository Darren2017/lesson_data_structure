#include"Queue_Sq.h"

void division(int **R, int n, int result[], int &sum);

int main()
{
    int n, cnt, **R;                //比赛数目，运动员数目，冲突矩阵
    cout << "please input number of match:  ";
    cin >> n;
    R = new int *[n];                       //动态申请冲突矩阵内存
    for(int i = 0; i < n; i++){
        R[i] = new int [n];
    }
    for(int i = 0; i < n; i++){             //初始化冲突矩阵
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
        cout << "please input matchs athlete" << i + 1 << "  enter   ";             //读入某个运动员参与的比赛
        for(int j = 0; j < count; j++){
            cin >> a[j];
        }
        for(int m = 0; m < count; m++){                 //构建冲突矩阵
            for(int n = m + 1; n < count; n++){
                cout << a[m] << "  "  << a[n]  << endl;
                R[a[m]][a[n]] = 1;
                R[a[n]][a[m]] = 1;
            }
        }
    }

    int result[n], sum = 0;
    division(R, n, result, sum);                //划分
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


void division(int **R, int n, int result[], int &sum){
    int pre = n, group = 0, clash[n];           //pre 前一个出队列的序号，用来判断是否需要开辟新组
    QElemType i;
    SqQueue Q;
    InitQueue_Sq(Q, n + 1, 10);
    for(int e = 0; e < n; e++){             //将所有比赛入队，等待检查
        EnQueue_Sq(Q, e);
    }
    while(!QueueEmpty_Sq(Q)){
        DeQueue_Sq(Q, i);
        if(i <= pre){
            group++;                        //开辟新组
            for(int j = 0; j < n; j++){
                clash[j] = 0;
            }
        }
        if(clash[i] == 0){                  //如果无冲突则进入当前组
            result[i] = group;
            for(int j = 0; j < n; j++){         //更新clash数组
                clash[j] += R[i][j];
            }
        }else{                              //有冲突则重新入队
            EnQueue_Sq(Q, i);
        }
        pre = i;
    }
    sum = group;
    DestroyQueue_Sq(Q);
}

// 测试用例
//9 7 3 1 4 8 2 1 7 2 8 3 3 1 0 5 2 3 4 3 5 6 2 2 6 4