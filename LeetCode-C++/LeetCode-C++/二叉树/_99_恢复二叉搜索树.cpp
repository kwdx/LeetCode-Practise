//
//  _99_恢复二叉搜索树.cpp
//  LeetCode-C++
//
//  Created by warden on 2020/2/17.
//  Copyright © 2020 warden. All rights reserved.
//

#include "_99_恢复二叉搜索树.hpp"
#include <algorithm>

void _99_恢复二叉搜索树::recoverTree(TreeNode* root) {
    TreeNode* first = NULL;
    TreeNode* last = NULL;
    TreeNode* prev = NULL;
    
    while (root) {
        TreeNode* tmp = root->left;
        while (tmp && tmp->right && tmp->right != root)
            tmp = tmp->right;
        if (!tmp || tmp->right == root) {
            if (tmp)
                tmp->right = NULL;
            if (prev && root->val < prev->val) {
                last = root;
                first = first == NULL ? prev : first;
            }
            prev = root;
            root = root->right;
        } else {
            tmp->right = root;
            root = root->left;
        }
    }
    if (first && last)
        std::swap(first->val, last->val);
}
