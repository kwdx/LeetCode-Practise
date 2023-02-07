/*
 * @lc app=leetcode.cn id=2331 lang=cpp
 *
 * [2331] 计算布尔二叉树的值
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
    bool evaluateTree(TreeNode* root) {
        if (root == nullptr) return true;
        if (root->val == 0) return false;
        if (root->val == 1) return true;
        if (root->val == 2) return evaluateTree(root->left) | evaluateTree(root->right);
        if (root->val == 3) return evaluateTree(root->left) & evaluateTree(root->right);
        return true;
    }
    
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode* root;
    bool res;
    
    /**
     输入：root = [2,1,3,null,null,0,1]
     输出：true
     解释：上图展示了计算过程。
     AND 与运算节点的值为 False AND True = False 。
     OR 运算节点的值为 True OR False = True 。
     根节点的值为 True ，所以我们返回 true 。
     */
    root = generateTreeByLevel({2,1,3,INT_MAX,INT_MAX,0,1});
    res = true;
    assert(res == Solution().evaluateTree(root));
    
    /**
     输入：root = [0]
     输出：false
     解释：根节点是叶子节点，且值为 false，所以我们返回 false 。
     */
    root = generateTreeByLevel({0});
    res = false;
    assert(res == Solution().evaluateTree(root));

    cout << "OK~" << endl;
    
    return 0;
}
