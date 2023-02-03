/*
 * @lc app=leetcode.cn id=1145 lang=cpp
 *
 * [1145] 二叉树着色游戏
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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode *xNode = find(root, x);
        int leftSize = getSubtreeSize(xNode->left);
        if (leftSize >= (n + 1) / 2) {
            return true;
        }
        int rightSize = getSubtreeSize(xNode->right);
        if (rightSize >= (n + 1) / 2) {
            return true;
        }
        int remain = n - 1 - leftSize - rightSize;
        return remain >= (n + 1) / 2;
    }

    TreeNode* find(TreeNode *node, int x) {
        if (node == NULL) {
            return NULL;
        }
        if (node->val == x) {
            return node;
        }
        TreeNode* ans = find(node->left, x);
        if (ans != NULL) {
            return ans;
        } else {
            return find(node->right, x);
        }
    }
    
    int getSubtreeSize(TreeNode *node) {
        if (node == NULL) {
            return 0;
        }
        return 1 + getSubtreeSize(node->left) + getSubtreeSize(node->right);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode* root;
    int n;
    int x;
    bool res;
    
    /**
     输入：root = [1,2,3,4,5,6,7,8,9,10,11], n = 11, x = 3
     输出：true
     解释：第二个玩家可以选择值为 2 的节点。
     */
    root = generateTreeByLevel({1,2,3,4,5,6,7,8,9,10,11});
    n = 11;
    x = 3;
    res = true;
    assert(res == Solution().btreeGameWinningMove(root, n, x));
    
    /**
     输入：root = [1,2,3], n = 3, x = 1
     输出：false
     */
    root = generateTreeByLevel({1,2,3});
    n = 3;
    x = 1;
    res = false;
    assert(res == Solution().btreeGameWinningMove(root, n, x));

    cout << "OK~" << endl;
    
    return 0;
}
