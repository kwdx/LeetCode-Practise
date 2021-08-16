/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, (int)preorder.size(), 0, (int)inorder.size());
    }

private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
        if (preStart >= preEnd) return nullptr;

        int value = preorder[preStart];
        TreeNode* node = new TreeNode(value);

        // 找出中序遍历的根节点下标
        int index = inStart;
        for (int i = inStart; i < inEnd; i++) {
            if (inorder[i] == value) {
                index = i;
                break;
            }
        }

        int leftLen = index - inStart;
        node->left = buildTree(preorder, inorder,
                               preStart + 1, preStart + 1 + leftLen,
                               inStart, index);
        node->right = buildTree(preorder, inorder,
                                preStart + 1 + leftLen, preEnd,
                                index + 1, inEnd);
        return node;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {

    Solution solution = Solution();
    TreeNode *node = nullptr;
    vector<int> preorder;
    vector<int> inorder;

    preorder = {3, 9, 20, 15, 7};
    inorder = {9, 3, 15, 20, 7};
    node = solution.buildTree(preorder, inorder);

    preorder = {-1};
    inorder = {-1};
    node = solution.buildTree(preorder, inorder);

    return 0;
}
