//
//  _110_平衡二叉树.cpp
//  LeetCode-C++
//
//  Created by warden on 2020/2/17.
//  Copyright © 2020 warden. All rights reserved.
//

#include "_110_平衡二叉树.hpp"
#include <stdlib.h>

bool _110_平衡二叉树::isBalanced(TreeNode* root) {
    return depth(root) != -1;
}

int _110_平衡二叉树::depth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    if (!root->left && !root->right) {
        return 1;
    }
    int leftHeight = depth(root->left);
    if (leftHeight < 0) {
        return -1;
    }
    int rightHeight = depth(root->right);
    if (rightHeight < 0) {
        return -1;
    }
    if (abs(rightHeight - leftHeight) > 1) {
        return -1;
    }
    return (rightHeight > leftHeight ? rightHeight : leftHeight) + 1;
}

