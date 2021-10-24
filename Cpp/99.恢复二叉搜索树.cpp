/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */

#include <iostream>
#include <vector>
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
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL;
        TreeNode* last = NULL;
        TreeNode* prev = NULL;
        
        while (root) {
            TreeNode* tmp=root->left;
            while (tmp && (tmp->right && tmp->right != root))
                tmp = tmp->right;
            if (!tmp || tmp->right == root) {
                if (tmp)
                    tmp->right = NULL;
                if (prev && root->val < prev->val) {
                    last = root;
                    first = first == NULL ? prev : first;
                }
                prev = root;
                root = root->right;
            } else {
                tmp->right = root;
                root = root->left;
            }
        }
        if (first && last)
            swap(first->val, last->val);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    TreeNode *root;
    vector<int> nodes, res;
    
    /**
     输入：root = [1,3,null,null,2]
     输出：[3,1,null,null,2]
     解释：3 不能是 1 左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。
     */
    nodes = {1,3,INT_MAX,INT_MAX,2};
    res = {3,1,2};
    root = generateTreeByLevel(nodes);
    Solution().recoverTree(root);
    assert(res == getTreeLevel(root));
    
    /**
     输入：root = [3,1,4,null,null,2]
     输出：[2,1,4,null,null,3]
     解释：2 不能在 3 的右子树中，因为 2 < 3 。交换 2 和 3 使二叉搜索树有效。
     */
    nodes = {3,1,4,INT_MAX,INT_MAX,2};
    res = {2,1,4,3};
    root = generateTreeByLevel(nodes);
    Solution().recoverTree(root);
    assert(res == getTreeLevel(root));
    
    cout << "OK~" << endl;
    
    return 0;
}
