//
//  _124_二叉树中的最大路径和.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_124_二叉树中的最大路径和.hpp"
#include <limits.h>
#include <algorithm>

using namespace std;

int _124_二叉树中的最大路径和::maxPathSum(TreeNode* root) {
    int maxValue = INT_MIN;
    max(curMaxPathValue(root, maxValue), maxValue);
    return maxValue;
}

int _124_二叉树中的最大路径和::curMaxPathValue(TreeNode* node, int & maxValue) {
    if (node == nullptr) return 0;
    
    int lv = max(curMaxPathValue(node->left, maxValue), 0);
    int rv = max(curMaxPathValue(node->right, maxValue), 0);
    int tv = node->val + max(lv, rv);
    
    maxValue = max(maxValue, node->val + lv + rv);
    maxValue = max(tv, maxValue);
    
    return tv;
}
