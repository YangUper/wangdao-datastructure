/*
 * 09. 在二叉树中查找值为 x 的结点，试编写算法（用 C 语言）打印值为 x 的结点的所有祖先，假设值为 x 的结点不多于一个。
 * */

#include "iostream"
using namespace std;

typedef struct BiNode{
    int data;
    BiNode* lchild;
    BiNode* rchild;
}BiNode, *BiTree;

bool printXAncient(BiTree tree, int x){
    if (!tree)
        return false;

    if (tree->data == x)
        return true;

    if (printXAncient(tree->lchild, x) || printXAncient(tree->rchild, x)){
        cout << tree->data << " ";
        return true;
    }

    return false;
}