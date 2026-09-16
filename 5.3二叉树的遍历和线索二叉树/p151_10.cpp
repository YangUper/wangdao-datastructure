/*
 * 10. 设一棵二叉树的结点结构为 (LLINK, INFO, RLINK)，ROOT 为指向该二叉树根结点的指针，p 和 q 分别为指向该二叉树中任意两个结点的指针，
 * 试编写算法 ANCESTOR(ROOT, p, q, r)，找到 p 和 q 的最近公共祖先结点 r。
 * */

#include "iostream"
using namespace std;

typedef struct BiNode{
    int data;
    BiNode* lchild;
    BiNode* rchild;
}BiNode, *BiTree;

BiNode* ANCESTOR_HELPER(BiTree tree, BiNode* p, BiNode* q){
    if (!tree || tree == p || tree == q)
        return tree;

    BiNode *left = ANCESTOR_HELPER(tree->lchild, p, q);
    BiNode *right = ANCESTOR_HELPER(tree->rchild, p, q);

    if (left && right)
        return tree;

    return left != nullptr ? left : right;
}

void ANCESTOR(BiTree tree, BiNode* p, BiNode* q, BiNode*& r){
    r = ANCESTOR_HELPER(tree, p, q);
}