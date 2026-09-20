/*
 * 假设图用邻接表表示，设计一个算法，输出从顶点vi到vj的所有简单路径。
 * */

#include "iostream"
#include "vector"
#define MAXV 100
using namespace std;

// 边节点
typedef struct ArcNode{
    int v;
    struct ArcNode* nextArc;
}ArcNode;

// 顶点
typedef struct VNode{
    int data;
    ArcNode *firstArc;
}VNode;

// 邻接表表示的图
typedef struct ALGraph{
    VNode vertices[MAXV];
    int vNum, arcNum;
}ALGraph;

vector<bool> visited(MAXV, false);

void DFS(ALGraph* G, int v, int j, vector<int>& path){
    visited[v] = true;
    path.push_back(v);

    if (v == j){
        for (int val: path){
            cout << val << " ";
        }
        cout << endl;
    } else{
        for (ArcNode* arc = G->vertices[v].firstArc; arc; arc = arc->nextArc){
            if (!visited[arc->v])
                DFS(G, arc->v, j, path);
        }
    }

    visited[v] = false;
    path.pop_back();
}

void printI2J(ALGraph* G, int i, int j){
    vector<int> path;
    DFS(G, i, j, path);
}