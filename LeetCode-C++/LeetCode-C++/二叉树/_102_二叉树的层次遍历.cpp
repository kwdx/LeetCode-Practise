//
//  _102_二叉树的层次遍历.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/11.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_102_二叉树的层次遍历.hpp"
#include <queue>

vector<vector<int>> _102_二叉树的层次遍历::levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    queue<TreeNode*> nodes;
    if (root) {
        nodes.push(root);
    }
    size_t size = nodes.size();
    vector<int> curLevel;
    while (!nodes.empty()) {
        if (size == 0) {
            size = nodes.size();
            result.push_back(curLevel);
            curLevel.clear();
        }
        TreeNode* p = nodes.front();
        nodes.pop();
        curLevel.push_back(p->val);
        if (p->left) {
            nodes.push(p->left);
        }
        if (p->right) {
            nodes.push(p->right);
        }
        size--;
    }
    if (curLevel.size() > 0) {
        result.push_back(curLevel);
    }
    return result;
}
