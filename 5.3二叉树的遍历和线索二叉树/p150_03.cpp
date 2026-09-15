/*
 * 假设二叉树采用二叉链表存储结构，设计一个非递归算法求二叉树的高度。
 * */

#include "iostream"
#include "queue"
using namespace std;

typedef struct BiNode{
    int data;
    BiNode* lchild;
    BiNode* rchild;
}BiNode, *BiTree;

int height(BiTree tree){
    if (!tree)
        return 0;

    int h = 0;
    queue<BiNode*> q;
    q.push(tree);
    while (!q.empty()){
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++){
            BiNode* p = q.front();
            q.pop();
            if (p->lchild)
                q.push(p->lchild);
            if (p->rchild)
                q.push(p->rchild);
        }
        h++;
    }
    return h;
}