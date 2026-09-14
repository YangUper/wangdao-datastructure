/*
 * 题目：08. 设 A 和 B 是两个单链表（带头结点），其中元素递增有序。
 * 设计一个算法从 A 和 B 中的公共元素产生单链表 C，要求不破坏 A、B 的结点。
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

LinkList findSharedEle(LinkList& l1, LinkList& l2){
    LinkList list = new LNode();
    LNode* cur = list;

    LNode* p1 = l1->next;
    LNode* p2 = l2->next;

    while (p1 && p2){
        if (p1->data < p2->data)
            p1 = p1->next;
        else if (p1->data > p2->data)
            p2 = p2->next;
        else{
            LNode* newNode = new LNode(p1->data);
            cur->next = newNode;
            cur = newNode;
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    return list;
}

int main(){
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {2, 3, 4, 5};

    LinkList l1 = CreateList(nums1);
    LinkList l2 = CreateList(nums2);

    cout << "链表1为：";
    PrintList(l1);
    cout << "链表2为：";
    PrintList(l2);

    LinkList list = findSharedEle(l1, l2);
    cout << "公共元素链表：";
    PrintList(list);

    return 0;
}