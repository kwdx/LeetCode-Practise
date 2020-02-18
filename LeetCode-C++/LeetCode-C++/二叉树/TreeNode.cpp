//
//  TreeNode.cpp
//  LeetCode-C++
//
//  Created by warden on 2020/2/18.
//  Copyright © 2020 warden. All rights reserved.
//

#include "TreeNode.hpp"
#include <queue>

using namespace std;

/// 创建二叉搜索树
TreeNode* generateBinaryTree(vector<int> trees) {
    if (trees.size() == 0) return nullptr;
    TreeNode *root = new TreeNode(trees[0]);
    for (int i = 1; i < trees.size(); i++) {
        int value = trees[i];
        TreeNode *parent = root;
        TreeNode *node = root;
        do {
            parent = node;
            if (value < node->val) {
                node = node->left;
            } else {
                node = node->right;
            }
        } while (node != nullptr);
        
        if (value < parent->val) {
            parent->left = new TreeNode(value);
        } else {
            parent->right = new TreeNode(value);
        }
    }
    return root;
}

/// 按照层序遍历生成二叉树
TreeNode* generateTreeByLevel(vector<int> trees) {
    if (trees.size() == 0) {
        return NULL;
    }
    TreeNode *root = new TreeNode(trees[0]);
    queue<TreeNode*> q;
    q.push(root);
    bool isLeft = true;
    for (int i = 1; i < trees.size(); i++) {
        TreeNode *parent = q.front();
        if (trees[i] != INT_MAX) {
            TreeNode *child = new TreeNode(trees[i]);
            if (isLeft) {
                parent->left = child;
            } else {
                parent->right = child;
            }
            q.push(child);
        }
        if (!isLeft) {
            q.pop();
        }
        
        isLeft = !isLeft;
    }
    return root;
}

/// 层序遍历打印二叉树
void printTreeByLevel(TreeNode* root) {
    if (!root) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        printf("%d ", node->val);
        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
    }
    printf("\n");
}

/// 打印向量
void printVector(std::vector<int> *nodes) {
    for (auto n:(*nodes)) {
        printf("%d ", n);
    }
    printf("\n");
}
