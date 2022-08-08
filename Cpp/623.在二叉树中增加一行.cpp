/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while (!q.empty() && level < depth) {
            int sz = (int)q.size();
            while (sz-- > 0) {
                TreeNode* node= q.front();
                q.pop();
                if (level == depth - 1) {
                    TreeNode* a = new TreeNode(val);
                    TreeNode* b = new TreeNode(val);
                    a->left = node->left;
                    b->right = node->right;
                    node->left = a;
                    node->right = b;
                } else {
                    if (node->left != nullptr) q.push(node->left);
                    if (node->right != nullptr) q.push(node->right);
                }
            }
            ++level;
        }
        return root;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode* root;
    int val;
    int depth;
    TreeNode* res;
    
    /**
     输入: root = [4,2,6,3,1,5], val = 1, depth = 2
     输出: [4,1,1,2,null,null,6,3,1,5]
     */
    root = generateTreeByLevel({4,2,6,3,1,5});
    val = 1;
    depth = 2;
    res = Solution().addOneRow(root, val, depth);
    printTreeByLevel(res);
    
    /**
     输入: root = [4,2,null,3,1], val = 1, depth = 3
     输出:  [4,2,null,1,1,3,null,null,1]
     */
    root = generateTreeByLevel({4,2,INT_MAX,3,1});
    val = 1;
    depth = 3;
    res = Solution().addOneRow(root, val, depth);
    printTreeByLevel(res);
    
    cout << "OK~" << endl;
    
    return 0;
}
