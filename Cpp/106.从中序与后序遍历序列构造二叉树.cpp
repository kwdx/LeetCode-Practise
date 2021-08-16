/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, postorder, 0, (int)inorder.size(), 0, (int)postorder.size());
    }

private:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {
        if (inStart >= inEnd) return nullptr;

        int value = postorder[postEnd - 1];
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
        node->left = buildTree(inorder, postorder,
                               inStart, index,
                               postStart, postStart + leftLen);
        node->right = buildTree(inorder, postorder,
                                index + 1, inEnd,
                                postStart + leftLen, postEnd - 1);
        return node;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {

    Solution solution = Solution();
    TreeNode *node = nullptr;
    vector<int> inorder;
    vector<int> postorder;

    inorder = {9, 3, 15, 20, 7};
    postorder = {9, 15, 7, 20, 3};
    node = solution.buildTree(inorder, postorder);

    inorder = {-1};
    postorder = {-1};
    node = solution.buildTree(inorder, postorder);

    return 0;
}
