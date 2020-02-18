//
//  _105_从前序与中序遍历序列构造二叉树.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/12.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include <stdio.h>
#include <vector>
#include <stack>
#include "TreeNode.hpp"

using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
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
};

/**
 例如，给出

 前序遍历 preorder = [3,9,20,15,7]
 中序遍历 inorder = [9,3,15,20,7]
 返回如下的二叉树：

     3
    / \
   9  20
     /  \
    15   7
 */
/**
int main(int argc, const char * argv[]) {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    Solution* solution = new Solution();
    TreeNode* root = solution->buildTree(preorder, inorder);
    printTreeByLevel(root);
    return 0;
}
*/
