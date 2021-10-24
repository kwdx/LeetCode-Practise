/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

#include <iostream>
#include <vector>
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
private:
    bool ismirror(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) return true;
        if (left == NULL || right == NULL) return false;
        return (left->val == right->val) && ismirror(left->left, right->right) && ismirror(left->right, right->left);
    }
    
public:
    bool isSymmetric1(TreeNode* root) {
        return ismirror(root, root);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while (!q.empty()) {
            TreeNode *t1 = q.front();
            q.pop();
            TreeNode *t2 = q.front();
            q.pop();
            if (t1 == NULL && t2 == NULL) continue;
            if (t1 == NULL || t2 == NULL) return false;
            if (t1->val != t2->val) return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> nodes;
    bool res;
    TreeNode *root;
    
    /**
     示例：
     二叉树 [1,2,2,3,4,4,3] 是对称的。
             1
            / \
           2   2
          / \ / \
         3  4 4  3
     */
    nodes = {1,2,2,3,4,4,3};
    res = true;
    root = generateTreeByLevel(nodes);
    assert(res == Solution().isSymmetric(root));
    
    /**
     但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

         1
        / \
       2   2
        \   \
        3    3
     */
    nodes = {1,2,2,INT_MAX,3,INT_MAX,3};
    res = false;
    root = generateTreeByLevel(nodes);
    assert(res == Solution().isSymmetric(root));

    cout << "OK~" << endl;
    
    return 0;
}
