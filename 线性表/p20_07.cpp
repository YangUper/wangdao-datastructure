/*
 * p20-7
 * 题目：已知在一维数组A[m+n]中依次存放两个线性表。编写一个函数，将数组中两个顺序表的位置互换，即变成A[n+m]。
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
        for (int i = 0; i < list.length; i++){
            if (i % 2 == 0){
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

void reverseTwoLists(SqList& list, int m, int n){
    int p1 = 0, p2 = m - 1;
    int t;
    while (p1 < p2){
        t = list.dataList[p1];
        list.dataList[p1] = list.dataList[p2];
        list.dataList[p2] = t;
        p1++;
        p2--;
    }

    p1 = m;
    p2 = m + n - 1;
    while (p1 < p2){
        t = list.dataList[p1];
        list.dataList[p1] = list.dataList[p2];
        list.dataList[p2] = t;
        p1++;
        p2--;
    }

    p1 = 0;
    p2 = m + n - 1;
    while (p1 < p2){
        t = list.dataList[p1];
        list.dataList[p1] = list.dataList[p2];
        list.dataList[p2] = t;
        p1++;
        p2--;
    }
}

int main(){
    SqList list;
    initList(list);

    cout << "位置互换前：" << endl;
    printList(list);

    reverseTowLists(list, 4, 6);

    cout << "位置互换之后（m=4，n=6）：" << endl;
    printList(list);

    delete[] list.dataList;
    return 0;
}