/*
 * p20-4
 * 题目：从顺序表中删除其值在给定值s和t之间（包含s和t，要求s < t）的所有元素，若s和t不合理或者顺序表为空，则显示出错信息并退出运行。
 * */

#include "iostream"

using namespace std;

#define MAX_SIZE 100

typedef struct SqList{
    int length;
    int* dataList;
    int maxSize = MAX_SIZE;
}SqList;

bool initList(SqList& list){
    try {
        list.dataList = new int [10];
        list.length = 10;
        for (int i = 0; i < list.length; i++)
            list.dataList[i] = i;
        return true;
    }catch (const bad_alloc& e) {
        cout << "内存分配失败：" << e.what() << endl;
        return false;
    }
}

void printList(const SqList& list){
    for (int i = 0; i < list.length; i++){
        cout << list.dataList[i] << "\t";
    }
    cout << "\n";
}

bool delS2T(SqList& list, int s, int t){
    if (list.length == 0){
        cout << "删除错误，顺序表为空。" << endl;
        return false;
    }

    if (s >= t){
        cout << "要删除的区间[s, t]有误" << endl;
        return false;
    }

    int k = 0; // 记录当前不应该被删除的元素的索引
    for (int i = 0; i < list.length; i++){
        if (!(list.dataList[i] >= s && list.dataList[i] <= t)){
            list.dataList[k] = list.dataList[i];
            k++;
        }
    }

    list.length = k;

    return true;
}

int main(){
    SqList list;
    if (!initList(list)){
        return -1;
    }

    cout << "未删除之前：" << endl;
    printList(list);

    int s;
    cout << "请输入需要删除的数字左边界：";
    cin >> s;

    int t;
    cout << "请输入需要删除的数字右边界：";
    cin >> t;

    if (!delS2T(list, s, t)){
        return -1;
    }

    cout << "删除之后：" << endl;
    printList(list);

    delete[] list.dataList;
    return 0;
}