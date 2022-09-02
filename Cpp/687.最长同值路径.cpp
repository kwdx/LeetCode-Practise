/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
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
private:
    int ans = 0;
public:
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
    
    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        int left1 = 0;
        int right1 = 0;
        if (root->left != nullptr && root->left->val == root->val) {
            left1 = left + 1;
        }
        if (root->right != nullptr && root->right->val == root->val) {
            right1 = right + 1;
        }
        ans = max(ans, left1 + right1);
        return max(left1, right1);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode* root;
    int res;
    
    /**
     输入：root = [5,4,5,1,1,5]
     输出：2
     */
    root = generateTreeByLevel({5,4,5,1,1,INT_MAX,5});
    res = 2;
    assert(res == Solution().longestUnivaluePath(root));
    
    /**
     输入：root = [1,4,5,4,4,5]
     输出：2
     */
    root = generateTreeByLevel({1,4,5,4,4,INT_MAX,5});
    res = 2;
    assert(res == Solution().longestUnivaluePath(root));

    cout << "OK~" << endl;
    
    return 0;
}
