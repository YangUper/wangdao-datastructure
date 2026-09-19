/*
 ** 07. 【2021统考真题】已知无向连通图G由顶点集V和边集E组成，|E|>0，当G中度为奇数的顶点个数为不大于2的偶数时，
 * G存在包含所有边且长度为|E|的路径（称为EL路径）。设图G采用邻接矩阵存储，类型定义如下：
 * typedef struct{              // 图的定义
 *     int numVertices,numEdges;// 图中实际的顶点数和边数
 *     char VerticesList[MAXV]; // 顶点表。MAXV 为已定义常量
 *     int Edge[MAXV] [MAXV];   // 邻接矩阵
 * } MGraph;
 *
 * 请设计算法 int IsExistEL(MGraph G)，判断G是否存在EL路径，若存在，则返回1，否则返回0。
 * 要求：
 * 1）给出算法的基本设计思想。
 * 2）根据设计思想，采用C或C++语言描述算法，关键之处给出注释。
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

int IsExistEL(MGraph G){
    int num = 0;
    for (int i = 0; i < G.numVertices; i++){
        int cnt = 0;
        for(int j = 0; j < G.numVertices; j++){
            if (G.Edge[i][j]){
                cnt++;
            }
        }
        if (cnt % 2){
            num++;
        }
    }
    if (num == 0 || num == 2){
        return 1;
    } else{
        return 0;
    }
}