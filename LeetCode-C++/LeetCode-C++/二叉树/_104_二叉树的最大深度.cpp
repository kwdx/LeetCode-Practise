//
//  _104_二叉树的最大深度.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/11.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/

#include <stdio.h>
#include <queue>
#include "TreeNode.hpp"

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        queue<TreeNode*> nodes;
        if (root) {
            nodes.push(root);
        }
        size_t size = 0;
        while (!nodes.empty()) {
            if (size == 0) {
                size = nodes.size();
                depth++;
            }
            TreeNode* p = nodes.front();
            nodes.pop();
            if (p->left) {
                nodes.push(p->left);
            }
            if (p->right) {
                nodes.push(p->right);
            }
            size--;
        }
        return depth;
    }
};

/**
 示例：
 给定二叉树 [3,9,20,null,null,15,7]，

     3
    / \
   9  20
     /  \
    15   7
 返回它的最大深度 3 。
 */
/**
int main(int argc, const char * argv[]) {
    TreeNode* root = generateTreeByLevel({3, 9, 20, INT_MAX, INT_MAX, 15, 7});
    Solution* solution = new Solution();
    printf("%d\n", solution->maxDepth(root));
    return 0;
}
 */
