//
//  TreeNode.h
//  LeetCode-C++
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// 创建二叉搜索树
TreeNode* generateBinaryTree(std::vector<int> trees);

/// 按照层序遍历生成二叉树
TreeNode* generateTreeByLevel(std::vector<int> trees);

/// 层序遍历打印二叉树
void printTreeByLevel(TreeNode* root);

/// 获取二叉树的层序遍历结果
std::vector<int> getTreeLevel(TreeNode* root);

/// 打印向量
void printVector(std::vector<int> *nodes);

#endif /* TreeNode_hpp */
