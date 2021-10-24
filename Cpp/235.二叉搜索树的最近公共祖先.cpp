/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return NULL;
        }
        int left, right = 0;
        if (p->val < q->val) {
            left = p->val;
            right = q->val;
        } else {
            left = q->val;
            right = p->val;
        }
        TreeNode* node = root;
        while (node) {
            if (node->val >= left && node->val <= right) {
                return node;
            } else if (node->val < left) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
        return node;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> root;
    TreeNode *p, *q;
    int res;
    
    /**
     输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
     输出: 6
     解释: 节点 2 和节点 8 的最近公共祖先是 6。
     */
    root = {6,2,8,0,4,7,9,INT_MAX,INT_MAX,3,5};
    p = new TreeNode(2);
    q = new TreeNode(8);
    res = 6;
    assert(res == Solution().lowestCommonAncestor(generateTreeByLevel(root), p, q)->val);
    
    /**
     输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
     输出: 2
     解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
     */
    root = {6,2,8,0,4,7,9,INT_MAX,INT_MAX,3,5};
    p = new TreeNode(2);
    q = new TreeNode(4);
    res = 2;
    assert(res == Solution().lowestCommonAncestor(generateTreeByLevel(root), p, q)->val);
    
    cout << "OK~" << endl;
    
    return 0;
}
