//
//  _938_二叉搜索树的范围和.cpp
//  LeetCode-C++
//
//  Created by warden on 2020/2/16.
//  Copyright © 2020 warden. All rights reserved.
//

#include "_938_二叉搜索树的范围和.hpp"

int _938_二叉搜索树的范围和::rangeSumBST(TreeNode* root, int L, int R) {
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
