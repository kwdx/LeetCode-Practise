/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        // // 层序
        // queue<TreeNode*> nodes;
        // nodes.push(root);

        // TreeNode *node = nullptr;
        // TreeNode *tempRight = nullptr;
        // TreeNode *rightMost = nullptr;

        // while (!nodes.empty()) {
        //     node = nodes.front();
        //     nodes.pop();

        //     tempRight = node->right;
        //     node->right = node->left;
        //     node->left = nullptr;

        //     rightMost = node;
        //     while (rightMost->right != nullptr) rightMost = rightMost->right;

        //     rightMost->right = tempRight;

        //     if (node->right != nullptr) nodes.push(node->right);
        // }

        // 递归
        if (root->left != nullptr) {
            TreeNode *right = root->right;
            root->right = root->left;
            root->left = nullptr;

            TreeNode *rightMost = root;
            while (rightMost->right != nullptr) rightMost = rightMost->right;
            rightMost->right = right;
        }

        flatten(root->right);
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    Solution solution = Solution();
    TreeNode *root = nullptr;
    
    root = generateTreeByLevel({1,2,5,3,4,INT_MAX,6});
    solution.flatten(root);
    
    return 0;
}
