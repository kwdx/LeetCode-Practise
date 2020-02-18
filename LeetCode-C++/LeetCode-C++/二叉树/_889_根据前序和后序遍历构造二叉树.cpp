//
//  _889_根据前序和后序遍历构造二叉树.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/12.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

#include <stdio.h>
#include <vector>
#include <stack>
#include "TreeNode.hpp"

using namespace std;


class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
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
};

/**
 示例：

 输入：pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
 输出：[1,2,3,4,5,6,7]
 */
/**
int main(int argc, const char * argv[]) {
    vector<int> preorder = {1,2,4,5,3,6,7};
    vector<int> inorder = {4,5,2,6,7,3,1};
    Solution* solution = new Solution();
    TreeNode* root = solution->constructFromPrePost(preorder, inorder);
    printTreeByLevel(root);
    return 0;
}
 */
