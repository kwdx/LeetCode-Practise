/*
 * @lc app=leetcode.cn id=1373 lang=cpp
 *
 * [1373] 二叉搜索子树的最大键值和
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
    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        traverse(root);
        return maxSum;
    }
private:
    int maxSum = 0;

    int* traverse(TreeNode* root) {
        if (!root)
            return new int[] {
                1, INT_MAX, INT_MIN, 0
            };

        // 递归计算左右子树
        int* left = traverse(root->left);
        int* right = traverse(root->right);

        int* res = new int[4]{0, 0, 0, 0};
        if (left[0] == 1 && right[0] == 1 &&
            left[2] < root->val && right[1] > root->val) {
            res[0] = 1;
            res[1] = min(left[1], root->val);
            res[2] = max(right[2], root->val);
            res[3] = left[3] + right[3] + root->val;
            maxSum = max(maxSum, res[3]);
        }

        return res;
    }

};
// @lc code=end


int main(int argc, const char * argv[]) {
    vector<int> nodes;

    /**
     输入：root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
     输出：20
     */
    nodes = {1,4,3,2,4,2,5,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,4,6};
    cout << Solution().maxSumBST(generateTreeByLevel(nodes)) << endl;

    /**
     输入：root = [4,3,null,1,2]
     输出：2
     */
    nodes = {4,3,INT_MAX,1,2};
    cout << Solution().maxSumBST(generateTreeByLevel(nodes)) << endl;

    /**
     输入：root = [-4,-2,-5]
     输出：0
     */
    nodes = {-4,-2,-5};
    cout << Solution().maxSumBST(generateTreeByLevel(nodes)) << endl;

    /**
     输入：root = [2,1,3]
     输出：6
     */
    nodes = {2,1,3};
    cout << Solution().maxSumBST(generateTreeByLevel(nodes)) << endl;

    /**
     输入：root = [5,4,8,3,null,6,3]
     输出：7
     */
    nodes = {5,4,8,3,INT_MAX,6,3};
    cout << Solution().maxSumBST(generateTreeByLevel(nodes)) << endl;

    return 0;
}
