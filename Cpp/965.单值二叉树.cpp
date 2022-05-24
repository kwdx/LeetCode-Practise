/*
 * @lc app=leetcode.cn id=965 lang=cpp
 *
 * [965] 单值二叉树
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
    bool isUnivalTree(TreeNode* root) {
        if (!root) {
            return true;
        }
        if (root->left && root->left->val != root->val) {
            return false;
        }
        if (root->right && root->right->val != root->val) {
            return false;
        }
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode* root;
    bool res;
    
    /**
     输入：[1,1,1,1,1,null,1]
     输出：true
     */
    root = generateTreeByLevel({1,1,1,1,1,INT_MAX,1});
    res = true;
    assert(res == Solution().isUnivalTree(root));
    
    /**
     输入：[2,2,2,5,2]
     输出：false
     */
    root = generateTreeByLevel({2,2,2,5,2});
    res = false;
    assert(res == Solution().isUnivalTree(root));

    cout << "OK~" << endl;
    
    return 0;
}
