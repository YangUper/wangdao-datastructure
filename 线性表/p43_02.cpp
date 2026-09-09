/*
 * 题目描述：
 * 试编写在带头结点的单链表 L 中删除一个最小值结点的高效算法（假设该结点唯一）。
 */

#include "iostream"
#include "vector"
using namespace std;

typedef struct LNode{
    int data;
    LNode* next;
    LNode(int val = 0): data(val), next(nullptr){}
}*LinkList;

LinkList CreateList(const vector<int>& nums) {
    LinkList L = new LNode(); // 创建头结点
    LNode* rear = L;
    for (int val : nums) {
        LNode* node = new LNode(val);
        rear->next = node;
        rear = node;
    }
    return L;
}

void PrintList(LinkList L){
    LNode* p = L->next;
    while (p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void DeleteMin(LinkList& l){
    if (l == nullptr || l->next == nullptr) return; // 边界保护：空链表直接返回

    LNode* p = l->next;
    LNode* preP = l;
    LNode* minP = p;
    LNode* preMinP = l;

    while (p){
        if (p->data < minP->data){
            preMinP = preP;
            minP = p;
        }

        p = p->next;
        preP = preP->next;
    }
    preMinP->next = minP->next;
    delete minP;
}

int main(){
    vector<int> initData = {5, 2, 5, 5, 8, 3, 5, 10, 5};
    LinkList l = CreateList(initData);

    cout << "删除之前： ";
    PrintList(l);

    DeleteMin(l);

    cout << "删除之后： ";
    PrintList(l);

    return 0;
}