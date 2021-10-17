/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

#include <iostream>
#include <vector>
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode *node = root;
        
        while (node || !st.empty()) {
            while (node) {
                ans.push_back(node->val);
                st.push(node);
                node = node->right;
            }
            node = st.top()->left;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    TreeNode *root;
    vector<int> res;
    
    /**
     输入: [1,null,2,3]
        1
         \
          2
         /
        3

     输出: [3,2,1]
     */
    root = generateTreeByLevel({1,INT_MAX,2,3});
    res = {3,2,1};
    assert(res == Solution().postorderTraversal(root));
    
    /**
     输入: [3,1,2]
        3
        / \
       1   2

     输出: [1,2,3]
     */
    root = generateTreeByLevel({3,1,2});
    res = {1,2,3};
    assert(res == Solution().postorderTraversal(root));
    
    cout << "OK~" << endl;
    
    return 0;
}
