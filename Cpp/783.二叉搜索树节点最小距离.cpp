/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
 */

#include <iostream>
#include <stack>
#include <limits.h>
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
    int minDiffInBST(TreeNode* root) {
        int preVal = -1;
        int val = INT_MAX;
        stack<TreeNode*> st;
        TreeNode* pre = root;
        while (pre || !st.empty()) {
            while (pre) {
                st.push(pre);
                pre = pre->left;
            }
            if (!st.empty()) {
                pre = st.top();
                st.pop();
                if (preVal >= 0) {
                    val = min(val, abs(pre->val - preVal));
                }
                preVal = pre->val;
                pre = pre->right;
            }
        }
        return val;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> root;
    int res;
    
    /**
     输入：root = [4,2,6,1,3]
     输出：1
     */
    root = {4,2,6,1,3};
    res = 1;
    assert(res == Solution().minDiffInBST(generateTreeByLevel(root)));
    
    /**
     输入：root = [1,0,48,null,null,12,49]
     输出：1
     */
    root = {1,0,48,INT_MAX,INT_MAX,12,49};
    res = 1;
    assert(res == Solution().minDiffInBST(generateTreeByLevel(root)));

    cout << "OK~" << endl;
    
    return 0;
}
