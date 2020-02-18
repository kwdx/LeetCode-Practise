//
//  _701_二叉搜索树中的插入操作.cpp
//  LeetCode-C++
//
//  Created by warden on 2020/1/5.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/

#include <stdio.h>
#include <vector>
#include "TreeNode.hpp"

using namespace std;

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        
        TreeNode *parent = root;
        TreeNode *node = new TreeNode(val);
        while (parent) {
            if (parent->val > val) {
                if (parent->left) {
                    parent = parent->left;
                } else {
                    parent->left = node;
                    return root;
                }
            } else {
                if (parent->right) {
                    parent = parent->right;
                } else {
                    parent->right = node;
                    return root;
                }
            }
        }
        return root;
    }
};

/**
给定二叉搜索树:

        4
       / \
      2   7
     / \
    1   3

和 插入的值: 5
你可以返回这个二叉搜索树:

         4
       /   \
      2     7
     / \   /
    1   3 5
或者这个树也是有效的:

         5
       /   \
      2     7
     / \
    1   3
         \
          4
*/
/**
int main(int argc, const char * argv[]) {
    vector<int> nodes = {4, 2, 7, 1, 3};
    TreeNode* root = generateTreeByLevel(nodes);
    Solution* solution = new Solution();
    root = solution->insertIntoBST(root, 5);
    printTreeByLevel(root);
    return 0;
}
 */
