/*
 * 题目：03. 试编写算法将带头结点的单链表就地逆置，所谓“就地”是指辅助空间复杂度为 O(1)。
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

void reverseList(LinkList& l){
    if (!l || !l->next){
        return;
    }

    LNode* cur = l->next;
    LNode* pre = nullptr;
    LNode* next = nullptr;

    while (cur){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    l->next = pre;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    LinkList l = CreateList(nums);

    cout << "链表逆置之前：";
    PrintList(l);

    reverseList(l);

    cout << "链表逆置之后：";
    PrintList(l);

    return 0;
}