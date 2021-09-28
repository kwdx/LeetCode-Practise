/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */

#include <iostream>
#include <unordered_map>
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
private:
    unordered_map<long long, int> m;
    long long ans = 0;
    int tar = 0;
    
    void dfs(TreeNode* node, int sum) {
        sum += node->val;
        long long tmp = sum - tar;
        if (m[tmp] > 0) {
            ans += (int)m[tmp];
        }
        m[sum] += 1;
        if (node->left) {
            dfs(node->left, sum);
        }
        if (node->right) {
            dfs(node->right, sum);
        }
        m[sum] -= 1;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return 0;
        }
        tar = targetSum;
        m[0] = 1;
        dfs(root, 0);

        return (int)ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    TreeNode* root;
    int targetSum, res;
    
    /**
     输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
     输出：3
     解释：和等于 8 的路径有 3 条，如图所示。
     */
    root = generateTreeByLevel({10,5,-3,3,2,INT_MAX,11,3,-2,INT_MAX,1});
    targetSum = 8;
    res = 3;
    assert(res == Solution().pathSum(root, targetSum));
    
    /**
     输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
     输出：3
     */
    root = generateTreeByLevel({5,4,8,11,INT_MAX,13,4,7,2,INT_MAX,INT_MAX,5,1});
    targetSum = 22;
    res = 3;
    assert(res == Solution().pathSum(root, targetSum));
    
    cout << "OK~" << endl;
    
    return 0;
}
