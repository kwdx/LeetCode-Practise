/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
 */

#include <iostream>
#include <vector>
#include <stack>
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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if (preorder.empty()) {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[0]);
        stack<TreeNode*> st;
        st.push(root);
        for (int i = 1, j = 0; i < preorder.size(); i++) {
            TreeNode *node = new TreeNode(preorder[i]);
            while (st.top()->val == postorder[j]) {
                st.pop();
                j++;
            }
            if (!st.top()->left) {
                st.top()->left = node;
            } else {
                st.top()->right = node;
            }
            st.push(node);
        }
        return root;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...

    vector<int> preorder, postorder, res;
    
    /**
     输入：pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
     输出：[1,2,3,4,5,6,7]
     */
    preorder = {1,2,4,5,3,6,7};
    postorder = {4,5,2,6,7,3,1};
    res = {1,2,3,4,5,6,7};
    assert(res == getTreeLevel(Solution().constructFromPrePost(preorder, postorder)));
    
    cout << "OK~" << endl;
    
    return 0;
}
