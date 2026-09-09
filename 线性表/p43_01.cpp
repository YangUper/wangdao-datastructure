/*
 * 题目描述：
 * 在带头结点的单链表 L 中，删除所有值为 x 的结点，并释放其空间，
 * 假设值为 x 的结点不唯一，试编写算法以实现上述操作。
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

void DeleteX(LinkList& L, int x){
    LNode* p = L->next;
    LNode* pre = L;
    while (p){
        if (p->data == x){
            pre->next = p->next;
            delete p;
            p = pre->next;
        } else{
            p = p->next;
            pre = pre->next;
        }
    }
}

int main(){
    vector<int> initData = {5, 2, 5, 5, 8, 3, 5, 10, 5};
    int x = 5;

    LinkList L = CreateList(initData);

    cout << "删除 “x=5” 之前：";
    PrintList(L);

    DeleteX(L, x);

    cout << "删除 “x=5” 之后：";
    PrintList(L);

    return 0;
}