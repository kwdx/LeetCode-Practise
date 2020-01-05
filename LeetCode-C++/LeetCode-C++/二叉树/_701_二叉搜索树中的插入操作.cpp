//
//  _701_二叉搜索树中的插入操作.cpp
//  LeetCode-C++
//
//  Created by warden on 2020/1/5.
//  Copyright © 2020 warden. All rights reserved.
//

#include "_701_二叉搜索树中的插入操作.hpp"

TreeNode* _701_二叉搜索树中的插入操作::insertIntoBST(TreeNode* root, int val) {
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
