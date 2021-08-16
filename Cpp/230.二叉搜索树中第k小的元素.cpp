/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int n = 0;
    int res = 0;

    void dfs(TreeNode* root, int k) {
        if (!root) return;

        dfs(root->left, k);
        if (++n == k) {
            res = root->val;
            return;
        }
        dfs(root->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        n = 0;
        res = 0;
        dfs(root, k);
        return res;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    Solution solution;
    TreeNode *root;

    root = generateTreeByLevel({3, 1, 4, INT_MAX, 2});
    // 1
    cout << solution.kthSmallest(root, 1) << endl;

    root = generateTreeByLevel({5,3,6,2,4,INT_MAX,INT_MAX,1});
    // 3
    cout << solution.kthSmallest(root, 3) << endl;
    return 0;
}
