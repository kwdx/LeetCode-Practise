//
//  _110_平衡二叉树.hpp
//  LeetCode-C++
//
//  Created by warden on 2020/2/17.
//  Copyright © 2020 warden. All rights reserved.
//

#ifndef _110_______hpp
#define _110_______hpp

#include <stdio.h>
#include "TreeNode.hpp"

class _110_平衡二叉树 {
public:
    bool isBalanced(TreeNode* root);
private:
    int depth(TreeNode* root);
};

#endif /* _110_______hpp */
