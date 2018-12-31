#include"Stack_Sq.h"

using namespace std;

typedef struct DQNode{
    PosType seat;
    struct DQNode *next;
    struct DQNode *pre;
}DQNode, *DqueuePtr;

typedef struct{
    DqueuePtr front;
    DqueuePtr rear;
}DLinkQueue;

int nextxpos[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int nextypos[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void InitQueue(DLinkQueue &Q);
void EnQueue(DLinkQueue &Q, PosType e);
void GetHead(DLinkQueue Q, PosType &e);
void DeQueue(DLinkQueue &Q);
bool QueueEmpty(DLinkQueue Q); 
bool ShortestPath(int **maze, int m, int n, SqStack &S);

int main()
{
    int m, n;
    cout << "请输入迷宫的行列数：";
    cin >> m  >> n;
    int **maze = new int*[m];
    for(int i = 0; i < m; i++){
        cout << "请输入第" << i + 1 << "行的布局：";
        maze[i] = new int[n];
        for(int j = 0; j < n; j++){
            cin >> maze[i][j];
        }
    }
    SqStack S;
    bool ans = ShortestPath(maze, m, n, S);
    if(ans){
        StackTraverse_Sq(S);
    }else{
        cout << "no answer";
    }
    return 0;
}



void InitQueue(DLinkQueue &Q){
    Q.front = NULL;
    Q.rear = NULL;
}

void EnQueue(DLinkQueue &Q, PosType e){
    DqueuePtr p = new DQNode;
    p -> seat.xpos = e.xpos;
    p -> seat.ypos = e.ypos;
    p -> next = NULL;
    if(!Q.rear){
        p -> pre = NULL;
        Q.rear = p;
        Q.front = p;
    }else{
        p -> pre = Q.front;
        Q.rear -> next = p;
        Q.rear = p;
    }
}

void GetHead(DLinkQueue Q, PosType &e){
    e.xpos = Q.front -> seat.xpos;
    e.ypos = Q.front -> seat.ypos;
}

void DeQueue(DLinkQueue &Q){
    Q.front = Q.front -> next;
}

bool QueueEmpty(DLinkQueue Q){
    return Q.front == NULL;
}

bool ShortestPath(int **maze, int m, int n, SqStack &S){
    DLinkQueue Q;
    bool visited[m][n], found = false;
    PosType e, curpos, npos;
    e.xpos = 0;
    e.ypos = 0;
    InitQueue(Q);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = false;
        }
    }
    if(maze[0][0] != 0){
        return false;
    }
    EnQueue(Q, e);
    while(!found && !QueueEmpty(Q)){
        GetHead(Q, curpos);
        visited[curpos.xpos][curpos.ypos] = true;
        for(int v = 0; v < 8 && !found; v++){
            npos.xpos = curpos.xpos +  nextxpos[v];
            npos.ypos = curpos.ypos +  nextypos[v];
            if(0 <= npos.xpos && npos.xpos < n && 0 <= npos.ypos && npos.ypos < m && maze[npos.ypos][npos.xpos] == 0 && visited[npos.ypos][npos.xpos] == false){
                EnQueue(Q, npos);
                visited[npos.ypos][npos.xpos] = true;
            }
            if(npos.xpos == n - 1 &&npos.ypos == m - 1){
                found = true;
            }
        }
        DeQueue(Q);
    }
    if(found){
        InitStack_Sq(S);
        DqueuePtr p = Q.rear;
        while(p){
            Push_Sq(S, p -> seat);
            p = p -> pre;
        }
        return true;
    }else{
        return false;
    }
}

// 6 8
// 0 1 0 1 0 0 0 1
// 1 0 0 1 1 0 1 0
// 0 1 1 0 0 1 1 1
// 1 0 0 1 1 0 0 1
// 1 0 0 0 1 1 0 1
// 0 1 1 1 0 0 0 0