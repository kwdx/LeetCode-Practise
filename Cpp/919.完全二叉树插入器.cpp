/*
 * @lc app=leetcode.cn id=919 lang=cpp
 *
 * [919] 完全二叉树插入器
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
class CBTInserter {
private:
    TreeNode* root;
    int n;
public:
    CBTInserter(TreeNode* root) {
        n = 0;
        this->root = root;
        TreeNode* node = root;
        queue<TreeNode*> q;
        if (node != nullptr) {
            q.emplace(node);
        }
        while (!q.empty()) {
            node = q.front();
            q.pop();
            n += 1;
            if (node->left) {
                q.emplace(node->left);
            }
            if (node->right) {
                q.emplace(node->right);
            }
        }
    }
    
    int insert(int val) {
        TreeNode* node = root;
        int idx = ++n;
        int index = idx, bits = 0;
        while (index) {
            ++bits;
            index >>= 1;
        }
        --bits;
        while (--bits > 0) {
            if (idx & (1 << bits))
                node = node->right;
            else
                node = node->left;
        }
        if (idx & 1)
            node->right = new TreeNode(val);
        else
            node->left = new TreeNode(val);
        return node->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     输入
     ["CBTInserter", "insert", "insert", "get_root"]
     [[[1, 2]], [3], [4], []]
     输出
     [null, 1, 2, [1, 2, 3, 4]]

     解释
     CBTInserter cBTInserter = new CBTInserter([1, 2]);
     cBTInserter.insert(3);  // 返回 1
     cBTInserter.insert(4);  // 返回 2
     cBTInserter.get_root(); // 返回 [1, 2, 3, 4]
     */
    TreeNode* root = generateBinaryTreeByLevel({1,2});
    CBTInserter cBTInserter(root);
    assert(cBTInserter.insert(3) == 1);
    assert(cBTInserter.insert(4) == 2);
    root = cBTInserter.get_root();
    vector<int> ans = {1,2,3,4};
    assert(ans == getTreeLevel(root));
    
    cout << "OK~" << endl;
    
    return 0;
}
