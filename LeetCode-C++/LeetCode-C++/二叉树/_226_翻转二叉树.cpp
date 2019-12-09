//
//  _226_翻转二叉树.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/7.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_226_翻转二叉树.hpp"
#include <stack>

using namespace std;

TreeNode* _226_翻转二叉树::invertTree(TreeNode* root) {
//    if (!root) return root;
//
//    TreeNode *leftNode = root->left;
//    TreeNode *rightNode = root->right;
//    invertTree(leftNode);
//    invertTree(rightNode);
//    root->left = rightNode;
//    root->right = leftNode;
//    return root;
    if (root == NULL) return NULL;
    
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()) {
        TreeNode *node = s.top();
        s.pop();
        TreeNode *tmp = node->left;
        node->left = node->right;
        node->right = tmp;
        if (node->left) s.push(node->left);
        if (node->right) s.push(node->right);
    }
    return root;
}
