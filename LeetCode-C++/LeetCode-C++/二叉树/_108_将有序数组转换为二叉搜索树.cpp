//
//  _108_将有序数组转换为二叉搜索树.cpp
//  LeetCode-C++
//
//  Created by warden on 2020/2/16.
//  Copyright © 2020 warden. All rights reserved.
//

#include "_108_将有序数组转换为二叉搜索树.hpp"
#include <vector>

using namespace std;

TreeNode* _108_将有序数组转换为二叉搜索树::sortedArrayToBST(vector<int>& nums) {
    if (nums.size() == 0) {
        return NULL;
    }
    return merge(nums, 0, (int)nums.size() - 1);
}

    TreeNode* _108_将有序数组转换为二叉搜索树::merge(vector<int>& nums, int left, int right) {
        if (left > right) {
            return NULL;
        }
        
        if (left == right) {
            return new TreeNode(nums[left]);
        }
        
        int mid = (left + right + 1) >> 1;
        
        TreeNode* treeNode = new TreeNode(nums[mid]);
        treeNode->left = merge(nums, left, mid - 1);
        treeNode->right = merge(nums, mid + 1, right);
        return treeNode;
    }

