//
//  _226_翻转二叉树.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/7.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/invert-binary-tree/

#include <stdio.h>
#include <stack>
#include "TreeNode.hpp"

using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
//    if (!root) return root;
//
//    TreeNode *leftNode = root->left;
//    TreeNode *rightNode = root->right;
//    invertTree(leftNode);
//    invertTree(rightNode);
//    root->left = rightNode;
//    root->right = leftNode;
//    return root;
        if (root == NULL) return NULL;
        
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *node = s.top();
            s.pop();
            TreeNode *tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            if (node->left) s.push(node->left);
            if (node->right) s.push(node->right);
        }
        return root;
    }
};

/**
 输入：

      4
    /   \
   2     7
  / \   / \
 1   3 6   9
 输出：

      4
    /   \
   7     2
  / \   / \
 9   6 3   1
 */
/**
int main(int argc, const char * argv[]) {
    TreeNode* root = generateTreeByLevel({4,2,7,1,3,6,9});
    Solution solution = Solution();
    root = solution.invertTree(root);
    printTreeByLevel(root);
    return 0;
}
*/
