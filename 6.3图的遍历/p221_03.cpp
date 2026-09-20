/*
 * 试设计一个算法，判断一个无向图G是否为一棵树。若是一棵树，则算法返回true，否则返回false。
 * */

#include "iostream"
#include "queue"
#include "vector"
#define MAXV 100
using namespace std;

typedef struct {              // 图的定义
    int numVertices, numEdges;// 图中实际的顶点数和边数
    char VerticesList[MAXV]; // 顶点表。MAXV 为已定义常量
    int Edge[MAXV][MAXV];   // 邻接矩阵
} MGraph;

void BFS(MGraph G, int v, vector<bool> visited){
    queue<int> q;
    q.push(v);
    visited[v] = true;// 入队立即标记已访问
    while (!q.empty()){
        int cur = q.front();
        q.pop();

        for (int i = 0; i < G.numVertices; i++){
            if (G.Edge[cur][i] && !visited[i]){
                q.push(i);
            }
        }
    }
}

bool isTree(MGraph G){
    vector<bool> visited(G.numVertices, false);
    int cnt = 0;
    for (int i = 0; i < G.numVertices; i++){
        if (!visited[i]){
            cnt++;
            BFS(G, i, visited);
        }
    }

    if (G.numEdges + 1 == G.numVertices && cnt == 1){
        return true;
    } else{
        return false;
    }
}