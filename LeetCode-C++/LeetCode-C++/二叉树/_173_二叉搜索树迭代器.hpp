//
//  _173_二叉搜索树迭代器.hpp
//  LeetCode-C++
//
//  Created by warden on 2020/2/17.
//  Copyright © 2020 warden. All rights reserved.
//

#ifndef _173__________hpp
#define _173__________hpp

#include <stdio.h>
#include "TreeNode.hpp"
#include <stack>

using namespace std;

class _173_二叉搜索树迭代器 {
private:
    stack<TreeNode*> st;
public:
    _173_二叉搜索树迭代器(TreeNode* root);
    
    int next();
    
    bool hasNext();
};

#endif /* _173__________hpp */
