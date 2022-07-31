/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] 最大层内元素和
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
    int maxLevelSum(TreeNode* root) {
        int ans = 0;
        int maxVal = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node;
        int level = 0;
        while (!q.empty()) {
            ++level;
            int sz = (int)q.size();
            int tmp = 0;
            for (int i = 0; i < sz; ++i) {
                node = q.front();
                q.pop();
                tmp += node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            if (tmp > maxVal) {
                maxVal = tmp;
                ans = level;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode* root;
    int res;
    
    /**
     输入：root = [1,7,0,7,-8,null,null]
     输出：2
     解释：
     第 1 层各元素之和为 1，
     第 2 层各元素之和为 7 + 0 = 7，
     第 3 层各元素之和为 7 + -8 = -1，
     所以我们返回第 2 层的层号，它的层内元素之和最大。
     */
    root = generateTreeByLevel({1,7,0,7,-8});
    res = 2;
    assert(res == Solution().maxLevelSum(root));
    
    /**
     输入：root = [989,null,10250,98693,-89388,null,null,null,-32127]
     输出：2
     */
    root = generateTreeByLevel({989,INT_MAX,10250,98693,-89388,INT_MAX,INT_MAX,INT_MAX,-32127});
    res = 2;
    assert(res == Solution().maxLevelSum(root));
    
    cout << "OK~" << endl;
    
    return 0;
}
