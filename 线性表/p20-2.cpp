/*
 * p20-2
 * 题目：设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O（1）.
 */


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

void reverse(SqList& list){
    int t;
    for (int i = 0; i < list.length / 2; i++){
        t = list.dataList[i];
        list.dataList[i] = list.dataList[list.length - 1 - i];
        list.dataList[list.length - 1 - i] = t;
    }
}

void printList(const SqList& list){
    for (int i = 0; i < list.length; i++){
        cout << list.dataList[i] << "\t";
    }
    cout << "\n";
}

int main(){
    SqList list;
    if (!initList(list)){
        return -1;
    }

    cout << "逆置之前：" << endl;
    printList(list);

    reverse(list);

    cout << "逆置之后：" << endl;
    printList(list);

    delete[] list.dataList;
    return 0;
}