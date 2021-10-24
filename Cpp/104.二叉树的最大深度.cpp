/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

#include <iostream>
#include <queue>
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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        queue<TreeNode*> nodes;
        if (root) {
            nodes.push(root);
        }
        size_t size = 0;
        while (!nodes.empty()) {
            if (size == 0) {
                size = nodes.size();
                depth++;
            }
            TreeNode* p = nodes.front();
            nodes.pop();
            if (p->left) {
                nodes.push(p->left);
            }
            if (p->right) {
                nodes.push(p->right);
            }
            size--;
        }
        return depth;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> nodes;
    int res;
    TreeNode *root;
    
    /**
     示例：
     给定二叉树 [3,9,20,null,null,15,7]，

         3
        / \
       9  20
         /  \
        15   7
     返回它的最大深度 3 。     */
    nodes = {3,9,20,INT_MAX,INT_MAX,15,7};
    res = 3;
    root = generateTreeByLevel(nodes);
    assert(res == Solution().maxDepth(root));

    cout << "OK~" << endl;
    
    return 0;
}
