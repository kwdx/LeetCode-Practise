//
//  _104_二叉树的最大深度.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/11.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_104_二叉树的最大深度.hpp"
#include <queue>

using namespace std;

int _104_二叉树的最大深度::maxDepth(TreeNode* root) {
        int depth = 0;
        queue<TreeNode*> nodes;
        if (root) {
            nodes.push(root);
        }
        size_t size = 0;
        while (!nodes.empty()) {
            if (size == 0) {
                size = nodes.size();
                depth++;
            }
            TreeNode* p = nodes.front();
            nodes.pop();
            if (p->left) {
                nodes.push(p->left);
            }
            if (p->right) {
                nodes.push(p->right);
            }
            size--;
        }
        return depth;
}
