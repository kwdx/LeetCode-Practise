//
//  _106_从中序与后序遍历序列构造二叉树.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/12.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

#include <stdio.h>
#include <vector>
#include <stack>
#include "TreeNode.hpp"

using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
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
};

/**
 例如，给出

 中序遍历 inorder = [9,3,15,20,7]
 后序遍历 postorder = [9,15,7,20,3]
 返回如下的二叉树：

     3
    / \
   9  20
     /  \
    15   7
 */
/**
int main(int argc, const char * argv[]) {
    vector<int> preorder = {9, 3, 15, 20, 7};
    vector<int> inorder = {9, 15, 7, 20, 3};
    Solution* solution = new Solution();
    TreeNode* root = solution->buildTree(preorder, inorder);
    printTreeByLevel(root);
    return 0;
}
 */
