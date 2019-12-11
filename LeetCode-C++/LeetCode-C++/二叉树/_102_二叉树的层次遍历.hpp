//
//  _102_二叉树的层次遍历.hpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/11.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/binary-tree-level-order-traversal/

#ifndef _102__________hpp
#define _102__________hpp

#include <stdio.h>
#include <vector>
#include "TreeNode.hpp"

using namespace std;

class _102_二叉树的层次遍历 {
public:
    vector<vector<int>> levelOrder(TreeNode* root);
};

#endif /* _102__________hpp */
