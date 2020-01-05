//
//  _700_二叉搜索树中的搜索.cpp
//  LeetCode-C++
//
//  Created by warden on 2020/1/5.
//  Copyright © 2020 warden. All rights reserved.
//

#include "_700_二叉搜索树中的搜索.hpp"

TreeNode* _700_二叉搜索树中的搜索::searchBST(TreeNode* root, int val) {
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
