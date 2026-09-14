/*
* 【2013 统考真题】
 * 题目描述：
 * 已知一个整数序列 A = (a_0, a_1, ..., a_{n-1})，其中 0 <= a_i < n (0 <= i < n)。
 * 若存在 a_{p_1} = a_{p_2} = ... = a_{p_m} = x 且 m > n/2 (0 <= p_k < n, 1 <= k <= m)，
 * 则称 x 为 A 的主元素。
 * 例如 A = (0, 5, 5, 3, 5, 7, 5, 5)，则 5 为主元素；
 * 又如 A = (0, 5, 5, 3, 5, 1, 5, 7)，则 A 中没有主元素。
 * 假设 A 中的 n 个元素保存在一个一维数组中，请设计一个尽可能高效的算法，
 * 找出 A 的主元素。若存在主元素，则输出该元素；否则输出 -1。
 *
 * 要求：
 * 1) 给出算法的基本设计思想。
 * 2) 根据设计思想，采用 C 或 C++ 或 Java 语言描述算法，关键之处给出注释。
 * 3) 说明你所设计算法的时间复杂度和空间复杂度。
 * */

#include "iostream"
using namespace std;

int main(){
    const int n = 8;
    int A[n] = {0, 5, 5, 3, 5, 7, 5, 5};
    int B[n];
    for (int i = 0; i < n; i++) B[i] = 0;

    for (int i = 0; i < n; i++){
        int a = A[i];
        B[a] ++;
    }
    int maxCount = B[0];
    int index = 0;
    for (int i = 1; i < n; i++){
        if (maxCount < B[i]){
            index = i;
            maxCount = B[i];
        }
    }
    if (maxCount > n / 2){
        cout << index;
    } else{
        cout << -1;
    }

    return 0;
}