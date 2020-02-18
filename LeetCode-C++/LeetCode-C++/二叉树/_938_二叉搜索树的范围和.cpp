//
//  _938_二叉搜索树的范围和.cpp
//  LeetCode-C++
//
//  Created by warden on 2020/2/16.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/range-sum-of-bst/

#include <stdio.h>
#include <vector>
#include "TreeNode.hpp"

using namespace std;

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root) {
            return 0;
        }
        if (root->val < L) {
            return rangeSumBST(root->right, L, R);
        }
        if (root->val > R) {
            return rangeSumBST(root->left, L, R);
        }
        
        return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }
};

/**
 示例 1：

 输入：root = [10,5,15,3,7,null,18], L = 7, R = 15
 输出：32
 示例 2：

 输入：root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
 输出：23
 */
/**
int main(int argc, const char * argv[]) {
    vector<int> nodes = {10,5,15,3,7,13,18,1,INT_MAX,6};
    Solution* solution = new Solution();
    TreeNode* root = generateTreeByLevel(nodes);
    printf("%d\n", solution->rangeSumBST(root, 6, 10));
    return 0;
}
 */
