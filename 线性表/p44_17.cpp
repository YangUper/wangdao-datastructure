/*
 *17.【2009统考真题】已知一个带有表头结点的单链表，结点结构为
    +------+------+
    | data | link |
    +------+------+
假设该链表只给出了头指针 list。在不改变链表的前提下，请设计一个尽可能高效的
算法，查找链表中倒数第 k 个位置上的结点（k 为正整数）。若查找成功，算法输出该
结点的 data 域的值，并返回 1；否则，只返回 0。要求：
1）描述算法的基本设计思想。
2）描述算法的详细实现步骤。
3）根据设计思想和实现步骤，采用程序设计语言描述算法（使用 C、C++ 或 Java 语言
   实现），关键之处请给出
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

int searchKthFromEnd(const LinkList l, const int k){
    if (!l || !l->next)
        return 0;

    LNode* left = l->next;
    LNode* right = l->next;

    for (int i = 0; i < k; i++){
        if (!right)
            return 0;
        right = right->next;
    }

    while (right){
        right = right->next;
        left = left->next;
    }

    cout << "倒数第" << k << "个数是：" << left->data;
    return 1;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    LinkList l = CreateList(nums);
    int k;
    cout << "请输入k：";
    cin >> k;

    cout << "链表中的数据有：";
    PrintList(l);
    if (searchKthFromEnd(l, k) == 0)
        cout << "链表长度不够。" << endl;

    return 0;
}