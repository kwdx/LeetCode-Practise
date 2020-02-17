//
//  _230_二叉搜索树中第K小的元素.cpp
//  LeetCode-C++
//
//  Created by warden on 2020/2/16.
//  Copyright © 2020 warden. All rights reserved.
//

#include "_230_二叉搜索树中第K小的元素.hpp"

int _230_二叉搜索树中第K小的元素::kthSmallest(TreeNode* root, int k) {
    dfs(root, k);
    return res;
}

void _230_二叉搜索树中第K小的元素::dfs(TreeNode* root, int k) {
    if (!root) {
        return;
    }
    dfs(root->left, k);
    if (++n == k) {
        res = root->val;
        return ;
    }
    dfs(root->right, k);
}
