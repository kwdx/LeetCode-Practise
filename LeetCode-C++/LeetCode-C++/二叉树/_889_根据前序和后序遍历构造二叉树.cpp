//
//  _889_根据前序和后序遍历构造二叉树.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/12.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_889_根据前序和后序遍历构造二叉树.hpp"
#include <stack>

TreeNode* _889_根据前序和后序遍历构造二叉树::constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if (pre.empty()) {
            return NULL;
        }
        TreeNode *root = new TreeNode(pre[0]);
        stack<TreeNode*> st;
        st.push(root);
        for (int i = 1, j = 0; i < pre.size(); i++) {
            TreeNode *node = new TreeNode(pre[i]);
            while (st.top()->val == post[j]) {
                st.pop();
                j++;
            }
            if (!st.top()->left) {
                st.top()->left = node;
            } else {
                st.top()->right = node;
            }
            st.push(node);
        }
        return root;
}
