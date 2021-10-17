/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 */

#include <iostream>
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
    int n = 0;
    int res = 0;

    void dfs(TreeNode* root, int k) {
        if (!root) return;

        dfs(root->left, k);
        if (++n == k) {
            res = root->val;
            return;
        }
        dfs(root->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        n = 0;
        res = 0;
        dfs(root, k);
        return res;
    }
    int kthSmallest1(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode *node = root;
        int num = 1;
        while (node || !st.empty()) {
            while (node) {
                st.push(node);
                node = node->left;
            }
            node = st.top();
            if (num++ == k) return node->val;
            st.pop();
            node = node->right;
        }
        return 0;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    TreeNode *root;
    int k,res;

    /**
     输入：root = [3,1,4,null,2], k = 1
     输出：1
     */
    root = generateTreeByLevel({3,1,4,INT_MAX,2});
    k = 1;
    res = 1;
    assert(res == Solution().kthSmallest1(root, k));
    
    /**
     输入：root = [5,3,6,2,4,null,null,1], k = 3
     输出：3
     */
    root = generateTreeByLevel({5,3,6,2,4,INT_MAX,INT_MAX,1});
    k = 3;
    res = 3;
    assert(res == Solution().kthSmallest1(root, k));

    cout << "OK~" << endl;
    
    return 0;
}
