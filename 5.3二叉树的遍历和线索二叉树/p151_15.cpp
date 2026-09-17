/*
 * 【2014 统考真题】
题目描述：
    二叉树的带权路径长度（WPL）是二叉树中所有叶结点的带权路径长度之和。
    给定一棵二叉树 T，采用二叉链表存储，结点结构为：
    +------+--------+-------+
    | left | weight | right |
    +------+--------+-------+
    其中叶结点的 weight 域保存该结点的非负权值。设 root 为指向 T 的根结点的指针，
    请设计求 T 的 WPL 的算法。

要求：
1) 给出算法的基本设计思想。
2) 使用 C 或 C++ 语言，给出二叉树结点的数据类型定义。
3) 根据设计思想，采用 C 或 C++ 语言描述算法，关键之处给出注释。
 * */

#include "iostream"
#include "queue"
using namespace std;

typedef struct BiNode{
    int weight;
    BiNode* left;
    BiNode* right;
}BiNode, *BiTree;

int WPL_Recursion(BiTree root, int height){
    if (!root)
        return 0;

    if (!root->left && !root->right)
        return height * root->weight;

    return WPL_Recursion(root->left, height + 1) + WPL_Recursion(root->right, height + 1);
}

int WPL_NORecursion(BiTree root){
    if (!root)
        return 0;

    queue<BiNode*> q;
    q.push(root);
    int sum = 0;
    int height = 0;
    while (!q.empty()){
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++){
            BiNode* tem = q.front();
            q.pop();
            if (!tem->left && !tem->right)
                sum += tem->weight * height;
            if (tem->left)
                q.push(tem->left);
            if (tem->right)
                q.push(tem->right);
        }
        height++;
    }
    return sum;
}