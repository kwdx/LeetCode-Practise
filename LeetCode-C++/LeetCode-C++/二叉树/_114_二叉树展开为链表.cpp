//
//  _114_二叉树展开为链表.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/

#include <stdio.h>
#include "TreeNode.hpp"

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        
        if (root->left != nullptr) {
            // 保留right
            TreeNode* right = root->right;
            // 将left嫁接到right
            root->right = root->left;
            // 清空left
            root->left = nullptr;
            // 将right嫁接到root的最右下角
            TreeNode* rightMost = root->right;
            while (rightMost->right != nullptr) {
                rightMost = rightMost->right;
            }
            rightMost->right = right;
        }
        flatten(root->right);
    }
};

/**
     1
    / \
   2   5
  / \   \
 3   4   6
 将其展开为：

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
 */
/**
int main(int argc, const char * argv[]) {
    TreeNode* root = generateTreeByLevel({1,2,5,3,4,INT_MAX,6});
    Solution solution = Solution();
    solution.flatten(root);
    while (root) {
        printf("%d ", root->val);
        root = root->right;
    }
    printf("\n");
    return 0;
}
*/
