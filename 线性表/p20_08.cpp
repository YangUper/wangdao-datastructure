/*
 * p20-8
 * 题目：线性表中的元素递增有序且按顺序存储与计算机内。要求设计一个算法，完成用最少时间在表中查找数值为x的元素，若找到，则将其与后继元素位置相交换，
 * 若找不到，则将其插入表中并使表中元素仍然递增有序。
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
        list.dataList = new int [11];
        list.length = 10;
        for (int i = 0; i < list.length; i++){
            if (i == 3){
                list.dataList[i] = 4;
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

void findX(SqList& list, int x){
    for (int i = 0; i < list.length; i++){
        if (list.dataList[i] == x){
            // 找到了，并且不是最后一个元素
            if (i != list.length - 1){
                int t = list.dataList[i];
                list.dataList[i] = list.dataList[i + 1];
                list.dataList[i + 1] = t;
                break;
            }
        }

        if (list.dataList[i] > x){
            list.length++;
            for (int j = list.length - 1; j > i; j--){
                list.dataList[j] = list.dataList[j - 1];
            }
            list.dataList[i] = x;
            break;
        }

        if (i == list.length - 1 && list.dataList[i] < x){
            list.length++;
            list.dataList[list.length - 1] = x;
        }
    }
}

// 此处使用了二分查找，不理解的同学可以往课本后面看
//void findX(SqList& list, int x) {
//    int low = 0, high = list.length - 1, mid;
//
//    // 1. 折半查找 - 满足“最少时间”要求
//    while (low <= high) {
//        mid = (low + high) / 2;
//        if (list.dataList[mid] == x) break;
//        else if (list.dataList[mid] < x) low = mid + 1;
//        else high = mid - 1;
//    }
//
//    // 2. 判断结果
//    if (list.dataList[mid] == x && mid != list.length - 1) {
//        // 找到了且不是最后一个元素，与后继交换
//        int temp = list.dataList[mid];
//        list.dataList[mid] = list.dataList[mid + 1];
//        list.dataList[mid + 1] = temp;
//    }
//    else if (low > high) {
//        // 没找到，插入到 low 所在的位置
//        // 注意：实际应用中应检查 list.length < list.maxSize
//        for (int i = list.length - 1; i >= low; i--) {
//            list.dataList[i + 1] = list.dataList[i];
//        }
//        list.dataList[low] = x;
//        list.length++;
//    }
//}

int main(){
    SqList list;
    initList(list);

    int x;
    cout << "请输入需要查找的x：";
    cin >> x;

    cout << "原始顺序表：" << endl;
    printList(list);

    findX(list, x);

    cout << "查找结果如下" << endl;
    printList(list);

    delete[] list.dataList;

    return 0;
}