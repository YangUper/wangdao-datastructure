/*
 * 设计一个算法将二叉树的叶节点按从左到右的顺序连成一个单链表，表头指针为head。二叉树按二叉链表存储，链接时用叶节点的右指针域来存放单链表指针。
 * */

#include "iostream"
using namespace std;

typedef struct BiNode{
    int data;
    BiNode* lchild;
    BiNode* rchild;
}BiNode, *BiTree;

void linkLeaf(BiTree tree, BiNode*& head, BiNode*& tail){
    if (!tree)
        return;

    if (!tree->rchild && !tree->lchild){
        if (!head){
            head = tail = tree;
        } else{
            tail->rchild = tree;
            tail = tree;
        }
        return;
    }

    linkLeaf(tree->lchild, head, tail);
    linkLeaf(tree->rchild, head, tail);
}

BiNode *leaf2LinkList(BiTree tree){
    BiNode* head = nullptr;
    BiNode* tail = nullptr;
    linkLeaf(tree, head, tail);
    return head;
}