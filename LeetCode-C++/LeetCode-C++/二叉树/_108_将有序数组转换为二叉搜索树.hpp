//
//  _108_将有序数组转换为二叉搜索树.hpp
//  LeetCode-C++
//
//  Created by warden on 2020/2/16.
//  Copyright © 2020 warden. All rights reserved.
//

#ifndef _108_______________hpp
#define _108_______________hpp

#include <stdio.h>
#include "TreeNode.hpp"
#include <vector>

using namespace std;

class _108_将有序数组转换为二叉搜索树 {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums);
private:
    TreeNode* merge(vector<int>& nums, int left, int right);
};

#endif /* _108_______________hpp */
