/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
 */

#include <iostream>
#include <vector>
#include <unordered_set>
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
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) return false;
        if (sets.count(k - root->val)) return true;
        sets.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
private:
    unordered_set<int> sets;
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode *root;
    int k;
    bool res;
    
    /**
     输入: root = [5,3,6,2,4,null,7], k = 9
     输出: true
     */
    root = generateTreeByLevel({5,3,6,2,4,INT_MAX,7});
    k = 9;
    res = true;
    assert(res == Solution().findTarget(root, k));
    
    /**
     输入: root = [], k = 28
     输出: false
     */
    root = generateTreeByLevel({5,3,6,2,4,INT_MAX,7});
    k = 28;
    res = false;
    assert(res == Solution().findTarget(root, k));

    cout << "OK~" << endl;
    
    return 0;
}
