/*
 * * 08. 【2023统考真题】已知有向图 G 采用邻接矩阵存储，类型定义如下：
 * typedef struct{              // 图的类型定义
 *     int numVertices,numEdges;// 图的顶点数和有向边数
 *     char VerticesList[MAXV]; // 顶点表，MAXV 为已定义常量
 *     int Edge[MAXV] [MAXV];   // 邻接矩阵
 * } MGraph;
 *
 * 将图中出度大于入度的顶点称为 K 顶点。
 * 请设计算法 int printVertices(MGraph G)，对给定的任意非空有向图 G，输出 G 中所有的 K 顶点，并返回 K 顶点的个数。
 * 要求：
 * 1）给出算法的基本设计思想。
 * 2）根据设计思想，采用 C 或 C++ 语言描述算法，关键之处给出注释。
 * 3）说明你所设计算法的时间复杂度和空间复杂度。
 * */

#include "iostream"
#define MAXV 100
using namespace std;

typedef struct {              // 图的定义
    int numVertices, numEdges;// 图中实际的顶点数和边数
    char VerticesList[MAXV]; // 顶点表。MAXV 为已定义常量
    int Edge[MAXV][MAXV];   // 邻接矩阵
} MGraph;

int printVertices(MGraph G){
    int a[MAXV];
    for (int i = 0; i < G.numVertices; i++){
        for (int j = 0; j < G.numVertices; j++){
            if (G.Edge[i][j]){
                a[i]++;
                a[j]--;
            }
        }
    }

    int num = 0;
    for (int i = 0; i < G.numVertices; i++){
        if (a[i] > 0){
            cout << G.VerticesList[i] << " ";
            num++;
        }
    }

    return num;
}