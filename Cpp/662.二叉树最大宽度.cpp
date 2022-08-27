/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
 */

#include <iostream>
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
    int ans = 0;
public:
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 1, 0);
        return ans;
    }
    
    void dfs(TreeNode* root, int idx, int depth) {
        if (root == nullptr) return;
        if (map.count(depth) == 0) {
            map[depth] = idx;
        }
        ans = max(ans, idx - map[depth] + 1);
        idx = idx - map[depth] + 1;
        dfs(root->left, idx << 1, depth + 1);
        dfs(root->right, idx << 1 | 1, depth + 1);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode* root;
    int res;
    
    /**
     输入：root = [1,3,2,5,3,null,9]
     输出：4
     解释：最大宽度出现在树的第 3 层，宽度为 4 (5,3,null,9) 。
     */
    root = generateTreeByLevel({1,3,2,5,3,INT_MAX,9});
    res = 4;
    assert(res == Solution().widthOfBinaryTree(root));
    
    /**
     输入：root = [1,3,2,5,null,null,9,6,null,7]
     输出：7
     解释：最大宽度出现在树的第 4 层，宽度为 7 (6,null,null,null,null,null,7) 。
     */
    root = generateTreeByLevel({1,3,2,5,INT_MAX,INT_MAX,9,6,INT_MAX,7});
    res = 7;
    assert(res == Solution().widthOfBinaryTree(root));
    
    /**
     输入：root = [1,3,2,5]
     输出：2
     解释：最大宽度出现在树的第 2 层，宽度为 2 (3,2) 。
     */
    root = generateTreeByLevel({1,3,2,5});
    res = 2;
    assert(res == Solution().widthOfBinaryTree(root));

    cout << "OK~" << endl;
    
    return 0;
}
