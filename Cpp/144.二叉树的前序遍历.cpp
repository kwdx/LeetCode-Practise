/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode *node = root;
        while (node || !st.empty()) {
            while (node) {
                ans.push_back(node->val);
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            node = node->right;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    TreeNode *root;
    vector<int> res;
    
    /**
     输入：root = [1,null,2,3]
     输出：[1,2,3]
     */
    root = generateTreeByLevel({1,INT_MAX,2,3});
    res = {1,2,3};
    assert(res == Solution().preorderTraversal(root));
    
    /**
     输入：root = []
     输出：[]
     */
    root = generateTreeByLevel({});
    res = {};
    assert(res == Solution().preorderTraversal(root));
    
    /**
     输入：root = []
     输出：[]
     */
    root = generateTreeByLevel({});
    res = {};
    assert(res == Solution().preorderTraversal(root));
    
    /**
     输入：root = [1]
     输出：[2]
     */
    root = generateTreeByLevel({1});
    res = {1};
    assert(res == Solution().preorderTraversal(root));
    
    /**
     输入：root = [1,2]
     输出：[1,2]
     */
    root = generateTreeByLevel({1,2});
    res = {1,2};
    assert(res == Solution().preorderTraversal(root));
    
    /**
     输入：root = [1,null,2]
     输出：[1,2]
     */
    root = generateTreeByLevel({1,INT_MAX,2});
    res = {1,2};
    assert(res == Solution().preorderTraversal(root));
    
    cout << "OK~" << endl;
    
    return 0;
}
