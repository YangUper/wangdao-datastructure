/*
 * 题目：09. 已知两个链表 A 和 B 分别表示两个集合，其元素递增排列。
 * 编制函数，求 A 与 B 的交集，并存放于 A 链表中。
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

void replaceAWithSharedEle(LinkList& l1, const LinkList l2){
    if (!l1 || !l1->next)
        return;

    LNode* pre = l1;
    LNode* p1 = l1->next;
    LNode* p2 = l2->next;

    while (p1 && p2){
        if (p1->data < p2->data){
            pre->next = p1->next;
            delete p1;
            p1 = pre->next;
        } else if (p1->data > p2->data)
            p2 = p2->next;
        else{
            p1 = p1->next;
            p2 = p2->next;
            pre = pre->next;
        }
    }

    while (p1){
        pre->next = p1->next;
        delete p1;
        p1 = pre->next;
    }
}

int main(){
    vector<int> nums1 = {1, 2, 3, 4, 6};
    vector<int> nums2 = {-1, 2, 3, 4, 5};

    LinkList l1 = CreateList(nums1);
    LinkList l2 = CreateList(nums2);

    cout << "链表A:";
    PrintList(l1);
    cout << "链表B：";
    PrintList(l2);

    cout << "寻找交集之后的A链表：";
    replaceAWithSharedEle(l1, l2);
    PrintList(l1);

    return 0;
}