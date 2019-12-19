//
//  _101_对称二叉树.hpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/16.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/symmetric-tree/

#ifndef _101_______hpp
#define _101_______hpp

#include <stdio.h>
#include "TreeNode.hpp"

class _101_对称二叉树 {
public:
    bool isSymmetric(TreeNode* root);
    bool isSymmetric1(TreeNode* root);
private:
    bool ismirror(TreeNode* left, TreeNode* right);
};

#endif /* _101_______hpp */
