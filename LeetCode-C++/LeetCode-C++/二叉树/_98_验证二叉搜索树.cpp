//
//  _98_验证二叉搜索树.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/validate-binary-search-tree/

#include <stdio.h>
#include <stack>
#include <climits>
#include <limits.h>
#include "TreeNode.hpp"

using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
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
};

/**
 示例 1:

 输入:
     2
    / \
   1   3
 输出: true
 示例 2:

 输入:
     5
    / \
   1   4
      / \
     3   6
 输出: false
 解释: 输入为: [5,1,4,null,null,3,6]。
      根节点的值为 5 ，但是其右子节点值为 4 。
 */
/**
int main(int argc, const char * argv[]) {
//    TreeNode* root = generateBinaryTree({2, 1, 3});
    TreeNode* root = generateBinaryTree({5,1,4,INT_MAX,INT_MAX,3,6});
    Solution solution = Solution();
    printf("%d\n", solution.isValidBST(root));
    return 0;
}
*/
