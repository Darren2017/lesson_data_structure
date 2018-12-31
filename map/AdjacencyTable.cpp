#include<iostream>
#define InfoType int
#define VertexType char

using namespace std;

const int MAX_VERTEX_NUM = 20;

typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextarc;
    InfoType *info;
}ArcNode;

typedef struct VNode{
    VertexType data;
    ArcNode *firstarc;
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct{
    AdjList vertices;
    int vexnum, arcnum;
    int kind;
} ALGraph;

void CreateUDG(ALGraph &G);
int LocateVex(ALGraph G, VertexType v);
void DFS(ALGraph G, int v, bool *visited);
void DFSTraverse(ALGraph G);
void VisitFunc(VertexType data);

int main()
{
    ALGraph G;
    CreateUDG(G);
    DFSTraverse(G);

    return 0;
}

void CreateUDG(ALGraph &G){
    cout << "请输入顶点数和边数：" << endl;
    cin >> G.vexnum >> G.arcnum;

    for(int i = 0; i < G.vexnum; i++){
        cout << "请输入顶点信息：" << endl;
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }
    for(int k = 0; k < G.arcnum; k++){
        char  v1, v2;
        cout << "请输入边(vi, vj)" << endl;
        cin >> v1 >> v2;
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);
        ArcNode *pi = new ArcNode;      //采用前查的方式放入新节点
        pi -> adjvex = j;
        pi -> nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = pi;

        ArcNode *pj = new ArcNode;      ////采用前查的方式放入新节点
        pj -> adjvex = i;
        pj -> nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = pj;
    }
}

int LocateVex(ALGraph G, VertexType v){         //查找相应元素的下标
    for(int i = 0; i < G.vexnum; i++){
        if(G.vertices[i].data == v){
            return i;
        }
    }
    return 0;
}

void DFS(ALGraph G, int v, bool *visited){
    visited[v] = true;
    VisitFunc(G.vertices[v].data);
    for(ArcNode *p = G.vertices[v].firstarc; p; p = p -> nextarc){
        int w = p -> adjvex;
        if(!visited[w]){
            DFS(G, w, visited);
        }
    }

}
void DFSTraverse(ALGraph G){
    bool *visited = new bool[G.vexnum];
    for(int i = 0; i < G.vexnum; i++){      //初始化访问数组
        visited[i] = false;
    }
    for(int i = 0; i < G.vexnum; i++){          //避免非连通图有访问不到的情况
        if(!visited[i]){
            DFS(G, i, visited);
        }
    }
}

void VisitFunc(VertexType data){
    cout << data << " ";
}

// 测试用例
// 9 11
// 1 2 3 4 5 6 7 8 9
// 1 2
// 1 3
// 1 4
// 2 3
// 2 4
// 3 6
// 4 9
// 5 6
// 5 7
// 5 8
// 7 8