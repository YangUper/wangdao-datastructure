/*
 * 题目：
 * 04. 分别采用基于深度优先遍历和广度优先遍历算法判别以邻接表方式存储的有向图中是
 * 是否存在由顶点 vi 到顶点 vj 的路径 ( i ≠ j )。注意，算法中涉及的图的基本操作必须在
 * 此存储结构上实现。
 */

#include "iostream"
#include "vector"
#include "queue"
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

void resetVisited(){
    for (int i = 0; i < MAXV; i++)
        visited[i] = false;
}

void BFS(ALGraph* G, int v){
    queue<int> q;
    q.push(v);
    visited[v] = true;

    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (ArcNode* arc = G->vertices[cur].firstArc; arc ; arc = arc->nextArc){
            if (!visited[arc->v]){
                visited[arc->v] = true;
                q.push(arc->v);
            }
        }
    }
}

bool i2jBFS(ALGraph* G, int i, int j){
    if (i == j)
        return true;

    BFS(G, i);
    if (visited[i] && visited[j])
        return true;

    return false;
}

void DFS(ALGraph* G, int v){
    visited[v] = true;
    for (ArcNode* arc = G->vertices[v].firstArc; arc; arc = arc->nextArc){
        if (!visited[arc->v]){
            DFS(G, arc->v);
        }
    }
}

bool i2jDFS(ALGraph* G, int i, int j){
    if (i == j)
        return true;

    DFS(G, i);
    if (visited[i] && visited[j])
        return true;

    return false;
}