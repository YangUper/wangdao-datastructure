/*
 * 题目：06. 设 C = {a1, b1, a2, b2, ..., an, bn} 为线性表，采用带头结点的单链表存放，设计一个就地算法，
 * 将其拆分为两个线性表，使得 A = {a1, a2, ..., an}，B = {bn, ..., b2, b1}。
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

void divideLink(LinkList& l){
    if (!l || !l->next)
        return;

    cout << "原链表：";
    PrintList(l);

    LinkList l1 = new LNode();
    LNode* head1 = l1;
    LinkList l2 = new LNode();
    LNode* head2 = l2;

    LNode* cur = l->next;

    int cnt = 0;
    while (cur){
        LNode* next = cur->next;
        if (cnt++ % 2 == 0){
            head1->next = cur;
            head1 = head1->next;
        } else{
            cur->next = head2->next;
            head2->next = cur;
        }
        cur = next;
    }
    head1->next = nullptr;

    cout << "拆分之后l1：";
    PrintList(l1);
    cout << "拆分之后l2：";
    PrintList(l2);
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

    LinkList l = CreateList(nums);
    divideLink(l);

    return 0;
}