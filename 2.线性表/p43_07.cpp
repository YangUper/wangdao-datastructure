/*
 * 题目：07. 在一个递增有序的单链表中，存在重复的元素。设计算法删除重复的元素，
 * 例如 (7, 10, 21, 30, 42, 42, 42, 51, 70) 将变为 (7, 10, 21, 30, 42, 51, 70)。
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

void deleteDuplicates(LinkList& l){
    if (!l || !l->next)
        return;

    LNode* left = l->next;
    LNode* right = left->next;
    LNode* pre = l;

    while (left && right){
        if (left->data != right->data){
            pre = left;
            left = right;
            right = right->next;
        }else{
            pre->next = right;
            delete left;
            left = right;
            right = right->next;
        }
    }

}

int main(){
    vector<int> nums = {1, 2, 2, 2, 2, 4, 4, 8, 9, 44, 54};

    LinkList l = CreateList(nums);

    cout << "去重之前：";
    PrintList(l);

    deleteDuplicates(l);

    cout << "去重之后：";
    PrintList(l);

    return 0;
}