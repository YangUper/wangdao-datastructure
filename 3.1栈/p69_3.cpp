/*
* 03. 栈的初态和终态均为空，以 I 和 O 分别表示入栈和出栈，则出入栈的操作序列可表示
 * 为由 I 和 O 组成的序列，可以操作的序列称为合法序列，否则称为非法序列。
 *
 * 1) 下面所示的序列中哪些是合法的？
 *    A. IOIIOIOO    B. IOOIOIIO    C. IIIOIOIO    D. IIIOOIOO
 *    答案：A、D
 *
 * 2) 通过对 1) 的分析，写出一个算法，判定所给的操作序列是否合法。若合法，返回
 *    true，否则返回 false（假定被判定的操作序列已存入一维数组中）。
 * */

#include "iostream"
using namespace std;

bool isValid(const string s){
    int cnt = 0;
    for (char ch: s){
        if (ch == 'i')
            cnt++;
        else
            cnt--;
        if (cnt < 0)
            return false;
    }

    if (cnt > 0)
        return false;
    else
        return true;
}

int main(){
    string s = "iooiiioo";

    if (isValid(s))
        cout << "合法";
    else
        cout << "不合法";

    return 0;
}