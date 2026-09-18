/*
 * 编程以求孩子兄弟表示法存储的森林的叶节点数。
 * */

#include "iostream"
#include "queue"
using namespace std;

typedef struct CSNode{
    int data;
    CSNode* firstChild, *nextSibling;
}CSNode, *CSTree;

void numOfLeafByCursion(CSTree csTree, int &num){
    if (!csTree)
        return;

    if (!csTree->firstChild)
        num++;
    numOfLeafByCursion(csTree->firstChild, num);
    numOfLeafByCursion(csTree->nextSibling, num);
}

int numOfLeaf(CSTree csTree){
    if (!csTree)
        return 0;

    queue<CSNode*> q;
    q.push(csTree);
    int num = 0;
    while (!q.empty()){
        CSNode* cur = q.front();
        q.pop();
        if (!cur->firstChild){
            num++;
        } else{
            q.push(cur->firstChild);
        }

        if (cur->nextSibling)
            q.push(cur->nextSibling);
    }

    return num;
}