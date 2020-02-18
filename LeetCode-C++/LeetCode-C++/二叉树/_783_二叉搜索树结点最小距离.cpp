//
//  _783_二叉搜索树结点最小距离.cpp
//  LeetCode-C++
//
//  Created by warden on 2020/1/5.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/

#include <stdio.h>
#include <stack>
#include <limits.h>
#include "TreeNode.hpp"

using namespace std;

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
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
输入: root = [4,2,6,1,3,null,null]
输出: 1
解释:
注意，root是树结点对象(TreeNode object)，而不是数组。

给定的树 [4,2,6,1,3,null,null] 可表示为下图:

          4
        /   \
      2      6
     / \
    1   3

最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。
*/
/**
int main(int argc, const char * argv[]) {
    vector<int> nodes = {4, 2, 6, 1, 3};
    TreeNode* root = generateTreeByLevel(nodes);
    Solution* solution = new Solution();
    printf("%d\n", solution->minDiffInBST(root));
    return 0;
}
 */
