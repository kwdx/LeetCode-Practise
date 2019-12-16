//
//  _105_从前序与中序遍历序列构造二叉树.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/12.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_105_从前序与中序遍历序列构造二叉树.hpp"
#include <stack>

TreeNode* _105_从前序与中序遍历序列构造二叉树::buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty()) {
        return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[0]);
    stack<TreeNode*> st;
    st.push(root);
    for (int i = 1, j = 0; i < preorder.size(); i++) {
        TreeNode *topNode = NULL, *cur = new TreeNode(preorder[i]);
        while (!st.empty() && st.top()->val == inorder[j]) {
            topNode = st.top();
            st.pop();
            j++;
        }
        if (topNode) {
            topNode->right = cur;
        } else {
            st.top()->left = cur;
        }
        st.push(cur);
    }
    return root;
}
