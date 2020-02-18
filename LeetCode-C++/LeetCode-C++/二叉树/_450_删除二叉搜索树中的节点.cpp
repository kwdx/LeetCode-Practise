//
//  _450_删除二叉搜索树中的节点.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/17.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/delete-node-in-a-bst/

#include <stdio.h>
#include <vector>
#include "TreeNode.hpp"

using namespace std;

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* curNode = root;
        TreeNode* preNode = root;
        while (curNode && curNode->val != key) {
            preNode = curNode;
            if (curNode->val < key)
                curNode = curNode->right;
            else
                curNode = curNode->left;
        }
        if (!curNode) {
            return root;
        }
        if (!curNode->left && !curNode->right) {
            if (curNode == root) {
                return NULL;
            }
            if (preNode->left == curNode) {
                preNode->left = NULL;
            } else {
                preNode->right = NULL;
            }
        } else if (curNode->left && !curNode->right) {
            if (curNode == root) {
                return curNode->left;
            } else if (preNode->left == curNode) {
                preNode->left = curNode->left;
            } else {
                preNode->right = curNode->left;
            }
        } else if (curNode->right && !curNode->left) {
            if (curNode == root) {
                return curNode->right;
            } else if (preNode->left == curNode) {
                preNode->left = curNode->right;
            } else {
                preNode->right = curNode->right;
            }
        } else {
            TreeNode* dNode = curNode->left;
            while (dNode->right) {
                dNode = dNode->right;
            }
            dNode->right = curNode->right->left;
            curNode->right->left = curNode->left;
            if (curNode == root) {
                return curNode->right;
            } else if (preNode->left == curNode) {
                preNode->left = curNode->right;
            } else {
                preNode->right = curNode->right;
            }
        }
        return root;
    }
};

/**
 root = [5,3,6,2,4,null,7]
 key = 3

     5
    / \
   3   6
  / \   \
 2   4   7

 给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。

 一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。

     5
    / \
   4   6
  /     \
 2       7

 另一个正确答案是 [5,2,6,null,4,null,7]。

     5
    / \
   2   6
    \   \
     4   7
 */
/**
int main(int argc, const char * argv[]) {
    vector<int> nodes = {5,3,6,2,4,INT_MAX,7};
    TreeNode* root = generateTreeByLevel(nodes);
    Solution* solution = new Solution();
    root = solution->deleteNode(root, 3);
    printTreeByLevel(root);
    return 0;
}
*/
