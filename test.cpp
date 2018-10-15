// #include"Queue_Sq.h"
#include"Queue_L.h"

int main()
{
    LinkQueue Q;
    InitQueue_L(Q);
    for(int i = 0; i < 105; i++){
        EnQueue_L(Q, i + 1);
    }
    int a[109];

    QueueTraverse_L(Q);

    for(int i = 0; !QueueEmpty_L(Q); i++){
        DeQueue_L(Q, a[i]);
    }

    cout << endl << endl;
    for(int i = 0; i < 105; i++){
        cout << a[i] << "  ";
    }

    return 0;
}