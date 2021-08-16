/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
 */

#include <iostream>
#include <vector>
#include <map>
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        nodes.clear();
        tress.clear();
        inorderTravel(root);
        return nodes;
    }

private:
    vector<TreeNode*> nodes;
    map<string, int> tress;

    string inorderTravel(TreeNode* root) {
        if (root == nullptr) return "#";

        string left = inorderTravel(root->left);
        string right = inorderTravel(root->right);

        string id = left + "_" + right + "_" + to_string(root->val);
//        string id = left + "_" + to_string(root->val) + "_" + right;
        int freq = 0;
        auto iter = tress.find(id);
        if (iter != tress.end()) {
            // 有找到
            freq = iter->second;
        }
        if (freq == 1) {
            nodes.push_back(root);
        }
        tress[id] = freq + 1;
        return id;
    }

};
// @lc code=end

int main(int argc, const char * argv[]) {

    Solution solution = Solution();
    vector<TreeNode*> nodes;

    TreeNode *node_1 = new TreeNode(1);
    TreeNode *node_2 = new TreeNode(2);
    TreeNode *node_3 = new TreeNode(3);
    TreeNode *node_4 = new TreeNode(4);
    TreeNode *node_2_ = new TreeNode(2);
    TreeNode *node_4_ = new TreeNode(4);
    TreeNode *node_4__ = new TreeNode(4);
    node_1->left = node_2;
    node_1->right = node_3;
    node_2->left = node_4;
    node_3->left = node_2_;
    node_3->right = node_4_;
    node_2_->left = node_4__;

    nodes = solution.findDuplicateSubtrees(node_1);
    for (auto node : nodes) {
        cout << node->val << endl;
    }
    
    TreeNode *root = generateTreeByLevel({0,0,0,0,INT_MAX,INT_MAX,0,INT_MAX,INT_MAX,INT_MAX,0});
    nodes = solution.findDuplicateSubtrees(root);
    for (auto node : nodes) {
        cout << node->val << endl;
    }

    return 0;
}
//        0
//       / \
//      0   0
//     /     \
//    0       0
//             \
//              0
