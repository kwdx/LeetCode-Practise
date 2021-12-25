/*
 * @lc app=leetcode.cn id=1609 lang=cpp
 *
 * [1609] 奇偶树
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
public:
    bool isEvenOddTree(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        int pre = 0;
        bool isOdd = false;
        TreeNode* node;
        while (!q.empty()) {
            int n = (int)q.size();
            pre = isOdd ? q.front()->val + 1 : 0;
            for (int i = 0; i < n; ++i) {
                node = q.front();
                q.pop();
                if (isOdd) {
                    // 基数层，偶数、递减
                    if (node->val >= pre || node->val % 2 == 1) {
                        return false;
                    }
                } else {
                    // 偶数层，奇数、递增
                    if (node->val <= pre || node->val % 2 == 0) {
                        return false;
                    }
                }
                pre = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            isOdd = !isOdd;
        }
        return true;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nodes;
    TreeNode* root;
    bool res;
    
    /**
     输入：root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
     输出：true
     解释：每一层的节点值分别是：
     0 层：[1]
     1 层：[10,4]
     2 层：[3,7,9]
     3 层：[12,8,6,2]
     由于 0 层和 2 层上的节点值都是奇数且严格递增，而 1 层和 3 层上的节点值都是偶数且严格递减，因此这是一棵奇偶树。
     */
    nodes = {1,10,4,3,INT_MAX,7,9,12,8,6,INT_MAX,INT_MAX,2};
    root = generateTreeByLevel(nodes);
    res = true;
    assert(res == Solution().isEvenOddTree(root));
    
    /**
     输入：root = [5,4,2,3,3,7]
     输出：false
     解释：每一层的节点值分别是：
     0 层：[5]
     1 层：[4,2]
     2 层：[3,3,7]
     2 层上的节点值不满足严格递增的条件，所以这不是一棵奇偶树。
     */
    nodes = {5,4,2,3,3,7};
    root = generateTreeByLevel(nodes);
    res = false;
    assert(res == Solution().isEvenOddTree(root));
    
    /**
     输入：root = [5,9,1,3,5,7]
     输出：false
     解释：1 层上的节点值应为偶数。
     */
    nodes = {5,9,1,3,5,7};
    root = generateTreeByLevel(nodes);
    res = false;
    assert(res == Solution().isEvenOddTree(root));
    
    /**
     输入：root = [1]
     输出：true
     */
    nodes = {1};
    root = generateTreeByLevel(nodes);
    res = true;
    assert(res == Solution().isEvenOddTree(root));
    
    /**
     输入：root = [11,8,6,1,3,9,11,30,20,18,16,12,10,4,2,17]
     输出：true
     */
    nodes = {11,8,6,1,3,9,11,30,20,18,16,12,10,4,2,17};
    root = generateTreeByLevel(nodes);
    res = true;
    assert(res == Solution().isEvenOddTree(root));

    cout << "OK~" << endl;

    return 0;
}
