//
//  _230_二叉搜索树中第K小的元素.cpp
//  LeetCode-C++
//
//  Created by warden on 2020/2/16.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/

#include <stdio.h>
#include <vector>
#include "TreeNode.hpp"

using namespace std;

class Solution {
private:
    int n = 0;
    int res;
    void dfs(TreeNode* root, int k) {
        if (!root) {
            return;
        }
        dfs(root->left, k);
        if (++n == k) {
            res = root->val;
            return ;
        }
        dfs(root->right, k);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }
};

/**
 输入: root = [3,1,4,null,2], k = 1
    3
   / \
  1   4
   \
    2
 输出: 1
 示例 2:

 输入: root = [5,3,6,2,4,null,null,1], k = 3
        5
       / \
      3   6
     / \
    2   4
   /
  1
 输出: 3
*/
/**
int main(int argc, const char * argv[]) {
    vector<int> nodes = {5,3,6,2,4,INT_MAX,INT_MAX,1};
    TreeNode *root = generateTreeByLevel(nodes);
    Solution* solution = new Solution();
    printf("%d\n", solution->kthSmallest(root, 3));
    return 0;
}
 */
