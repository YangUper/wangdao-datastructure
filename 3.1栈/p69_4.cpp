/*
* 04. 设单链表的表头指针为 L，结点结构由 data 和 next 两个域构成，其中 data 域为字符型。
 * 设计算法判断该链表的全部 n 个字符是否中心对称。例如，xyx、xyyx 都是中心对称的。
 */

#include "iostream"
#include "vector"
#include "stack"
using namespace std;

typedef struct LNode{
    char data;
    LNode* next;
    LNode(char val = 0): data(val), next(nullptr){}
}*LinkList;

LinkList CreateList(const vector<char>& nums) {
    LinkList L = new LNode(); // 创建头结点
    LNode* rear = L;
    for (char val : nums) {
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

bool isSymmetry(const LinkList& l){
    if (!l || !l->next)
        return true;

    stack<char> s;
    LNode* p = l->next;
    while (p){
        s.push(p->data);
        p = p->next;
    }

    p = l->next;
    while (p){
        if (p->data != s.top())
            return false;
        s.pop();
        p = p->next;
    }

    return true;
}

int main(){
    vector<char> seq = {'x', 'y', 'x', 'y'};
    LinkList l = CreateList(seq);

    cout << "链表序列为：";
    PrintList(l);

    if (isSymmetry(l))
        cout << "是对称的";
    else
        cout << "不是对称的";

    return 0;
}