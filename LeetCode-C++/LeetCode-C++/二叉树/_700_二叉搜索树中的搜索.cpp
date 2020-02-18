//
//  _700_二叉搜索树中的搜索.cpp
//  LeetCode-C++
//
//  Created by warden on 2020/1/5.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/search-in-a-binary-search-tree/

#include <stdio.h>
#include <vector>
#include "TreeNode.hpp"

using namespace std;

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return root;
        TreeNode *cur = root;
        while (cur) {
            if (cur->val == val) {
                break;
            } else if (cur->val < val) {
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        return cur;
    }
};

/**
给定二叉搜索树:

        4
       / \
      2   7
     / \
    1   3

和值: 2
你应该返回如下子树:

      2
     / \
    1   3
*/
/**
int main(int argc, const char * argv[]) {
    vector<int> nodes = {4,2,7,1,3};
    TreeNode* root = generateTreeByLevel(nodes);
    Solution* solution = new Solution();
    root = solution->searchBST(root, 5);
    if (root) {
        printTreeByLevel(root);
    }

    return 0;
}
*/
