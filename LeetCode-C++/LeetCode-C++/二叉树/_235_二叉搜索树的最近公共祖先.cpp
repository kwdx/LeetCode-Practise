//
//  _235_二叉搜索树的最近公共祖先.cpp
//  LeetCode-C++
//
//  Created by warden on 2020/2/16.
//  Copyright © 2020 warden. All rights reserved.
//

#include "_235_二叉搜索树的最近公共祖先.hpp"

TreeNode* _235_二叉搜索树的最近公共祖先::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return NULL;
        }
        int left, right = 0;
        if (p->val < q->val) {
            left = p->val;
            right = q->val;
        } else {
            left = q->val;
            right = p->val;
        }
        TreeNode* node = root;
        while (node) {
            if (node->val >= left && node->val <= right) {
                return node;
            } else if (node->val < left) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
        return node;
}
