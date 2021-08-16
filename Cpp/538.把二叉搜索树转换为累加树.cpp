/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
private:
    int sum = 0;

    void traverse(TreeNode* root) {
        if (!root) return;

        traverse(root->right);
        sum += root->val;
        root->val = sum;
        traverse(root->left);

    }
public:
    TreeNode* convertBST(TreeNode* root) {
        sum = 0;
        traverse(root);
        return root;
    }

};
// @lc code=end

int main(int argc, const char * argv[]) {
    Solution solution;
    TreeNode *root;

    root = generateTreeByLevel({4,1,6,0,2,5,7,INT_MAX,INT_MAX,INT_MAX,3,INT_MAX,INT_MAX,INT_MAX,8});
    root = solution.convertBST(root);
    // [30 36 21 36 35 26 15 33 8]
    printTreeByLevel(root);

    root = generateTreeByLevel({0, INT_MAX, 1});
    root = solution.convertBST(root);
    // 1, 1
    printTreeByLevel(root);

    root = generateTreeByLevel({1, 0, 2});
    root = solution.convertBST(root);
    // 3 3 2
    printTreeByLevel(root);

    root = generateTreeByLevel({3, 2, 4, 1});
    root = solution.convertBST(root);
    // 7 9 4 10
    printTreeByLevel(root);

    return 0;
}
