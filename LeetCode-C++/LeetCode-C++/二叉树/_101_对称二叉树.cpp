//
//  _101_对称二叉树.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/16.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/symmetric-tree/

#include <stdio.h>
#include <queue>
#include "TreeNode.hpp"

using namespace std;

class Solution {
private:
    bool ismirror(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) return true;
        if (left == NULL || right == NULL) return false;
        return (left->val == right->val) && ismirror(left->left, right->right) && ismirror(left->right, right->left);
    }
    
public:
    bool isSymmetric1(TreeNode* root) {
        return ismirror(root, root);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while (!q.empty()) {
            TreeNode *t1 = q.front();
            q.pop();
            TreeNode *t2 = q.front();
            q.pop();
            if (t1 == NULL && t2 == NULL) continue;
            if (t1 == NULL || t2 == NULL) return false;
            if (t1->val != t2->val) return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
};

/**
 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

     1
    / \
   2   2
  / \ / \
 3  4 4  3
 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

     1
    / \
   2   2
    \   \
    3    3
 */
/**
int main(int argc, const char * argv[]) {
//    vector<int> levels = {1,2,2,3,4,4,3};
    vector<int> levels = {1,2,2,INT_MAX,3,INT_MAX,3};
    TreeNode* root = generateTreeByLevel(levels);
    Solution* solution = new Solution();
    printf("%d\n", solution->isSymmetric(root));
    return 0;
}
 */
