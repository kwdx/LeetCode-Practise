/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (root == p || root == q) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left && right) return root;
        
        if (!left && !right) return NULL;
        
        return left != NULL ? left : right;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    TreeNode* root;
    TreeNode* parent;
    
    root = generateTreeByLevel({3,5,1,6,2,0,8,INT_MAX,INT_MAX,7,4});
    // 3
    parent = Solution().lowestCommonAncestor(root, root->left, root->right);
    cout << parent->val << endl;
    
    root = generateTreeByLevel({3,5,1,6,2,0,8,INT_MAX,INT_MAX,7,4});
    // 5
    parent = Solution().lowestCommonAncestor(root, root->left, root->left->right->right);
    cout << parent->val << endl;
    
    root = generateTreeByLevel({1,2});
    // 1
    parent = Solution().lowestCommonAncestor(root, root, root->left);
    cout << parent->val << endl;
    
    return 0;
}
