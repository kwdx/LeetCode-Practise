/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

#include <iostream>
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
    int maxPathSum(TreeNode* root) {
        int maxValue = INT_MIN;
        max(curMaxPathValue(root, maxValue), maxValue);
        return maxValue;
    }
    
    int curMaxPathValue(TreeNode* node, int & maxValue) {
        if (node == nullptr) return 0;
        
        int lv = max(curMaxPathValue(node->left, maxValue), 0);
        int rv = max(curMaxPathValue(node->right, maxValue), 0);
        int tv = node->val + max(lv, rv);
        
        maxValue = max(maxValue, node->val + lv + rv);
        maxValue = max(tv, maxValue);
        
        return tv;
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nodes;
    TreeNode *root;
    int res;
    
    /**
     输入：root = [1,2,3]
     输出：6
     解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
     */
    nodes = {1,2,3};
    res = 6;
    root = generateTreeByLevel(nodes);
    assert(res == Solution().maxPathSum(root));
    
    /**
     输入：root = [-10,9,20,null,null,15,7]
     输出：42
     解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
     */
    nodes = {-10,9,20,INT_MAX,INT_MAX,15,7};
    res = 42;
    root = generateTreeByLevel(nodes);
    assert(res == Solution().maxPathSum(root));
    
    cout << "OK~" << endl;
    
    return 0;
}
