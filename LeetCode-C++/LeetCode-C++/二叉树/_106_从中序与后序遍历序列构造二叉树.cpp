//
//  _106_从中序与后序遍历序列构造二叉树.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/12.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_106_从中序与后序遍历序列构造二叉树.hpp"
#include <stack>

TreeNode* _106_从中序与后序遍历序列构造二叉树::buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (postorder.empty()) {
        return NULL;
    }
    TreeNode *root = new TreeNode(postorder[postorder.size() - 1]);
    stack<TreeNode*> st;
    st.push(root);
    for (int i = (int)postorder.size() - 2, j = (int)inorder.size() - 1; i >= 0; i--) {
        TreeNode *parentNode = NULL, *cur = new TreeNode(postorder[i]);
        while (!st.empty() && st.top()->val == inorder[j]) {
            parentNode = st.top();
            st.pop();
            j--;
        }
        if (parentNode) {
            parentNode->left = cur;
        } else {
            st.top()->right = cur;
        }
        st.push(cur);
    }
    return root;
}
