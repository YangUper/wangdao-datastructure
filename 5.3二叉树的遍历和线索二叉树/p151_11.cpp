/*
 * 假设二叉树采用二叉链表存储结构，设计一个算法，求非空二叉树b的宽度（具有节点数最多的那一层的节点数）
 * */

#include "iostream"
#include "queue"
using namespace std;

typedef struct BiNode{
    int data;
    BiNode* lchild;
    BiNode* rchild;
}BiNode, *BiTree;

int widthOfBiTree(BiTree tree){
    if (!tree)
        return 0;

    queue<BiNode*> q;
    q.push(tree);
    int width = 0;
    while (!q.empty()){
        int levelSize = q.size();
        width = max(width, levelSize);
        for (int i = 0; i < levelSize; i++){
            BiNode *p = q.front();
            q.pop();
            if (p->lchild)
                q.push(p->lchild);
            if (p->rchild)
                q.push(p->rchild);
        }
    }

    return width;
}