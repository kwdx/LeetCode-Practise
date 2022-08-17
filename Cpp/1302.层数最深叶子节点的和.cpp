/*
 * @lc app=leetcode.cn id=1302 lang=cpp
 *
 * [1302] 层数最深叶子节点的和
 */

#include <iostream>
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
    int deepestLeavesSum(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = (int)q.size();
            ans = 0;
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front();
                q.pop();
                ans += node->val;
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode* root;
    int res;
    
    /**
     输入：root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
     输出：15
     */
    root = generateTreeByLevel({1,2,3,4,5,INT_MAX,6,7,INT_MAX,INT_MAX,INT_MAX,INT_MAX,8});
    res = 15;
    assert(res == Solution().deepestLeavesSum(root));
    
    /**
     输入：root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
     输出：19
     */
    root = generateTreeByLevel({6,7,8,2,7,1,3,9,INT_MAX,1,4,INT_MAX,INT_MAX,INT_MAX,5});
    res = 19;
    assert(res == Solution().deepestLeavesSum(root));

    cout << "OK~" << endl;
    
    return 0;
}
