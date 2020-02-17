//
//  _230_二叉搜索树中第K小的元素.hpp
//  LeetCode-C++
//
//  Created by warden on 2020/2/16.
//  Copyright © 2020 warden. All rights reserved.
//

#ifndef _230________K_____hpp
#define _230________K_____hpp

#include <stdio.h>
#include "TreeNode.hpp"

class _230_二叉搜索树中第K小的元素 {
private:
    int n = 0;
    int res;
    void dfs(TreeNode* root, int k);
public:
    int kthSmallest(TreeNode* root, int k);
};

#endif /* _230________K_____hpp */
