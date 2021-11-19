/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
private:
    int ans = 0;
    int dfs(TreeNode* node) {
        if (!node) return 0;
        
        int leftSum = dfs(node->left);
        int rightSum = dfs(node->right);
        ans += abs(leftSum - rightSum);
        return leftSum + rightSum + node->val;
    }
public:
    int findTilt(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode *root;
    int res;
    
    /**
     输入：root = [1,2,3]
     输出：1
     解释：
     节点 2 的坡度：|0-0| = 0（没有子节点）
     节点 3 的坡度：|0-0| = 0（没有子节点）
     节点 1 的坡度：|2-3| = 1（左子树就是左子节点，所以和是 2 ；右子树就是右子节点，所以和是 3 ）
     坡度总和：0 + 0 + 1 = 1
     */
    root = generateTreeByLevel({1,2,3});
    res = 1;
    assert(res == Solution().findTilt(root));
    
    /**
     输入：root = [4,2,9,3,5,null,7]
     输出：15
     解释：
     节点 3 的坡度：|0-0| = 0（没有子节点）
     节点 5 的坡度：|0-0| = 0（没有子节点）
     节点 7 的坡度：|0-0| = 0（没有子节点）
     节点 2 的坡度：|3-5| = 2（左子树就是左子节点，所以和是 3 ；右子树就是右子节点，所以和是 5 ）
     节点 9 的坡度：|0-7| = 7（没有左子树，所以和是 0 ；右子树正好是右子节点，所以和是 7 ）
     节点 4 的坡度：|(3+5+2)-(9+7)| = |10-16| = 6（左子树值为 3、5 和 2 ，和是 10 ；右子树值为 9 和 7 ，和是 16 ）
     坡度总和：0 + 0 + 0 + 2 + 7 + 6 = 15
     */
    root = generateTreeByLevel({4,2,9,3,5,INT_MAX,7});
    res = 15;
    assert(res == Solution().findTilt(root));
    
    /**
     输入：root = [21,7,14,1,1,2,2,3,3]
     输出：9
     */
    root = generateTreeByLevel({21,7,14,1,1,2,2,3,3});
    res = 9;
    assert(res == Solution().findTilt(root));

    cout << "OK~" << endl;

    return 0;
}
