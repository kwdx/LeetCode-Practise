/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
 */

#include <iostream>
#include <stack>
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
class BSTIterator {
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *node = st.top();
        st.pop();
        int res = node->val;
        node = node->right;
        while (node) {
            st.push(node);
            node = node->left;
        }
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     输入
     ["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
     [[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
     输出
     [null, 3, 7, true, 9, true, 15, true, 20, false]

     解释
     BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
     bSTIterator.next();    // 返回 3
     bSTIterator.next();    // 返回 7
     bSTIterator.hasNext(); // 返回 True
     bSTIterator.next();    // 返回 9
     bSTIterator.hasNext(); // 返回 True
     bSTIterator.next();    // 返回 15
     bSTIterator.hasNext(); // 返回 True
     bSTIterator.next();    // 返回 20
     bSTIterator.hasNext(); // 返回 False
     */
    TreeNode *root = generateTreeByLevel({7,3,15,INT_MAX,INT_MAX,9,20});
    BSTIterator *bSTIterator = new BSTIterator(root);
    assert(3 == bSTIterator->next());
    assert(7 == bSTIterator->next());
    assert(bSTIterator->hasNext());
    assert(9 == bSTIterator->next());
    assert(bSTIterator->hasNext());
    assert(15 == bSTIterator->next());
    assert(bSTIterator->hasNext());
    assert(20 == bSTIterator->next());
    assert(!bSTIterator->hasNext());
        
    cout << "OK~" << endl;
    
    return 0;
}
