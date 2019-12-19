//
//  _450_删除二叉搜索树中的节点.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/17.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_450_删除二叉搜索树中的节点.hpp"

TreeNode* _450_删除二叉搜索树中的节点::deleteNode(TreeNode* root, int key) {
    TreeNode* curNode = root;
    TreeNode* preNode = root;
    while (curNode && curNode->val != key) {
        preNode = curNode;
        if (curNode->val < key)
            curNode = curNode->right;
        else
            curNode = curNode->left;
    }
    if (!curNode) {
        return root;
    }
    if (!curNode->left && !curNode->right) {
        if (curNode == root) {
            return NULL;
        }
        if (preNode->left == curNode) {
            preNode->left = NULL;
        } else {
            preNode->right = NULL;
        }
    } else if (curNode->left && !curNode->right) {
        if (curNode == root) {
            return curNode->left;
        } else if (preNode->left == curNode) {
            preNode->left = curNode->left;
        } else {
            preNode->right = curNode->left;
        }
    } else if (curNode->right && !curNode->left) {
        if (curNode == root) {
            return curNode->right;
        } else if (preNode->left == curNode) {
            preNode->left = curNode->right;
        } else {
            preNode->right = curNode->right;
        }
    } else {
        TreeNode* dNode = curNode->left;
        while (dNode->right) {
            dNode = dNode->right;
        }
        dNode->right = curNode->right->left;
        curNode->right->left = curNode->left;
        if (curNode == root) {
            return curNode->right;
        } else if (preNode->left == curNode) {
            preNode->left = curNode->right;
        } else {
            preNode->right = curNode->right;
        }
    }
    return root;
}
