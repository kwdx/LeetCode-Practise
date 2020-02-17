//
//  _173_二叉搜索树迭代器.cpp
//  LeetCode-C++
//
//  Created by warden on 2020/2/17.
//  Copyright © 2020 warden. All rights reserved.
//

#include "_173_二叉搜索树迭代器.hpp"
#include <stack>

using namespace std;

_173_二叉搜索树迭代器::_173_二叉搜索树迭代器(TreeNode* root) {
    while (root) {
        st.push(root);
        root = root->left;
    }
}

int _173_二叉搜索树迭代器::next() {
    TreeNode *node = st.top();
    st.pop();
    int res = node->val;
    node = node->right;
    while (node) {
        st.push(node);
        node = node->left;
    }
    return res;
}
    
bool _173_二叉搜索树迭代器::hasNext() {
    return !st.empty();
}
