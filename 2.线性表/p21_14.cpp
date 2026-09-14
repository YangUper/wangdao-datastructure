/*
 * 【2020 统考真题】
 * 题目描述：
 * 定义三元组 (a, b, c) (a, b, c 均为整数) 的距离 D = |a - b| + |b - c| + |c - a|。
 * 给定 3 个非空整数集合 S1、S2 和 S3，按升序分别存储在 3 个数组中。
 * 请设计一个尽可能高效的算法，计算并输出所有可能的三元组 (a, b, c) (a ∈ S1, b ∈ S2, c ∈ S3) 中的最小距离。
 * 例如 S1 = {-1, 0, 9}，S2 = {-25, -10, 10, 11}，S3 = {2, 9, 17, 30, 41}，
 * 则最小距离为 2，相应的三元组为 (9, 10, 9)。
 *
 * 要求：
 * 1) 给出算法的基本设计思想。
 * 2) 根据设计思想，采用 C 语言或 C++ 语言描述算法，关键之处给出注释。
 * 3) 说明你所设计算法的时间复杂度和空间复杂度。
 */

#include "iostream"
#include "vector"
using namespace std;

int main(){
    vector<int> s1{-1, 0, 9};
    vector<int> s2{-25, -10, 10, 11};
    vector<int> s3{2, 9, 17, 30, 41};

    int j = 0, k = 0, l = 0;
    int minD = 10000;
    while (j < s1.size() && k < s2.size() && l < s3.size()){
        int a = s1[j];
        int b = s2[k];
        int c = s3[l];

        int mx = max(a, max(b, c));
        int mn = min(a, min(b, c));

        int D = 2 * (mx - mn);

        if (D < minD){
            minD = D;
        }

        if (a == mn){
            j++;
        }else if (b == mn){
            k++;
        } else{
            l++;
        }
    }

    cout << "最小的距离：" << minD << endl;

    return 0;
}