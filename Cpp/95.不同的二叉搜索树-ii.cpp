/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return build(1, n);
    }

    vector<TreeNode*> build(int lo, int hi) {
        vector<TreeNode*> res;
        if (lo > hi) {
            res.push_back(nullptr);
            return res;
        }

        for (int i = lo; i <= hi; i++) {
            vector<TreeNode*> leftTree = build(lo, i - 1);
            vector<TreeNode*> rightTree = build(i + 1, hi);
            for (TreeNode* left : leftTree) {
                for (TreeNode* right : rightTree) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }

        return res;
    }

};
// @lc code=end

int main(int argc, const char * argv[]) {
    // 1 1 2 5 14 42 132 429 1430 4862 16796 58786 208012 742900 2674440 9694845 35357670 129644790 477638700 1767263190
    for (int i = 1; i <= 8; i++) {
        cout << Solution().generateTrees(i).size() << " ";
    }
    cout << endl;

    return 0;
}

