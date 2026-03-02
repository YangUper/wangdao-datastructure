/*
 *P20-1
 * 题目：从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。空出的位置由最后一个元素填补，若顺序表为空，则显示出错误信息并退出运行。
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
        for (int i = 0; i < 10; i++)
            list.dataList[i] = i;
        return true;
    }catch (const bad_alloc& e) {
        cout << "内存分配失败：" << e.what() << endl;
        return false;
    }
}

bool findMin(SqList& list, int& e){
    if (list.length == 0){
        cout << "ERROR\t" << "顺序表为空" << endl;
        return false;
    }

    int minNum = INT32_MAX;
    int index = -1;

    for (int i = 0; i < list.length; i++){
        if (list.dataList[i] < minNum){
            index = i;
            minNum = list.dataList[i];
        }
    }
    list.dataList[index] = list.dataList[list.length - 1];
    list.length--;
    e = minNum;
    return true;
}

int main(){
    SqList list;
    if (!initList(list)){
        return -1;
    }
    int e;
    if (findMin(list, e)){
        cout << "最小值是：" << e << endl;
    }

    delete[] list.dataList;
    return 0;
}