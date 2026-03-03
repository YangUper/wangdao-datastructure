/*
 * p20-6
 * 题目：将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表
 * */

#include "iostream"

using namespace std;

#define MAX_SIZE 100

typedef struct SqList{
    int length;
    int* dataList;
    int maxSize = MAX_SIZE;
}SqList;

bool initList(SqList& list, int seed){
    try {
        list.dataList = new int [10];
        list.length = 10;
        for (int i = 0; i < list.length; i++){
            if (seed % 2 == 0){
                list.dataList[i] = i - 1;
            } else{
                list.dataList[i] = i;
            }
        }
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

SqList mergeList(SqList& list1, SqList& list2){
    int n = list1.length + list2.length;
    SqList list;
    list.length = n;
    list.dataList = new int [n];
    int p1 = 0, p2 = 0;

    int k = 0;
    while (p1 < list1.length && p2 < list2.length){
        if (list1.dataList[p1] < list2.dataList[p2]){
            list.dataList[k] = list1.dataList[p1];
            p1++;
        } else{
            list.dataList[k] = list2.dataList[p2];
            p2++;
        }
        k++;
    }

    if (p1 == list1.length){
        for (int i = p2; i < list2.length; i++){
            list.dataList[k] = list2.dataList[i];
            k++;
        }
    } else{
        for (int i = p1; i < list1.length; i++){
            list.dataList[k] = list1.dataList[i];
            k++;
        }
    }

    return list;
}

int main(){
    SqList list1;
    initList(list1, 1);
    SqList list2;
    initList(list2, 2);

    cout << "两个待合并的顺序表如下：" << endl;
    printList(list1);
    printList(list2);

    cout << "合并之后的顺序表：" << endl;

    SqList list = mergeList(list1, list2);
    printList(list);

    delete[] list1.dataList;
    delete[] list2.dataList;
    delete[] list.dataList;

    return 0;
}