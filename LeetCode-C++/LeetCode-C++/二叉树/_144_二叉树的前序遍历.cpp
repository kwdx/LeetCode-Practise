//
//  _144_二叉树的前序遍历.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/7.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/binary-tree-preorder-traversal/

#include <stdio.h>
#include <vector>
#include <stack>
#include "TreeNode.hpp"

using namespace std;
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        stack<TreeNode*> nodes;
        TreeNode *p = root;
        while (p || !nodes.empty()) {
            while (p) {
                result.push_back(p->val);
                nodes.push(p);
                p = p->left;
            }
            
            p = nodes.top();
            nodes.pop();
            p = p->right;
        }
        return result;
    }
};

/**
 输入: [1,null,2,3]
    1
     \
      2
     /
    3

 输出: [1,2,3]
 */
/**
int main(int argc, const char * argv[]) {
    TreeNode* root = generateTreeByLevel({1, INT_MAX, 2, 3});
    Solution* solution = new Solution();
    vector<int> result = solution->preorderTraversal(root);
    printVector(&result);
    return 0;
}
*/
