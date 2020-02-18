//
//  _99_恢复二叉搜索树.cpp
//  LeetCode-C++
//
//  Created by warden on 2020/2/17.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/recover-binary-search-tree/

#include <stdio.h>
#include <algorithm>
#include <vector>
#include "TreeNode.hpp"

using namespace std;

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL;
        TreeNode* last = NULL;
        TreeNode* prev = NULL;
        
        while (root) {
            TreeNode* tmp=root->left;
            while (tmp && (tmp->right && tmp->right != root))
                tmp = tmp->right;
            if (!tmp || tmp->right == root) {
                if (tmp)
                    tmp->right = NULL;
                if (prev && root->val < prev->val) {
                    last = root;
                    first = first == NULL ? prev : first;
                }
                prev = root;
                root = root->right;
            } else {
                tmp->right = root;
                root = root->left;
            }
        }
        if (first && last)
            std::swap(first->val, last->val);
    }
};

/**
 输入: [1,3,null,null,2]

    1
   /
  3
   \
    2

 输出: [3,1,null,null,2]

    3
   /
  1
   \
    2
 示例 2:

 输入: [3,1,4,null,null,2]

   3
  / \
 1   4
    /
   2

 输出: [2,1,4,null,null,3]

   2
  / \
 1   4
    /
   3
 */
/**
int main(int argc, const char * argv[]) {
    Solution* solution = new Solution();
    vector<int> nodes = {1,3,INT_MAX,INT_MAX,2};
    TreeNode* root = generateTreeByLevel(nodes);
//    solution.recoverTree(root);
    nodes = {3,1,4,INT_MAX,INT_MAX,2};
    root = generateTreeByLevel(nodes);
    solution->recoverTree(root);
    printTreeByLevel(root);
    return 0;
}
*/
