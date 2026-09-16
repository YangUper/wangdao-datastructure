/*
 * 08. 已知二叉树以二叉链表存储，编写算法完成：对于树中每个元素值为 x 的结点，删除以它为根的子树，并释放相应的空间。
 * */

#include "iostream"
using namespace std;

typedef struct BiNode{
    int data;
    BiNode* lchild;
    BiNode* rchild;
}BiNode, *BiTree;

void deleteTree(BiTree& tree){
    if (!tree)
        return;

    deleteTree(tree->lchild);
    deleteTree(tree->rchild);
    delete tree;
    tree = nullptr;
}

void deleteX(BiTree& tree, int x){
    if (!tree)
        return;

    if (tree->data == x){
        deleteTree(tree);
        tree = nullptr;
        return;
    }
    deleteX(tree->lchild, x);
    deleteX(tree->rchild, x);
}

