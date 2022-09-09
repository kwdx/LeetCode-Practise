/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
 */

#include <iostream>
#include <vector>
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        while (root && (root->val < low || root->val > high)) {
            if (root->val < low) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        if (root == nullptr) {
            return nullptr;
        }
        
        for (auto node = root; node->left; ) {
            if (node->left->val < low) {
                node->left = node->left->right;
            } else {
                node = node->left;
            }
        }
        for (auto node = root; node->right; ) {
            if (node->right->val > high) {
                node->right = node->right->left;
            } else {
                node = node->right;
            }
        }
        return root;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode* root;
    int low;
    int high;
    vector<int> res;
    
    /**
     输入：root = [1,0,2], low = 1, high = 2
     输出：[1,null,2]
     */
    root = generateBinaryTree({1,0,2});
    low = 1;
    high = 2;
    res = {1,2};
    assert(res == getTreeLevel(Solution().trimBST(root, low, high)));
    
    /**
     输入：root = [3,0,4,null,2,null,null,1], low = 1, high = 3
     输出：[3,2,null,1]
     */
    root = generateBinaryTree({3,0,4,INT_MAX,2,INT_MAX,INT_MAX,1});
    low = 1;
    high = 3;
    res = {3,2,1};
    assert(res == getTreeLevel(Solution().trimBST(root, low, high)));

    cout << "OK~" << endl;
    
    return 0;
}
