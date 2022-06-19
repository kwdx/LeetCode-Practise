/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
 */

#include <iostream>
#include <vector>
#include <unordered_map>
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
    unordered_map<int, int> map;
    int maxNum = 0;
    
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int cur = root->val + dfs(root->left) + dfs(root->right);
        map[cur] = map[cur] + 1;
        maxNum = max(maxNum, map[cur]);
        return cur;
    }
    
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> ans;
        for (auto k : map) {
            if (k.second == maxNum) {
                ans.emplace_back(k.first);
            }
        }
        return ans;
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode* root;
    vector<int> ans;
    
    /**
     输入: root = [5,2,-3]
     输出: [2,-3,4]
     */
    root = generateTreeByLevel({5,2,-3});
    ans = {2,-3,4};
    Solution().findFrequentTreeSum(root);
//    assert(ans == Solution().findFrequentTreeSum(root));
    
    /**
     输入: root = [5,2,-5]
     输出: [2]
     */
    root = generateTreeByLevel({5,2,-5});
    ans = {2};
    assert(ans == Solution().findFrequentTreeSum(root));
    
    cout << "OK~" << endl;

    return 0;
}
