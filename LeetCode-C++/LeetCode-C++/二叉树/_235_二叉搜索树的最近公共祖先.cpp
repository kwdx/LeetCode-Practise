//
//  _235_二叉搜索树的最近公共祖先.cpp
//  LeetCode-C++
//
//  Created by warden on 2020/2/16.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/

#include <stdio.h>
#include <vector>
#include "TreeNode.hpp"

using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return NULL;
        }
        int left, right = 0;
        if (p->val < q->val) {
            left = p->val;
            right = q->val;
        } else {
            left = q->val;
            right = p->val;
        }
        TreeNode* node = root;
        while (node) {
            if (node->val >= left && node->val <= right) {
                return node;
            } else if (node->val < left) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
        return node;
    }
};

/**
 示例 1:

 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 输出: 6
 解释: 节点 2 和节点 8 的最近公共祖先是 6。
 示例 2:

 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 输出: 2
 解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
 */
/**
int main(int argc, const char * argv[]) {
    vector<int> nodes = {6,2,8,0,4,7,9,INT_MAX,INT_MAX,3,5};
    TreeNode *root = generateTreeByLevel(nodes);
    Solution* solution = new Solution();
    TreeNode *p = new TreeNode(7);
    TreeNode *q = new TreeNode(9);
    TreeNode *node = solution->lowestCommonAncestor(root, p, q);
    printf("%d\n", node->val);

    return 0;
}
*/
