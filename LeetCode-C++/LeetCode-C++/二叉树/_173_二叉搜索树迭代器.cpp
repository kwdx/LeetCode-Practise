//
//  _173_二叉搜索树迭代器.cpp
//  LeetCode-C++
//
//  Created by warden on 2020/2/17.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/binary-search-tree-iterator/

#include <stdio.h>
#include <stack>
#include <vector>
#include "TreeNode.hpp"

using namespace std;

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
 示例：
        7
       /\
      3  15
         /\
        9 20


 BSTIterator iterator = new BSTIterator(root);
 iterator.next();    // 返回 3
 iterator.next();    // 返回 7
 iterator.hasNext(); // 返回 true
 iterator.next();    // 返回 9
 iterator.hasNext(); // 返回 true
 iterator.next();    // 返回 15
 iterator.hasNext(); // 返回 true
 iterator.next();    // 返回 20
 iterator.hasNext(); // 返回 false
 */
/**
int main(int argc, const char * argv[]) {
    vector<int> nodes = {7,3,15,INT_MAX,INT_MAX,9,20};
    TreeNode *root = generateTreeByLevel(nodes);
    BSTIterator* iterator = new BSTIterator(root);
    printf("%d\n", iterator->next());   // 返回3
    printf("%d\n", iterator->next());   // 返回7
    printf("%d\n", iterator->hasNext());// 返回true
    printf("%d\n", iterator->next());   // 返回9
    printf("%d\n", iterator->hasNext());// 返回true
    printf("%d\n", iterator->next());   // 返回15
    printf("%d\n", iterator->hasNext());// 返回true
    printf("%d\n", iterator->next());   // 返回20
    printf("%d\n", iterator->hasNext());// 返回false
    return 0;
}
 */
