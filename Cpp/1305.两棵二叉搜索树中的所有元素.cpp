/*
 * @lc app=leetcode.cn id=1305 lang=cpp
 *
 * [1305] 两棵二叉搜索树中的所有元素
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
private:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        
        TreeNode* node = root;
        while (node || !st.empty()) {
            while (node) {
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            ans.push_back(node->val);
            node = node->right;
        }
        return ans;
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a = preorderTraversal(root1);
        vector<int> b = preorderTraversal(root2);
        vector<int> ans;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
                ans.push_back(a[i++]);
            } else {
                ans.push_back(b[j++]);
            }
        }
        while (i < a.size()) {
            ans.push_back(a[i++]);
        }
        while (j < b.size()) {
            ans.push_back(b[j++]);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode* root1;
    TreeNode* root2;
    vector<int> res;
    
    /**'
     输入：root1 = [2,1,4], root2 = [1,0,3]
     输出：[0,1,1,2,3,4]
     */
    root1 = generateBinaryTree({2,1,4});
    root2 = generateBinaryTree({1,0,3});
    res = {0,1,1,2,3,4};
    assert(res == Solution().getAllElements(root1, root2));
    
    /**'
     输入：root1 = [1,null,8], root2 = [8,1]
     输出：[1,1,8,8]
     */
    root1 = generateBinaryTree({1,8});
    root2 = generateBinaryTree({8,1});
    res = {1,1,8,8};
    assert(res == Solution().getAllElements(root1, root2));
    
    cout << "OK~" << endl;
    
    return 0;
}
