/**
 * 题目：假设二叉树采用二叉链表存储结构存储，设计一个算法，
 *      求先序遍历序列中第 k（1 <= k <= 二叉树中结点数）个结点的值。
 */

#include "iostream"
using namespace std;

typedef struct BiNode{
    int data;
    BiNode* lchild;
    BiNode* rchild;
}BiNode, *BiTree;

void kthData(BiTree tree, int k, int &cnt, int &num){//cnt 初始为1
    if (!tree)
        return;

    if (k == cnt){
        num = tree->data;
        return;
    } else
        cnt++;
    kthData(tree->lchild, k, cnt, num);
    kthData(tree->rchild, k, cnt, num);
}