//
//  _94_二叉树的中序遍历.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/9.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/binary-tree-inorder-traversal/%20/

#include <stdio.h>
#include <vector>
#include <stack>
#include "TreeNode.hpp"

using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> results;
        stack<TreeNode*> st;
        TreeNode* p = root;
        while (p || !st.empty()) {
            while (p) {
                st.push(p);
                p = p->left;
            }
            if (!st.empty()) {
                results.push_back(st.top()->val);
                p = st.top()->right;
                st.pop();
            }
        }
        return results;
    }
};

/**
 输入: [1,null,2,3]
    1
     \
      2
     /
    3

 输出: [1,3,2]
 */
/**
int main(int argc, const char * argv[]) {
    TreeNode* root = generateTreeByLevel({1, INT_MAX, 2, 3});
    Solution* solution = new Solution();
    vector<int> result = solution->inorderTraversal(root);
    printVector(&result);
    return 0;
}
 */
