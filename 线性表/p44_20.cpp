/*
 * 20.【2019统考真题】设线性表 L = (a1, a2, a3, ..., an-2, an-1, an) 采用带头结点的单链表保存，
 * 链表中的结点定义如下：
 *     typedef struct node
 *     {   int data;
 *         struct node* next;
 *     } NODE;
 *
 * 请设计一个空间复杂度为 O(1) 且时间上尽可能高效的算法，重新排列 L 中的各结点，
 * 得到线性表 L' = (a1, an, a2, an-1, a3, an-2, ...)。要求：
 * 1）给出算法的基本设计思想。
 * 2）根据设计思想，采用 C 或 C++ 语言描述算法，关键之处给出注释。
 * 3）说明你所设计的算法的时间复杂度。
 * */

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

void changeList(LinkList& l){
    if (!l || !l->next)
        return;

    LNode* slow = l->next;
    LNode* fast = l->next;

    while (fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next;
        fast = fast->next;
    }

    LNode* l2 = slow->next;
    slow->next = nullptr;

    // 翻转l2(无头节点)
    LNode* p2 = l2;
    LNode* pre = nullptr;
    while (p2){
        LNode* next = p2->next;
        p2->next = pre;
        pre = p2;
        p2 = next;
    }

    l2 = pre;
    p2 = l2;
    LNode* p1 = l->next;
    while (p1 && p2){
        LNode* p1Next = p1->next;
        LNode* p2Next = p2->next;

        p1->next = p2;
        if (!p1Next)
            break;
        p2->next = p1Next;

        p1 = p1Next;
        p2 = p2Next;
    }
}

int main(){
    vector<int> nums = {1, 2, 3, 4};

    LinkList l = CreateList(nums);

    cout << "初始链表：";
    PrintList(l);

    changeList(l);

    cout << "重新排列之后的链表：";
    PrintList(l);

    return 0;
}