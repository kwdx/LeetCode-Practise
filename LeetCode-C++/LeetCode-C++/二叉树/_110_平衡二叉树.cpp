//
//  _110_平衡二叉树.cpp
//  LeetCode-C++
//
//  Created by warden on 2020/2/17.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/balanced-binary-tree/

#include <stdio.h>
#include <vector>
#include "TreeNode.hpp"

using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;
    }
private:
    int depth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return 1;
        }
        int leftHeight = depth(root->left);
        if (leftHeight < 0) {
            return -1;
        }
        int rightHeight = depth(root->right);
        if (rightHeight < 0) {
            return -1;
        }
        if (abs(rightHeight - leftHeight) > 1) {
            return -1;
        }
        return (rightHeight > leftHeight ? rightHeight : leftHeight) + 1;
    }
};

/**
 示例 1:

 给定二叉树 [3,9,20,null,null,15,7]

     3
    / \
   9  20
     /  \
    15   7
 返回 true 。

 示例 2:

 给定二叉树 [1,2,2,3,3,null,null,4,4]

        1
       / \
      2   2
     / \
    3   3
   / \
  4   4
 返回 false 。
*/
/**
int main(int argc, const char * argv[]) {
    Solution* solution = new Solution();
    vector<int> nodes = {3,9,20,INT_MAX,INT_MAX,15,7};
    TreeNode* root = generateTreeByLevel(nodes);
    printf("%d\n", solution->isBalanced(root));
    vector<int> nodes1 = {1,2,2,3,3,INT_MAX,INT_MAX,4,4};
    TreeNode* root1 = generateTreeByLevel(nodes1);
    printf("%d\n", solution->isBalanced(root1));
    return 0;
}
 */
