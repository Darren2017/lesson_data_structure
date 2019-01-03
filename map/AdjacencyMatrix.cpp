// 无向有权图
#include<iostream>
#include<iomanip>
#include"h/Queue_Sq.h"

using namespace std;

#define INFINITY 65535

typedef int EdgeType;
typedef char VertexType;

typedef struct
{
    VertexType *vexs;           //存放元素信息
    EdgeType **arcs;            //邻接矩阵
    int numNodes, numEdges;
} MGraph;

void CreateMGraph(MGraph& MG);
void BFSTraverse(MGraph G);
void VisitFunc(VertexType v);

int main()
{
    MGraph MG;
    CreateMGraph(MG);
    BFSTraverse(MG);

    return 0;
}

void CreateMGraph(MGraph& MG){
    cout << "请输入顶点数和边数：" << endl;
    cin >> MG.numNodes >> MG.numEdges;
    MG.vexs = new VertexType[MG.numNodes];
    MG.arcs = new EdgeType* [MG.numNodes];
    for(int i = 0; i < MG.numNodes; i++){
        MG.arcs[i] = new EdgeType[MG.numNodes];
    }
    cout << "请输入顶点信息：" << endl;
    for(int i = 0; i < MG.numNodes; i++){
        cin >> MG.vexs[i];
    }
    for(int i = 0; i < MG.numNodes; i++){
        for(int j = 0; j < MG.numNodes; j++){
            if(i == j){
                MG.arcs[i][j] = 0;
            }else{
                MG.arcs[i][j] = INFINITY;
            }
        }
    }
    for(int k = 0; k < MG.numEdges; k++){
        int i, j, w;
        cout << "请输入边(vi, vj)和权值w：" << endl;
        cin >> i >> j >> w;
        MG.arcs[i - 1][j - 1] = w;
        MG.arcs[j - 1][i - 1] = w;
    }

    for(int i = 0; i < MG.numNodes; i++){       //输出邻接矩阵
        for(int j = 0; j < MG.numNodes; j++){
            if(MG.arcs[i][j] == 65535){
                cout << "     M ";
            }else{
                cout << setw(6) << MG.arcs[i][j] << " ";
            }
        }
        cout << endl << endl;
    }
}

void BFSTraverse(MGraph G){
    bool visited[G.numNodes];
    SqQueue Q;
    InitQueue_Sq(Q);
    // queue<int> Q;
    for(int i = 0; i < G.numNodes; i++){        //初始化访问数组
        visited[i] = false;
    }
    for(int i = 0; i < G.numNodes; i++){
        if(!visited[i]){
            visited[i] = true;      //立刻标记为以访问
            VisitFunc(G.vexs[i]);
            EnQueue_Sq(Q, i);       //将当前访问元素入队
            // Q.push(i);
            while(!QueueEmpty_Sq(Q)){
                int u;
                // GetHead_Sq(Q, u);
                // int u = Q.front();
                DeQueue_Sq(Q, u);
                for(int w = 0; w < G.numNodes; w++){        //遍历所有元素，只要是有边相连，并且未访问则访问该元素
                    if(G.arcs[u][w] != INFINITY && !visited[w] && G.arcs[u][w] != 0){
                        visited[w] = true;
                        VisitFunc(G.vexs[w]);
                        EnQueue_Sq(Q, w);
                        // Q.push(w);
                    }
                }
            }
        }
    }
}

void VisitFunc(VertexType v){
    cout << v << "  ";
}

// 测试用例
// 9 11
// 1 2 3 4 5 6 7 8 9
// 1 2 1
// 1 3 1
// 1 4 1
// 2 3 1
// 2 4 1
// 3 6 1
// 4 9 1
// 5 6 1
// 5 7 1
// 5 8 1
// 7 8 1