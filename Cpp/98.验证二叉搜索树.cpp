/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

#include <iostream>
#include <stack>
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
    long maxValue = LONG_MIN;
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;

        bool left = isValidBST(root->left);
        if (root->val > maxValue) maxValue = root->val;
        else return false;
        bool right = isValidBST(root->right);

        return left && right;
    }

    bool isValidBST1(TreeNode* root) {
        TreeNode* node = root;
        stack<TreeNode*> st;
        long inorder = LONG_MIN;

        while (node || !st.empty()) {
            while (node) {
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            if (node->val <= inorder) return false;
            inorder = node->val;
            node = node->right;
        }

        return true;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    Solution solution;
    TreeNode *root;

    root = generateTreeByLevel({2, 1, 3});
    // true
    cout << solution.isValidBST(root) << endl;

    root = generateTreeByLevel({5, 1, 4, INT_MAX, INT_MAX, 3, 6});
    // false
    cout << solution.isValidBST(root) << endl;

    cout << INT_MIN << endl;
    root = generateTreeByLevel({-2147483648});
    // false
    cout << solution.isValidBST(root) << endl;
    
    return 0;
}

