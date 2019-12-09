//
//  _145_二叉树的后序遍历.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/9.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_145_二叉树的后序遍历.hpp"
#include <stack>
vector<int> _145_二叉树的后序遍历::postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* p = root;
        while (p || !st.empty()) {
            while (p) {
                result.push_back(p->val);
                st.push(p);
                p = p->right;
            }
            
            p = st.top()->left;
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
}
