//
//  _530_二叉搜索树的最小绝对差.cpp
//  LeetCode-C++
//
//  Created by warden on 2020/1/5.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/

#include <stdio.h>
#include <stack>
#include <limits.h>
#include "TreeNode.hpp"

using namespace std;

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int preVal = -1;
        int val = INT_MAX;
        stack<TreeNode*> st;
        TreeNode* pre = root;
        while (pre || !st.empty()) {
            while (pre) {
                st.push(pre);
                pre = pre->left;
            }
            if (!st.empty()) {
                pre = st.top();
                st.pop();
                if (preVal >= 0) {
                    val = min(val, abs(pre->val - preVal));
                }
                preVal = pre->val;
                pre = pre->right;
            }
        }
        return val;
    }
};

/**
输入:

   1
    \
     3
    /
   2

输出:
1

解释:
最小绝对差为1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
*/
/**
int main(int argc, const char * argv[]) {
//    vector<int> nodes = {5,INT_MAX,10,13};
//    vector<int> nodes = {236,104,701,INT_MAX,227,INT_MAX,911};
//    vector<int> nodes = {0,INT_MAX,2236,1277,2776,519};
    vector<int> nodes = {1,INT_MAX,3,2};
    TreeNode* root = generateTreeByLevel(nodes);
    Solution* solution = new Solution();
    printf("%d\n", solution->getMinimumDifference(root));
    return 0;
}
 */
