/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) {
            return 0;
        }
        if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        }
        if (root->val > high) {
            return rangeSumBST(root->left, low, high);
        }
        
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...

    vector<int> root;
    int low, high, res;
    
    /**
     输入：root = [10,5,15,3,7,null,18], low = 7, high = 15
     输出：32
     */
    root = {10,5,15,3,7,INT_MAX,18};
    low = 7;
    high = 15;
    res = 32;
    assert(res == Solution().rangeSumBST(generateTreeByLevel(root), low, high));
    
    /**
     输入：root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
     输出：23
     */
    root = {10,5,15,3,7,13,18,1,INT_MAX,6};
    low = 6;
    high = 10;
    res = 23;
    assert(res == Solution().rangeSumBST(generateTreeByLevel(root), low, high));

    cout << "OK~" << endl;
    
    return 0;
}
