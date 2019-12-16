//
//  _106_从中序与后序遍历序列构造二叉树.hpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/12.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

#ifndef _106_________________hpp
#define _106_________________hpp

#include <stdio.h>
#include <vector>
#include "TreeNode.hpp"

using namespace std;

class _106_从中序与后序遍历序列构造二叉树 {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);
};

#endif /* _106_________________hpp */
