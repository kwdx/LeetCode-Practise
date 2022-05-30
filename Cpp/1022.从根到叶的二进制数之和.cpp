/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
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
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
    
    int dfs(TreeNode* root, int cur) {
        int ans = 0, val = (cur << 1) + root->val;
        if (root->left != nullptr) ans += dfs(root->left, val);
        if (root->right != nullptr) ans += dfs(root->right, val);
        return root->left == nullptr && root->right == nullptr ? val : ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode* root;
    int res;
    
    /**
     输入：root = [1,0,1,0,1,0,1]
     输出：22
     解释：(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
     */
    root = generateTreeByLevel({1,0,1,0,1,0,1});
    res = 22;
    assert(res == Solution().sumRootToLeaf(root));
    
    /**
     输入：root = [0]
     输出：0
     */
    root = generateTreeByLevel({0});
    res = 0;
    assert(res == Solution().sumRootToLeaf(root));

    cout << "OK~" << endl;
    
    return 0;
}
