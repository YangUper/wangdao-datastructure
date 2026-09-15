/*
 * 二叉树采用链式结构存储，编写一个把数中所有节点的左、右子树进行交换的函数。
 * */

#include "iostream"
using namespace std;

typedef struct BiNode{
    int data;
    BiNode* lchild;
    BiNode* rchild;
}BiNode, *BiTree;

void exchangeSubTree(BiTree& tree){
    if (!tree)
        return;

    exchangeSubTree(tree->lchild);
    exchangeSubTree(tree->rchild);
    swap(tree->rchild, tree->lchild);
}