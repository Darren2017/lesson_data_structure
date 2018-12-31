#include<iostream>
#include<algorithm>

using namespace std;

typedef struct edge{
    int x, y, w;
}edge;          //存放每条边
int *p;     //并查集
char *vex;      //元素信息

static bool cmp(edge a, edge b);
int root(int a);
int connected(int a, int b);
int Locate(int numNodes, char v);
void Union(int a, int b);
void kruskal(edge *e, int numNodes, int numEdges);

int main()
{
    int numNodes, numEdges;
    cout << "输入边的个数，点的个数" << endl;
    cin >> numEdges >> numNodes;
    edge *e = new edge[numEdges];
    p = new int[numNodes + 1];
    vex = new char[numNodes + 1];
    cout << "请输入顶点信息：" << endl;
    for(int i = 1; i <= numNodes; i++){
        cin >> vex[i];
    }
    cout << "分别输入所有的边的定点、权重" << endl;
    for(int i = 0; i < numEdges; i++){          //构造网
        char a, b;
        cin >> a >> b >> e[i].w;
        e[i].x = Locate(numNodes, a);
        e[i].y = Locate(numNodes, b);
    }
    for(int i = 1; i <= numNodes; i++){         // 初始化并查集，使每个节点的根节点是自身
        p[i] = i;
    }
    kruskal(e, numNodes, numEdges);             //调用Kruskal算法

    return 0;
}

void kruskal(edge *e, int numNodes, int numEdges){
    sort(e, e + numEdges, cmp);                 //对所有边进行升序排列
    for(int i = 0; i < numEdges; i++){ 
        if(!connected(e[i].x, e[i].y)){         //如果没有连接，则进行连接
            Union(e[i].x, e[i].y);
            cout << vex[e[i].x] << "-->" << vex[e[i].y] << "  " << e[i].w << endl;
        }
    }
}

int Locate(int numNodes, char v){
    for(int i = 1; i <= numNodes; i++){
        if(vex[i] == v){
            return i;
        }
    }
    return 0;
}


static bool cmp(edge a, edge b){
    return a.w < b.w;
}

int root(int a){            //查找某个节点的根节点
    if(a != p[a]){
        p[a] = root(p[a]);
    }
    return p[a];
}

int connected(int a, int b){            //通过判断根节点是否相同，判断是否连接
    return root(a) == root(b);
}

void Union(int a, int b){           //连接
    if(!connected(a, b)){
        p[root(a)] = root(b);
    }
}

// 11 7
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