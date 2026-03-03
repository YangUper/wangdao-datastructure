/*
 * p20-3
 * 题目：对长度为n的顺序表L，编写一个时间复杂度为O（n）、空间复杂度为O（1）的算法，该算法删除顺序表中所有值为x的数据元素。
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

void delX(SqList& list, int x){
    int appear = 0; // 记录从左到右扫描过程中，出现的值为x的数量
    for (int i = 0; i < list.length; i++){
        if (list.dataList[i] == x)
            appear++;
        else
            list.dataList[i - appear] = list.dataList[i];
    }

    list.length -= appear;
}

int main(){
    SqList list;
    if (!initList(list)){
        return -1;
    }

    cout << "未删除之前：" << endl;
    printList(list);

    int x;
    cout << "请输入需要删除的数字：";
    cin >> x;

    delX(list, x);

    cout << "删除之后：" << endl;
    printList(list);

    delete[] list.dataList;
    return 0;
}