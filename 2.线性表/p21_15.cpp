/*
 * 【2025 统考真题】
 * 题目描述：
 * 有两个长度均为 n 的一维整形数组 A 和 res，对数组 A 中的每个元素 A[i]，
 * 计算 A[i] 与 A[j] (0 <= i <= j <= n-1) 乘积的最大值，将其保存到 res[i] 中。
 * 例如，当 A[] = {1, 4, -9, 6} 时，得到 res[] = {6, 24, 81, 36}。
 * 现给定数组 A，设计一个时间和空间上尽可能高效的算法 calMulMax，求 res 中各元素的值。
 * 函数原型为 void calMulMax(int A[], int res[], int n)。
 *
 * 要求如下：
 * 1) 给出算法的基本设计思想。
 * 2) 根据设计思想，采用 C 或 C++ 语言描述算法，关键之处给出注释。
 * 3) 说明你所设计算法的时间复杂度和空间复杂度。
*/

#include "iostream"
using namespace std;

void calMulMax(int A[], int res[], int n){
    int mx = A[n - 1];
    int mn = A[n - 1];

    for (int i = n-1; i >= 0; i--){
        mx = max(mx, A[i]);
        mn = min(mn, A[i]);

        if (A[i] >= 0)
            res[i] = A[i] * mx;
        else
            res[i] = A[i] * mn;
    }

    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
}

int main(){
    int A[4] = {1, 4, -9, 6};
    int res[4] = {6, 24, 81, 36};
    calMulMax(A, res, 4);

    return 0;
}