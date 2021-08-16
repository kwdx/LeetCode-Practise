/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root) {
            if (root->val == val) return root;
            else if (root->val < val) root = root->right;
            else root = root->left;
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
    root = solution.searchBST(root, 2);
    /**
     2
    /     \
   1       3
     */
    printTreeByLevel(root);

    return 0;
}
