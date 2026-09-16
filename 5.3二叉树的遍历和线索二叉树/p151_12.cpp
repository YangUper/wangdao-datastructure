/*
 * * 题目：设有一棵满二叉树（所有结点值均不同），已知其先序序列为 pre，
 *      设计一个算法求其后序序列 post。
 * */

#include "vector"

using namespace std;

void pre2Post(const vector<int> pre, vector<int>& post, int l, int r){
    if (l > r)
        return;

    if (l == r){
        post.push_back(pre[l]);
        return;
    }

    int half = (r - l) / 2;
    pre2Post(pre, post, l + 1, l + half);
    pre2Post(pre, post, l + half + 1, r);

    post.push_back(pre[l]);
}