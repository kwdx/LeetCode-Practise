/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> nodes;
        if (root) {
            nodes.push(root);
        }
        while (!nodes.empty()) {
            int cnt = (int)nodes.size();
            int val = nodes.front()->val;
            for (int i = 0; i < cnt; ++i) {
                TreeNode* node = nodes.front();
                nodes.pop();
                val = max(val, node->val);
                if (node->left) {
                    nodes.push(node->left);
                }
                if (node->right) {
                    nodes.push(node->right);
                }
            }
            ans.emplace_back(val);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode* root;
    vector<int> res;
    
    /**
     输入: root = [1,3,2,5,3,null,9]
     输出: [1,3,9]
     */
    root = generateBinaryTreeByLevel({1,3,2,5,3,INT_MAX,9});
    res = {1,3,9};
    assert(res == Solution().largestValues(root));
    
    /**
     输入: root = [1,2,3]
     输出: [1,3]
     */
    root = generateBinaryTreeByLevel({1,2,3});
    res = {1,3};
    assert(res == Solution().largestValues(root));
    
    cout << "OK~" << endl;
    
    return 0;
}
