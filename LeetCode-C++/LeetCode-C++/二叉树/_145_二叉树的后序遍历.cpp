//
//  _145_二叉树的后序遍历.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/9.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/binary-tree-postorder-traversal/

#include <stdio.h>
#include <stack>
#include <vector>
#include "TreeNode.hpp"

using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
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
};

/**
 输入: [1,null,2,3]
    1
     \
      2
     /
    3

 输出: [3,2,1]
 */
/**
int main(int argc, const char * argv[]) {
    TreeNode* root = generateTreeByLevel({1, INT_MAX, 2, 3});
    Solution* solution = new Solution();
    vector<int> result = solution->postorderTraversal(root);
    printVector(&result);
    return 0;
}
 */
