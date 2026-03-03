/*
 * p20-5
 * 题目：从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
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

void removeDuplication(SqList& list){
    if (list.length <= 1)
        return;

    int k = 0;

    for (int i = 1; i < list.length; i++){
        if (list.dataList[i] != list.dataList[k]){
            k++;
            list.dataList[k] = list.dataList[i];
        }
    }

    list.length = k + 1;
}

int main(){
    SqList list;
    if (!initList(list)){
        return -1;
    }

    cout << "未删除之前：" << endl;
    printList(list);

    removeDuplication(list);

    cout << "删除之后：" << endl;
    printList(list);

    delete[] list.dataList;
    return 0;
}