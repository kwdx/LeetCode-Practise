//
//  _105_从前序与中序遍历序列构造二叉树.hpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/12.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#ifndef _105_________________hpp
#define _105_________________hpp

#include <stdio.h>
#include <vector>
#include "TreeNode.hpp"

using namespace std;

class _105_从前序与中序遍历序列构造二叉树 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
};

#endif /* _105_________________hpp */
