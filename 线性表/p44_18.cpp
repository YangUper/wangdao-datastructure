/*
 * 18.【2012统考真题】假定采用带头结点的单链表保存单词，当两个单词有相同的后缀时，
 * 可共享相同的后缀存储空间，例如，loading 和 being 的存储映像如下图所示。
 *
 *              str1 ---> [头] -> [l] -> [o] -> [a] -> [d] --+
 *                                                           |
 *                                                           v
 *              str2 ---> [头] -> [b] -> [e] --------------> [i] -> [n] -> [g] -> ^
 *                                                           (p)
 *
 * 设 str1 和 str2 分别指向两个单词所在单链表的头结点，链表结点结构为 [ data | next ]，
 * 请设计一个时间上尽可能高效的算法，找出由 str1 和 str2 所指向两个链表共同后缀
 * 的起始位置（如图中字符 i 所在结点的位置 p）。要求：
 * 1）给出算法的基本设计思想。
 * 2）根据设计思想，采用 C 或 C++ 或 Java 语言描述算法，关键之处给出注释。
 * 3）说明你所设计算法的时间复杂度。
 * */

#include "iostream"
#include "vector"
using namespace std;

typedef struct LNode{
    char data;
    LNode* next;
    LNode(int val = 0): data(val), next(nullptr){}
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

LNode* findSharedSuffix(LinkList& l1, LinkList& l2, int len1, int len2){
    if (!l1 || !l1->next || !l2 || !l2->next)
        return nullptr;

    LNode* p = l1->next;
    LNode* q = l2->next;

    if (len1 > len2){
        int diff = len1 - len2;
        while (diff--)
            p = p->next;
    } else{
        int diff = len2 - len1;
        while (diff--)
            q = q->next;
    }

    while (q && p){
        if (p == q)
            return p;
        else{
            p = p->next;
            q = q->next;
        }
    }

    return nullptr;
}

int main() {
    // 构造后缀 "ing"
    LNode* i_node = new LNode('i');
    LNode* n_node = new LNode('n');
    LNode* g_node = new LNode('g');
    i_node->next = n_node;
    n_node->next = g_node;

    // 构造 str1 前缀 "load" 并连接后缀
    LinkList str1 = new LNode();
    LNode* l = new LNode('l');
    LNode* o = new LNode('o');
    LNode* a = new LNode('a');
    LNode* d = new LNode('d');
    str1->next = l;
    l->next = o;
    o->next = a;
    a->next = d;
    d->next = i_node;

    // 构造 str2 前缀 "be" 并连接后缀
    LinkList str2 = new LNode();
    LNode* b = new LNode('b');
    LNode* e = new LNode('e');
    str2->next = b;
    b->next = e;
    e->next = i_node;

    // 执行算法查找共同后缀
    LNode* common = findSharedSuffix(str1, str2, 7, 5);

    if (common) {
        std::cout << "共同后缀起始结点的字符为: " << common->data << std::endl;
    } else {
        std::cout << "未找到共同后缀。" << std::endl;
    }

    return 0;
}