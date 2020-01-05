//
//  _94_二叉树的中序遍历.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/9.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_94_二叉树的中序遍历.hpp"
#include <stack>

vector<int> _94_二叉树的中序遍历::inorderTraversal(TreeNode* root) {
    vector<int> results;
    stack<TreeNode*> st;
    TreeNode* p = root;
    while (p || !st.empty()) {
        while (p) {
            st.push(p);
            p = p->left;
        }
        if (!st.empty()) {
            results.push_back(st.top()->val);
            p = st.top()->right;
            st.pop();
        }
    }
    return results;
}
