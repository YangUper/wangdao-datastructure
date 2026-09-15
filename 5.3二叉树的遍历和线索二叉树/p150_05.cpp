/*
 * 假设二叉树采用二叉链表存储结构，试设计一个算法，计算一颗给定二叉树的所有双分支结点个数。
 * */

#include "iostream"
#include "queue"
using namespace std;

typedef struct BiNode{
    int data;
    BiNode* lchild;
    BiNode* rchild;
}BiNode, *BiTree;

void recursionDoubleNum(BiTree tree, int &num){
    if (!tree){
        return;
    }

    if (tree->rchild && tree->lchild)
        num++;

    if (tree->lchild)
        recursionDoubleNum(tree->lchild, num);

    if (tree->rchild)
        recursionDoubleNum(tree->rchild, num);
}

int doubleNum(BiTree tree){
    if (!tree)
        return 0;

    int num = 0;
    queue<BiNode*> q;
    q.push(tree);
    while (!q.empty()){
        BiNode* p = q.front();
        q.pop();
        if (p->lchild && p->rchild)
            num++;
        if (p->lchild)
            q.push(p->lchild);
        if (p->rchild)
            q.push(p->rchild);
    }

    return num;
}