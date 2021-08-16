/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */

#include <iostream>
#include <vector>
#include "TreeNode.h"

using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, (int)nums.size());
    }
private:
    TreeNode* buildTree(vector<int> &nums, int left, int right) {
        if (left >= right) return nullptr;

        int value = nums[left];
        int index = left;
        for (int i = left; i < right; i++) {
            if (nums[i] > value) {
                value = nums[i];
                index = i;
            }
        }
        TreeNode* node = new TreeNode(value);
        node->left = buildTree(nums, left, index);
        node->right = buildTree(nums, index + 1, right);
        return node;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solution;
    TreeNode *node;
    vector<int> nums;
    
    nums = {3,2,1,6,0,5};
    // [6,3,5,null,2,0,null,null,1]
    node = solution.constructMaximumBinaryTree(nums);

    nums = {3,2,1};
    // [3,null,2,null,1]
    node = solution.constructMaximumBinaryTree(nums);

    return 0;
}
