/*
 * @lc app=leetcode.cn id=814 lang=cpp
 *
 * [814] 二叉树剪枝
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
    TreeNode* pruneTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->left == nullptr && root->right == nullptr && root->val == 0) {
            return nullptr;
        }
        return root;
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode* root;
    
    /**
     输入：root = [1,null,0,0,1]
     输出：[1,null,0,null,1]
     解释：
     只有红色节点满足条件“所有不包含 1 的子树”。 右图为返回的答案。
     */
    root = generateTreeByLevel({1,INT_MAX,0,0,1});
    printTreeByLevel(Solution().pruneTree(root));
    
    /**
     输入：root = [1,0,1,0,0,0,1]
     输出：[1,null,1,null,1]
     */
    root = generateTreeByLevel({1,0,1,0,0,0,1});
    printTreeByLevel(Solution().pruneTree(root));
    
    /**
     输入：root = [1,1,0,1,1,0,1,0]
     输出：[1,1,0,1,1,null,1]
     */
    root = generateTreeByLevel({1,1,0,1,1,0,1,0});
    printTreeByLevel(Solution().pruneTree(root));
    
    cout << "OK~" << endl;
    
    return 0;
}
