/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* getMin(TreeNode* node) {
        // BST 最左边的就是最小的
        while (node->left != nullptr) node = node->left;
        return node;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root-> val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            TreeNode* minNode = getMin(root->right);
            root->val = minNode->val;
            root->right = deleteNode(root->right, minNode->val);
        }

        return root;
    }

    TreeNode* deleteNode1(TreeNode* root, int key) {
        TreeNode* deleteNode = root;
        TreeNode* parentNode = root;
        while (deleteNode && deleteNode->val != key) {
            parentNode = deleteNode;
            if (deleteNode->val < key)
                deleteNode = deleteNode->right;
            else
                deleteNode = deleteNode->left;
        }
        if (!deleteNode) return root;

        if (!deleteNode->left || !deleteNode->right) {
            // 任意子节点为空或为叶子节点
            TreeNode* replaceNode = deleteNode->left ? deleteNode->left : deleteNode->right;

            if (deleteNode == root) {
                // 删除的是根结点
                return replaceNode;
            }
            if (parentNode->left == deleteNode)
                parentNode->left = replaceNode;
            else
                parentNode->right = replaceNode;
        } else {
            // 左右子树均有
            TreeNode* leftRightNode = deleteNode->left;
            while (leftRightNode->right)
                leftRightNode = leftRightNode->right;
            // 选择deleteNode->right登基
            leftRightNode->right = deleteNode->right->left;
            deleteNode->right->left = deleteNode->left;
            if (deleteNode == root)
                return deleteNode->right;
            if (parentNode->left == deleteNode)
                parentNode->left = deleteNode->right;
            else
                parentNode->right = deleteNode->right;
        }
        return root;
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    Solution solution;
    TreeNode *root;

//    /**
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
//     */
//    root = generateTreeByLevel({5,3,6,2,4,INT_MAX,7});
//    root = solution.deleteNode(root, 3);
//    /**
//     5
//    / \
//   4   6
//  /     \
// 2       7
//
//     5
//    / \
//   2   6
//    \   \
//     4   7
//     */
//    printTreeByLevel(root);

    root = generateTreeByLevel({5,3,6,2,4,INT_MAX,7});
    root = solution.deleteNode(root, 5);
    /**
     5
    /    \
   3       6
  /   \     /
 2     4 7
     
     6
    /   \
   3      7
  /   \
 2      4
     */
    printTreeByLevel(root);
    
    return 0;
}
