/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
 */

#include <iostream>
#include <string>
#include <vector>
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
    string tree2str(TreeNode* root) {
        if (root == nullptr) return "";
        dfs(root);
        return ans.substr(1, ans.length() - 2);
    }
    
    void dfs(TreeNode* node) {
        ans.append("(");
        ans.append(to_string(node->val));
        if (node->left != nullptr) dfs(node->left);
        else if (node->right != nullptr) ans.append("()");
        if (node->right != nullptr) dfs(node->right);
        ans.append(")");
    }
private:
    string ans;
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode *root;
    string res;
    
    /**
     输入: 二叉树: [1,2,3,4]
            1
          /   \
         2     3
        /
       4

     输出: "1(2(4))(3)"

     解释: 原本将是“1(2(4)())(3())”，
     在你省略所有不必要的空括号对之后，
     它将是“1(2(4))(3)”。
     */
    root = generateTreeByLevel({1,2,3,4});
    res = "1(2(4))(3)";
    assert(res == Solution().tree2str(root));
    
    /**
     输入: 二叉树: [1,2,3,null,4]
            1
          /   \
         2     3
          \
           4

     输出: "1(2()(4))(3)"

     解释: 和第一个示例相似，
     除了我们不能省略第一个对括号来中断输入和输出之间的一对一映射关系。
     */
    root = generateTreeByLevel({1,2,3,INT_MAX,4});
    res = "1(2()(4))(3)";
    assert(res == Solution().tree2str(root));

    cout << "OK~" << endl;
    
    return 0;
}
