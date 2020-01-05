//
//  _783_二叉搜索树结点最小距离.cpp
//  LeetCode-C++
//
//  Created by warden on 2020/1/5.
//  Copyright © 2020 warden. All rights reserved.
//

#include "_783_二叉搜索树结点最小距离.hpp"
#include <stack>
#include <limits.h>

using namespace std;

int _783_二叉搜索树结点最小距离::minDiffInBST(TreeNode* root) {
        int preVal = -1;
        int val = INT_MAX;
        stack<TreeNode*> st;
        TreeNode* pre = root;
        while (pre || !st.empty()) {
            while (pre) {
                st.push(pre);
                pre = pre->left;
            }
            if (!st.empty()) {
                pre = st.top();
                st.pop();
                if (preVal >= 0) {
                    val = min(val, abs(pre->val - preVal));
                }
                preVal = pre->val;
                pre = pre->right;
            }
        }
        return val;
}
