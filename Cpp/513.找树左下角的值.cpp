/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.emplace(root);
        int ans = root->val;
        while (!q.empty()) {
            ans = q.front()->val;
            int cnt = (int)q.size();
            for (int i = 0; i < cnt; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.emplace(node->left);
                if (node->right) q.emplace(node->right);
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
     输入: root = [2,1,3]
     输出: 1
     */
    root = generateTreeByLevel({2,1,3});
    res = 1;
    assert(res == Solution().findBottomLeftValue(root));
    
    /**
     输入: [1,2,3,4,null,5,6,null,null,7]
     输出: 7
     */
    root = generateTreeByLevel({1,2,3,4,INT_MAX,5,6,INT_MAX,INT_MAX,7});
    res = 7;
    assert(res == Solution().findBottomLeftValue(root));
    
    cout << "OK~" << endl;
    
    return 0;
}
