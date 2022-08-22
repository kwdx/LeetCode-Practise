/*
 * @lc app=leetcode.cn id=655 lang=cpp
 *
 * [655] 输出二叉树
 */

#include <iostream>
#include <vector>
#include <string>
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
    int h = 0, m = 0, n = 0;
    vector<vector<string>> ans;
public:
    vector<vector<string>> printTree(TreeNode* root) {
        dfs1(root, 0);
        m = h + 1;
        n = (1 << (h + 1)) - 1;
        ans.resize(m, vector<string>(n, ""));
        dfs2(root, 0, (n - 1) / 2);
        return ans;
    }
    
    void dfs1(TreeNode* root, int depth) {
        if (root == nullptr) return;
        h = max(h, depth);
        dfs1(root->left, depth + 1);
        dfs1(root->right, depth + 1);
    }
    
    void dfs2(TreeNode* root, int x, int y) {
        if (root == nullptr) return;
        ans[x][y] = to_string(root->val);
        dfs2(root->left, x + 1, y - (1 << max(h - x - 1, 0)));
        dfs2(root->right, x + 1, y + (1 << max(h - x - 1, 0)));
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode* root;
    vector<vector<string>> res;
    
    /**
     输入：root = [1,2]
     输出：
     [["","1",""],
      ["2","",""]]
     */
    root = generateTreeByLevel({1,2});
    res = {{"","1",""},{"2","",""}};
    assert(res == Solution().printTree(root));
    
    /**
     输入：root = [1,2,3,null,4]
     输出：
     [["","","","1","","",""],
      ["","2","","","","3",""],
      ["","","4","","","",""]]
     */
    root = generateTreeByLevel({1,2,3,INT_MAX,4});
    res = {{"","","","1","","",""},{"","2","","","","3",""},{"","","4","","","",""}};
    assert(res == Solution().printTree(root));

    cout << "OK~" << endl;
    
    return 0;
}
