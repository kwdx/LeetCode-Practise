//
//  _114_二叉树展开为链表.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_114_二叉树展开为链表.hpp"

void _114_二叉树展开为链表::flatten(TreeNode* root) {
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
