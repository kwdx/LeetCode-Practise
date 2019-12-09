//
//  _144_二叉树的前序遍历.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/7.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_144_二叉树的前序遍历.hpp"
#include <stack>

vector<int> _144_二叉树的前序遍历::preorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root == NULL) {
        return result;
    }
    stack<TreeNode*> nodes;
    TreeNode *p = root;
    while (p || !nodes.empty()) {
        while (p) {
            result.push_back(p->val);
            nodes.push(p);
            p = p->left;
        }
        
        p = nodes.top();
        nodes.pop();
        p = p->right;
    }
    return result;
}
