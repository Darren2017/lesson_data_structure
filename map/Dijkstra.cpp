// 无向有权图
#include<iostream>
#include<iomanip>
#include<cstring>

using namespace std;

#define MAXVEX 100
#define INFINITY 65535

typedef int EdgeType;
typedef char VertexType;

struct Dist{
    string path;
    int value;
    bool visited;
    Dist(){
        visited = false;
        value = 0;
        path = "";
    }
};

typedef struct
{
    VertexType *vexs;
    EdgeType **arcs;
    int numNodes, numEdges;
    Dist *dist;
} MGraph;

void CreateMGraph(MGraph& MG);
int Locate(MGraph MG, VertexType v);
void dijkstra(MGraph& MG);

int main()
{
    MGraph MG;
    CreateMGraph(MG);
    dijkstra(MG);

    return 0;
}

int Locate(MGraph MG, VertexType v){
    for(int i = 1; i <= MG.numNodes; i++){
        if(MG.vexs[i] == v){
            return i;
        }
    }
    return 0;
}

void CreateMGraph(MGraph& MG){
    cout << "请输入顶点数和边数：" << endl;
    cin >> MG.numNodes >> MG.numEdges;      //输入点数和边数
    MG.vexs = new VertexType[MG.numNodes];  //动态申请内存
    MG.arcs = new EdgeType *[MG.numNodes];
    for(int i = 0; i < MG.numNodes; i++){
        MG.arcs[i] = new EdgeType[MG.numNodes];
    }
    MG.dist = new Dist[MG.numNodes];

    cout << "请输入顶点信息：" << endl;
    for(int i = 0; i < MG.numNodes; i++){
        cin >> MG.vexs[i];
    }
    for(int i = 0; i < MG.numNodes; i++){       //初始化邻接矩阵
        for(int j = 0; j < MG.numNodes; j++){
            if(i == j){
                MG.arcs[i][j] = 0;
            }else{
                MG.arcs[i][j] = INFINITY;
            }
        }
    }
    for(int k = 0; k < MG.numEdges; k++){       //构造邻接矩阵
        char v1, v2;
        int w;
        cout << "请输入边(vi, vj)和权值w：" << endl;
        cin >> v1 >> v2 >> w;
        int i = Locate(MG, v1), j = Locate(MG, v2);
        MG.arcs[i][j] = w;
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

void dijkstra(MGraph& MG){
    char ch;
    cout << "请输入起始点：";
    cin >> ch;
    int start = Locate(MG, ch);
    for(int i = 0; i < MG.numNodes; i++){           //初始化dist数组，记录当前最短路径
        string a = "", b = "";
        a.insert(0, 1, MG.vexs[start]);
        b.insert(0, 1, MG.vexs[i]);
        MG.dist[i].visited = false;
        MG.dist[i].value = MG.arcs[start][i];
        MG.dist[i].path = "v" + a + "-->v" + b;
    }
    MG.dist[start].visited = true;          //源点进入已选择集合
    MG.dist[start].value = 0;
    int cnt = 1;
    while(cnt < MG.numNodes){               //选择最短的一条路径的终点进入集合
        int now = 0;
        int mmin = INFINITY;
        for(int i = 0; i < MG.numNodes; i++){
            if(!MG.dist[i].visited && MG.dist[i].value < mmin){
                now = i;
                mmin = MG.dist[i].value;
            }
        }
        MG.dist[now].visited = true;
        cnt++;
        for(int i = 0; i < MG.numNodes; i++){           //维护dist数组，如果经过最短路径集合的路径小于直接路径则更新。
            if(!MG.dist[i].visited && MG.arcs[now][i] != 0 && MG.dist[now].value + MG.arcs[now][i] < MG.dist[i].value){
                MG.dist[i].value = MG.dist[now].value + MG.arcs[now][i];
                string a;
                a.insert(0, 1, MG.vexs[i]);
                MG.dist[i].path = MG.dist[now].path + "-->v" + a;
            }
        }
    }
    cout << "以v" << MG.vexs[start] << "为起点的最短路径为：" << endl;
    for(int i = 0; i < MG.numNodes; i++){
        if(MG.dist[i].value == INFINITY){
            cout << "v" << MG.vexs[start] << "到v" << MG.vexs[i] << "没有最短路径" << endl;
        }else{
            cout << MG.dist[i].path << " = " << MG.dist[i].value << endl;
        }
    }
}

// 测试用例
// 10 7
// a b c d e f g
// a g 9
// b a 20
// b c 10
// b d 30
// c e 5
// e g 15
// e d 12
// f e 8
// f g 10
// g c 18
// b
