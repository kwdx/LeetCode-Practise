/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
 */

#include <iostream>
#include "TreeNode.h"

using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);

        TreeNode* parent = root;
        TreeNode* node = new TreeNode(val);

        while (parent) {
            if (parent->val < val) {
                if (parent->right) {
                    parent = parent->right;
                } else {
                    parent->right = node;
                    return root;
                }
            } else {
                if (parent->left) {
                    parent = parent->left;
                } else {
                    parent->left = node;
                    return root;
                }
            }
        }

        return root;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    Solution solution;
    TreeNode *root;

    /**
     4
    / \
   2   7
  / \
 1   3
     */
    root = generateTreeByLevel({4,2,7,1,3});
    root = solution.insertIntoBST(root, 5);
    /**
     5
    / \
   2   7
  /     \
 1       3
      \
       4

     4
    /   \
   2     7
  /  \    /
 1    3  5
     */
    printTreeByLevel(root);

    return 0;
}
