/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        int lLevel = 0, rLevel = 0;
        TreeNode *node;
        
        node = root;
        while (node) {
            node = node->left;
            lLevel++;
        }
        node = root;
        while (node) {
            node = node->right;
            rLevel++;
        }
        
        if (lLevel == rLevel) return (1<<lLevel) - 1;
        
        return countNodes(root->left) + 1 + countNodes(root->right);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> nodes;
    TreeNode* root;
    
    root = generateTreeByLevel({1,2,3,4,5,6});
    // 6
    cout << Solution().countNodes(root) << endl;
    
    root = generateTreeByLevel({});
    // 0
    cout << Solution().countNodes(root) << endl;
    
    root = generateTreeByLevel({1});
    // 1
    cout << Solution().countNodes(root) << endl;
    
    return 0;
}
