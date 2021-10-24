/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;
    }
private:
    int depth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return 1;
        }
        int leftHeight = depth(root->left);
        if (leftHeight < 0) {
            return -1;
        }
        int rightHeight = depth(root->right);
        if (rightHeight < 0) {
            return -1;
        }
        if (abs(rightHeight - leftHeight) > 1) {
            return -1;
        }
        return (rightHeight > leftHeight ? rightHeight : leftHeight) + 1;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nodes;
    TreeNode *root;
    bool res;
    
    /**
     输入：root = [3,9,20,null,null,15,7]
     输出：true
     */
    nodes = {3,9,20,INT_MAX,INT_MAX,15,7};
    res = true;
    root = generateTreeByLevel(nodes);
    assert(res == Solution().isBalanced(root));
    
    /**
     输入：root = [1,2,2,3,3,null,null,4,4]
     输出：false
     */
    nodes = {1,2,2,3,3,INT_MAX,INT_MAX,4,4};
    res = false;
    root = generateTreeByLevel(nodes);
    assert(res == Solution().isBalanced(root));
    
    /**
     输入：root = []
     输出：true
     */
    nodes = {};
    res = true;
    root = generateTreeByLevel(nodes);
    assert(res == Solution().isBalanced(root));

    cout << "OK~" << endl;
    
    return 0;
}
