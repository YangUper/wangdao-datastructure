/*
 * 二叉树按二叉链表形式存储，试编写一个判别给定二叉树是否是完全二叉树的算法。
 * */

#include "iostream"
#include "queue"
using namespace std;

typedef struct BiNode{
    int data;
    BiNode* lchild;
    BiNode* rchild;
}BiNode, *BiTree;

bool isCompleteBiTree(BiTree tree){
    if (tree == nullptr)
        return true;

    int flag = true;
    queue<BiTree> q;
    q.push(tree);

    while (!q.empty()){
        BiTree p = q.front();
        q.pop();

        if (p->lchild){
            if (!flag)
                return false;
            q.push(p->lchild);
        }
        else{
            flag = false;
        }

        if (p->rchild){
            if (!flag)
                return false;
            q.push(p->rchild);
        }
        else{
            flag = false;
        }
    }
    return true;
}