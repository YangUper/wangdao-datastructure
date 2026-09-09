/*
 * 题目：04. 设在一个带表头结点的单链表中，所有结点的元素值无序，试编写一个函数，删除表中所有处于给定的两个值（作为函数参数给出）之间的元素（若存在）。
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

void deleteBtwMN(LinkList& l, int m, int n){
    if (!l || !l->next)
        return;

    LNode* cur = l->next;
    LNode* pre = l;

    while (cur){
        if (cur->data > m && cur->data < n){
            pre->next = cur->next;
            delete cur;
            cur = pre->next;
        } else{
            pre = pre->next;
            cur = cur->next;
        }
    }
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 4, 2, 1, 9};
    LinkList l = CreateList(nums);
    int m, n;
    cout << "请输入较小值：";
    cin >> m;

    cout << "请输入较大值：";
    cin >> n;

    cout << "删除之前：";
    PrintList(l);

    deleteBtwMN(l, m, n);

    cout << "删除之后：";
    PrintList(l);

    return 0;
}