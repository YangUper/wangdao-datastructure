/*
 Q是一个队列，S是一个空栈，实现将队列中的元素逆置的算法。
 * */

#include "iostream"
#include "queue"
#include "stack"
using namespace std;

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    stack<int> s;

    while (!q.empty()){
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()){
        q.push(s.top());
        s.pop();
    }

    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}