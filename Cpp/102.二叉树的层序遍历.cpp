/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *node;
        while (!q.empty()) {
            int len = (int)q.size();
            vector<int> level;
            for (int i = 0; i < len; ++i) {
                node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    TreeNode *root;
    vector<vector<int>> res;
    
    /**
     示例：
     二叉树：[3,9,20,null,null,15,7],

         3
        / \
       9  20
         /  \
        15   7
     返回其层序遍历结果：

     [
       [3],
       [9,20],
       [15,7]
     ]
     */
    root = generateTreeByLevel({3,9,20,INT_MAX,INT_MAX,15,7});
    res = {{3},{9,20},{15,7}};
    assert(res == Solution().levelOrder(root));
    
    cout << "OK~" << endl;
    
    return 0;
}
