/*
 * 【2018 统考真题】
 * 题目描述：
 * 给定一个含 n (n >= 1) 个整数的数组，请设计一个在时间上尽可能高效的算法，
 * 找出数组中未出现的最小正整数。
 * 例如，数组 {-5, 1, 2, 3, 2, 1} 中未出现的最小正整数是 1；
 * 数组 {1, 2, 3} 中未出现的最小正整数是 4。
 *
 * 要求：
 * 1) 给出算法的基本设计思想。
 * 2) 根据设计思想，采用 C 或 C++ 语言描述算法，关键之处给出注释。
 * 3) 说明你所设计算法的时间复杂度和空间复杂度。
 */

#include "iostream"
using namespace std;

int main(){
    const int n = 6;
    int A[n] = {-5, 1, 2, 3, 2, 1};
    bool flag[n] = {false};

    for (int i = 0; i < n; i++){
        int a = A[i];
        if (a > 0 && a <= n){
            flag[a-1] = true;
        }
    }

    for (int i = 0; i < n; i++){
        if (!flag[i]){
            cout << i+1;
            return 0;
        }
    }

    return 0;
}