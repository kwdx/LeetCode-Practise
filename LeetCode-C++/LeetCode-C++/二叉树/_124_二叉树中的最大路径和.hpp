//
//  _124_二叉树中的最大路径和.hpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/

#ifndef _124____________hpp
#define _124____________hpp

#include <stdio.h>
#include "TreeNode.hpp"

class _124_二叉树中的最大路径和 {
public:
    int maxPathSum(TreeNode* root);
    
private:
    int curMaxPathValue(TreeNode* node, int & maxValue);
};

#endif /* _124____________hpp */
