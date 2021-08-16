/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        
        stack<TreeNode*> st;
        
        TreeNode* node = root;
        while (node || !st.empty()) {
            while (node) {
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            nodes.push_back(node->val);
            node = node->right;
        }
        return nodes;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    TreeNode* root;
    vector<int> nodes;
    
    root = generateTreeByLevel({1,INT_MAX,2,3});
    // [1,3,2]
    nodes = Solution().inorderTraversal(root);
    for (int node : nodes)
        cout << node << " ";
    cout << endl;
    
    root = generateTreeByLevel({});
    // []
    nodes = Solution().inorderTraversal(root);
    for (int node : nodes)
        cout << node << " ";
    cout << endl;
    
    root = generateTreeByLevel({1});
    // [1]
    nodes = Solution().inorderTraversal(root);
    for (int node : nodes)
        cout << node << " ";
    cout << endl;
    
    root = generateTreeByLevel({1,2});
    // [2,1]
    nodes = Solution().inorderTraversal(root);
    for (int node : nodes)
        cout << node << " ";
    cout << endl;
    
    root = generateTreeByLevel({1,INT_MAX,2});
    // [1,2]
    nodes = Solution().inorderTraversal(root);
    for (int node : nodes)
        cout << node << " ";
    cout << endl;
    
    return 0;
}
