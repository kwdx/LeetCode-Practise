/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums, res;
    TreeNode *node;
    
    /**
     输入：nums = [-10,-3,0,5,9]
     输出：[0,-3,9,-10,null,5]
     解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：
     */
    nums = {-10,-3,0,5,9};
    res = {0,-3,9,-10,5};
    node = Solution().sortedArrayToBST(nums);
    assert(res == getTreeLevel(node));
    
    /**
     输入：nums = [1,3]
     输出：[3,1]
     解释：[1,3] 和 [3,1] 都是高度平衡二叉搜索树。     */
    nums = {1,3};
    res = {3,1};
    node = Solution().sortedArrayToBST(nums);
    assert(res == getTreeLevel(node));
    
    cout << "OK~" << endl;
    
    return 0;
}
