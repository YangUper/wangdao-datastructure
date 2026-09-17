/*
 * 【2022 统考真题】
题目描述：
    已知非空二叉树 T 的结点值均为正整数，采用顺序存储方式保存，数据结构定义如下：
    typedef struct {
        int SqBiTNode[MAX_SIZE]; // MAX_SIZE 为已定义常量，保存二叉树结点值的数组
        int ElemNum;             // 实际占用的数组元素个数
    } SqBiTree;
    T 中不存在的结点在数组 SqBiTNode 中用 -1 表示。

要求：
    请设计一个尽可能高效的算法，判定一棵采用这种方式存储的二叉树是否为二叉搜索树，
    若是，则返回 true，否则，返回 false。
1) 给出算法的基本设计思想。
2) 根据设计思想，采用 C 或 C++ 语言描述算法，关键之处给出注释。
 * */

#include "iostream"
#define MAX_SIZE 100
using namespace std;

typedef struct {
    int SqBiTNode[MAX_SIZE]; // MAX_SIZE 为已定义常量，保存二叉树结点值的数组
    int ElemNum;             // 实际占用的数组元素个数
} SqBiTree;

bool isBisearchHelper(SqBiTree sqBiTree, int index, int& preVal){
    if (index >= sqBiTree.ElemNum || sqBiTree.SqBiTNode[index] == -1)
        return true;

    if (!isBisearchHelper(sqBiTree, 2 * index + 1, preVal))
        return false;

    if (preVal >= sqBiTree.SqBiTNode[index])
        return false;
    preVal = sqBiTree.SqBiTNode[index];

    return isBisearchHelper(sqBiTree, 2 * index + 2, preVal);
}

bool isBiSearch(SqBiTree sqBiTree){
    int preVal = -1;
    return isBisearchHelper(sqBiTree, 0, preVal);
}