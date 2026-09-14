/*
 * 题目：10. 两个整数序列 A = a1, a2, a3, ..., am 和 B = b1, b2, b3, ..., bn 已经存入两个单链表中，
 * 设计一个算法，判断序列 B 是否是序列 A 的连续子序列。
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

bool isSubSequence(const LinkList l1, const LinkList l2){
    if (!l2 || !l2->next)
        return true;
    if (!l1 || !l1->next)
        return false;

    LNode* pivot = l1->next;

    while (pivot){
        LNode* p1 = pivot;
        LNode* p2 = l2->next;

        while (p1 && p2 && p1->data == p2->data){
            p1 = p1->next;
            p2 = p2->next;
        }

        if (!p2)
            return true;

        pivot = pivot->next;
    }

    return false;
}

int main(){
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {1, 2, 3, 6};

    LinkList l1 = CreateList(nums1);
    LinkList l2 = CreateList(nums2);

    cout << "链表A：";
    PrintList(l1);
    cout << "链表B：";
    PrintList(l2);

    bool flag = isSubSequence(l1, l2);
    if (flag)
        cout << "序列 B 是序列 A 的连续子序列";
    else
        cout << "序列 B 不是序列 A 的连续子序列";

    return 0;
}