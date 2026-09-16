/*
 * 14. 试设计判断两棵二叉树是否相似的算法。所谓二叉树 T_1 和 T_2 相似，指的是 T_1 和 T_2 都是空的二叉树或都只有一个根结点；
 * 或者 T_1 的左子树和 T_2 的左子树是相似的，且 T_1 的右子树和 T_2 的右子树是相似的。
 * */

#include "iostream"
using namespace std;

typedef struct BiNode{
    int data;
    BiNode* lchild;
    BiNode* rchild;
}BiNode, *BiTree;

bool isSimilar(BiTree t1, BiTree t2){
    if (!t1 && !t2)
        return true;

    if ((t1 && !t2) || (!t1 && t2))
        return false;

    if (!t1->lchild && !t1->rchild && !t2->lchild && !t2->rchild)
        return true;

    bool left = isSimilar(t1->lchild, t2->lchild);
    bool right = isSimilar(t1->rchild, t2->rchild);
    if (left && right)
        return true;
    else
        return false;
}