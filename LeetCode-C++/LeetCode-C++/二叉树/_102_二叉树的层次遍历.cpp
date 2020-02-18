//
//  _102_二叉树的层次遍历.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/11.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/binary-tree-level-order-traversal/

#include <stdio.h>
#include <vector>
#include <queue>
#include "TreeNode.hpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> nodes;
        if (root) {
            nodes.push(root);
        }
        size_t size = nodes.size();
        vector<int> curLevel;
        while (!nodes.empty()) {
            if (size == 0) {
                size = nodes.size();
                result.push_back(curLevel);
                curLevel.clear();
            }
            TreeNode* p = nodes.front();
            nodes.pop();
            curLevel.push_back(p->val);
            if (p->left) {
                nodes.push(p->left);
            }
            if (p->right) {
                nodes.push(p->right);
            }
            size--;
        }
        if (curLevel.size() > 0) {
            result.push_back(curLevel);
        }
        return result;
    }
};

/**
     3
    / \
   9  20
     /  \
    15   7
 返回其层次遍历结果：

 [
   [3],
   [9,20],
   [15,7]
 ]
 */
/**
int main(int argc, const char * argv[]) {
    TreeNode* root = generateTreeByLevel({3, 9, 20, INT_MAX, INT_MAX, 15, 7});
    Solution* solution = new Solution();
    vector<vector<int>> result = solution->levelOrder(root);
    for (auto v:result) {
        printVector(&v);
    }
    return 0;
}
 */
