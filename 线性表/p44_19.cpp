/*
 * 19.【2015统考真题】用单链表保存 m 个整数，结点的结构为 [data][link]，且 |data| <= n（n 为正整数）。
 * 现要求设计一个时间上尽可能高效的算法，对于链表中 data 的绝对值相等的结点，
 * 仅保留第一次出现的结点而删除其余绝对值相等的结点。
 * */

#include "iostream"
#include "cmath"
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

void deleteSameAbs(LinkList& l, const int n){
    if (!l || !l->next)
        return;

    bool* flag = new bool[n+1]();
    LNode* p = l->next;
    LNode* pre = l;

    while (p){
        if (flag[abs(p->data)]){
            pre->next = p->next;
            delete p;
            p = pre->next;
        }else{
            flag[abs(p->data)] = true;
            p = p->next;
            pre = pre->next;
        }
    }

    delete[] flag;
}

int main(){
    vector<int> nums = {1, -1, 0, 2, -2, 3, 5, -5};
    LinkList l = CreateList(nums);
    const int n = 10;

    cout << "链表原数据：";
    PrintList(l);

    deleteSameAbs(l, n);

    cout << "删除绝对相同的数据之后的链表：";
    PrintList(l);

    return 0;
}