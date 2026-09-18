/*
 * 以孩子兄弟链表为存储结构，请设计递归算法求树的深度。
 * */

#include "iostream"
using namespace std;

typedef struct CSNode{
    int data;
    CSNode* firstChild, *nextSibling;
}CSNode, *CSTree;

int height(CSTree csTree){
    if (!csTree)
        return 0;

    return max(height(csTree->firstChild) + 1, height(csTree->nextSibling));
}