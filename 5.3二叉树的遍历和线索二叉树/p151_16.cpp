/*
 * 【2017 统考真题】
题目描述：
    请设计一个算法，将给定的表达式树（二叉树）转换为等价的中缀表达式
    （通过括号反映操作符的计算次序）并输出。

    二叉树结点定义如下：
    typedef struct node{
        char data[10];           // 存储操作数或操作符
        struct node *left, *right;
    } BTree;

要求：
1) 给出算法的基本设计思想。
2) 根据设计思想，采用 C 或 C++ 语言描述算法，关键之处给出注释。
 * */

#include "iostream"
using namespace std;

typedef struct node{
    char data[10];           // 存储操作数或操作符
    struct node *left, *right;
}BTree;

void toInfixHelper(BTree* bTree, string& s, int depth){
    if (!bTree)
        return;

    bool isNoLeaf = bTree->left || bTree->right;
    if (isNoLeaf && depth > 1){
        s += "(";
    }

    toInfixHelper(bTree->left, s, depth + 1);

    s += bTree->data;

    toInfixHelper(bTree->right, s, depth + 1);

    if (isNoLeaf && depth > 1){
        s += ")";
    }
}

void toInfix(BTree* bTree){
    string s = "";
    toInfixHelper(bTree, s, 1);
    cout << s;
}