//
//  _98_验证二叉搜索树.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_98_验证二叉搜索树.hpp"
#include <stack>
#include <climits>

using namespace std;

bool _98_验证二叉搜索树::isValidBST(TreeNode* root) {
        TreeNode* p = root;
        stack<TreeNode *> st;
        long inorder = LONG_MIN;
        
        while (p || !st.empty()) {
            while (p) {
                st.push(p);
                p = p->left;
            }
            p = st.top();
            st.pop();
            if (p->val <= inorder) return false;
            inorder = p->val;
            p = p->right;
        }

        return true;
}
