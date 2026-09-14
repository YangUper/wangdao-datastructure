/*
 * 题目：
 * 01. 假设一个算术表达式中包含圆括号、方括号和花括号 3 种类型的括号，
 * 编写一个算法来判别表达式中的括号是否配对，以字符 '\0' 作为算术表达式的结束符。
 */

#include "iostream"
#include "stack"

using namespace std;

bool isValid(char *s){
    stack<char> stack1;
    for (int i = 0; s[i] != '\0'; i++){
        char ch = s[i];
        if (ch == '{' || ch == '(' || ch == '['){
            stack1.push(ch);
        } else{
            if (stack1.empty())
                return false;
            char top = stack1.top();
            if ((top == '(' && ch == ')')
            || (top == '[' && ch == ']')
            || (top == '{' && ch == '}')){
                stack1.pop();
            } else{
                return false;
            }
        }
    }

    return stack1.empty();
}

int main(){
    char s[] = "{}([])()";
    bool flag = isValid(s);
    if (flag)
        cout << "合法";
    else
        cout << "非法";
    return 0;
}