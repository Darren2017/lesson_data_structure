// 无向有权图
#include<iostream>
#include<iomanip>
#include<queue>

using namespace std;

#define INFINITY 65535

#define EdgeType int
#define VertexType char

typedef struct
{
    VertexType vexs[100];
    EdgeType arcs[100][100];
    int numNodes, numEdges;
} MGraph;

void CreateMGraph(MGraph& MG);
int Locate(MGraph MG, VertexType v);
int Prim(MGraph MG);

int main()
{
    MGraph MG;
    CreateMGraph(MG);
    cout << Prim(MG);

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

void CreateMGraph(MGraph& MG){              //创建邻接矩阵
    cout << "请输入顶点数和边数：" << endl;
    cin >> MG.numNodes >> MG.numEdges;
    cout << "请输入顶点信息：" << endl;
    for(int i = 1; i <= MG.numNodes; i++){
        cin >> MG.vexs[i];
    }
    for(int i = 1; i <= MG.numNodes; i++){
        for(int j = 1; j <= MG.numNodes; j++){
            if(i == j){
                MG.arcs[i][j] = 0;
            }else{
                MG.arcs[i][j] = INFINITY;
            }
        }
    }
    for(int k = 0; k < MG.numEdges; k++){
        char v1, v2;
        int w;
        cout << "请输入边(vi, vj)和权值w：" << endl;
        cin >> v1 >> v2 >> w;
        int i = Locate(MG, v1), j = Locate(MG, v2);
        MG.arcs[i][j] = w;
        MG.arcs[j][i] = w;
    }

    for(int i = 1; i <= MG.numNodes; i++){
        for(int j = 1; j <= MG.numNodes; j++){
            if(MG.arcs[i][j] == 65535){
                cout << "     M ";
            }else{
                cout << setw(6) << MG.arcs[i][j] << " ";
            }
        }
        cout << endl << endl;
    }
}

int Prim(MGraph MG){
    int sta[MG.numNodes + 1];
    int lowcost[MG.numNodes + 1];
    int min, minid, sum = 0;
    for(int i = 1; i <= MG.numNodes; i++){          //初始化lowcost数组，所有值都为从第一顶点出发的权重
        lowcost[i] = MG.arcs[1][i];
        sta[i] = 1;
    }
    sta[1] = 0;         //第一个顶点进入集合

    for(int h = 2; h <= MG.numNodes; h++){
        min = 65535;
        for(int j = 2; j <= MG.numNodes; j++){              //寻找权重最小的顶点，用min记录权重，minid记录顶点
            if(lowcost[j] < min && lowcost[j] != 0){
                min = lowcost[j];
                minid = j;
            }
        }
        lowcost[minid] = 0;             //最小顶点进入集合
        cout << MG.vexs[sta[minid]] << " -> " << MG.vexs[minid] << " :  " <<min << endl;
        sum += min;
        for(int s = 2; s <= MG.numNodes; s++){                  //维护lowcost数组与sta数组
            if(lowcost[s] > MG.arcs[minid][s] && MG.arcs[minid][s]){
                lowcost[s] = MG.arcs[minid][s];
                sta[s] = minid;
            }
        }
    }
    return sum;
}

// 测试用例
// 7 11
// a b c e d f g
// a b 12
// a f 16
// a g 14
// b c 10
// b f 7
// c d 3
// c f 6
// c e 5
// d e 4
// f e 2
// f g 8