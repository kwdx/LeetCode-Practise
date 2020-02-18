//
//  _108_将有序数组转换为二叉搜索树.cpp
//  LeetCode-C++
//
//  Created by warden on 2020/2/16.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/

#include <stdio.h>
#include <vector>
#include "TreeNode.hpp"

using namespace std;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return NULL;
        }
        return merge(nums, 0, (int)nums.size() - 1);
    }
private:
    TreeNode* merge(vector<int>& nums, int left, int right) {
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
};

/**
给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
*/
/**
int main(int argc, const char * argv[]) {
    vector<int> nodes = {-10,-3,0,5,9};
    Solution* solution = new Solution();
    TreeNode* root = solution->sortedArrayToBST(nodes);
    printTreeByLevel(root);
    return 0;
}
 */
