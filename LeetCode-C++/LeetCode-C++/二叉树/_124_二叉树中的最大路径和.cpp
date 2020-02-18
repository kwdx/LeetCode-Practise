//
//  _124_二叉树中的最大路径和.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/

#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include "TreeNode.hpp"

using namespace std;

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxValue = INT_MIN;
        max(curMaxPathValue(root, maxValue), maxValue);
        return maxValue;
    }
    
    int curMaxPathValue(TreeNode* node, int & maxValue) {
        if (node == nullptr) return 0;
        
        int lv = max(curMaxPathValue(node->left, maxValue), 0);
        int rv = max(curMaxPathValue(node->right, maxValue), 0);
        int tv = node->val + max(lv, rv);
        
        maxValue = max(maxValue, node->val + lv + rv);
        maxValue = max(tv, maxValue);
        
        return tv;
    }
};

/**
 输入: [1,2,3]

        1
       / \
      2   3

 输出: 6
 示例 2:

 输入: [-10,9,20,null,null,15,7]

    -10
    / \
   9  20
     /  \
    15   7

 输出: 42
 */
/**
int main(int argc, const char * argv[]) {
    TreeNode* root = generateTreeByLevel({1,2,3});
//    TreeNode* root = generateTreeByLevel({-10,9,20,INT_MAX,INT_MAX,15,7});
    Solution solution = Solution();
    printf("%d\n", solution.maxPathSum(root));
    return 0;
}
 */
