//
//  _101_对称二叉树.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/16.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_101_对称二叉树.hpp"
#include <queue>

using namespace std;

bool _101_对称二叉树::ismirror(TreeNode* left, TreeNode* right) {
    if (left == NULL && right == NULL) return true;
    if (left == NULL || right == NULL) return false;
    return (left->val == right->val) && ismirror(left->left, right->right) && ismirror(left->right, right->left);
}

bool _101_对称二叉树::isSymmetric1(TreeNode* root) {
    return ismirror(root, root);
}

bool _101_对称二叉树::isSymmetric(TreeNode* root) {
    if (!root) return true;
    queue<TreeNode*> q;
    q.push(root);
    q.push(root);
    while (!q.empty()) {
        TreeNode *t1 = q.front();
        q.pop();
        TreeNode *t2 = q.front();
        q.pop();
        if (t1 == NULL && t2 == NULL) continue;
        if (t1 == NULL || t2 == NULL) return false;
        if (t1->val != t2->val) return false;
        q.push(t1->left);
        q.push(t2->right);
        q.push(t1->right);
        q.push(t2->left);
    }
    return true;
}
