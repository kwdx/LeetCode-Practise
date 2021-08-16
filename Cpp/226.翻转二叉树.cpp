/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

#include <iostream>
#include <queue>
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;

        // 层序便利
        queue<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            TreeNode *node = nodes.front();
            nodes.pop();
            TreeNode *tmp = node->right;
            node->right = node->left;
            node->left = tmp;
            if (node->left) nodes.push(node->left);
            if (node->right) nodes.push(node->right);
        }
        
        return root;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    TreeNode* root = generateTreeByLevel({4,2,7,1,3,6,9});
    Solution solution = Solution();
    root = solution.invertTree(root);
    // 4,7,2,9.6,3,1
    printTreeByLevel(root);
    return 0;
}
