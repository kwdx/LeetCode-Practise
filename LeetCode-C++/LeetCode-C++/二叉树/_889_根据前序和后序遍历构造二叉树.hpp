//
//  _889_根据前序和后序遍历构造二叉树.hpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/12.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

#ifndef _889________________hpp
#define _889________________hpp

#include <stdio.h>
#include <vector>
#include "TreeNode.hpp"

using namespace std;

class _889_根据前序和后序遍历构造二叉树 {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post);
};

#endif /* _889________________hpp */
