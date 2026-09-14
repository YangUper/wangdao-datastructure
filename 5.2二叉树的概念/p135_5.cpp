/*
 * 题目：
 * 05. 已知一棵二叉树按顺序存储结构进行存储，设计一个算法，
 * 求编号分别为 i 和 j 的两个结点的最近的公共祖先结点的值。
 */

#include "iostream"

using namespace std;

int findSharedAncient(int a, int b){
    while (a != b){
        if (a > b)
            a /= 2;
        else
            b /= 2;
    }
    return a;
}

int main(){
    int a, b;
    cout << "请输入a：";
    cin >> a;
    cout << "请输入b：";
    cin >> b;

    int index = findSharedAncient(a, b);
    cout << "a和b最近的公共祖先的索引是：" << index;
    return 0;
}