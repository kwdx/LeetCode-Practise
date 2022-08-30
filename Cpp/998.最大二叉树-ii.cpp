/*
 * @lc app=leetcode.cn id=998 lang=cpp
 *
 * [998] 最大二叉树 II
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* parent = nullptr;
        TreeNode* cur = root;
        while (cur != nullptr) {
            if (val > cur->val) {
                if (parent == nullptr) {
                    return new TreeNode(val, root, nullptr);
                }
                TreeNode* node = new TreeNode(val, cur, nullptr);
                parent->right = node;
                return root;
            } else {
                parent = cur;
                cur = cur->right;
            }
        }
        parent->right = new TreeNode(val);
        return root;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode* root;
    int val;
    vector<int> res;
    
    /**
     输入：root = [4,1,3,null,null,2], val = 5
     输出：[5,4,null,1,3,null,null,2]
     解释：a = [1,4,2,3], b = [1,4,2,3,5]
     */
    root = generateTreeByLevel({4,1,3,INT_MAX,INT_MAX,2});
    val = 5;
    res = {5,4,1,3,2};
    assert(res == getTreeLevel(Solution().insertIntoMaxTree(root, val)));
    
    /**
     输入：root = [5,2,4,null,1], val = 3
     输出：[5,2,4,null,1,null,3]
     解释：a = [2,1,5,4], b = [2,1,5,4,3]
     */
    root = generateTreeByLevel({5,2,4,INT_MAX,INT_MAX,1});
    val = 3;
    res = {5,2,4,1,3};
    assert(res == getTreeLevel(Solution().insertIntoMaxTree(root, val)));
    
    /**
     输入：root = [5,2,3,null,1], val = 4
     输出：[5,2,4,null,1,3]
     解释：a = [2,1,5,3], b = [2,1,5,3,4]
     */
    root = generateTreeByLevel({5,2,3,INT_MAX,1});
    val = 4;
    res = {5,2,4,1,3};
    assert(res == getTreeLevel(Solution().insertIntoMaxTree(root, val)));

    cout << "OK~" << endl;
    
    return 0;
}
