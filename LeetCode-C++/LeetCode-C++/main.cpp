//
//  main.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//

#include <iostream>
#include <queue>
#include "_509_斐波那契数.hpp"
#include "_21_合并两个有序链表.hpp"
#include "_23_合并K个排序链表.hpp"
#include "_150_逆波兰表达式求值.hpp"
#include "_98_验证二叉搜索树.hpp"
#include "_124_二叉树中的最大路径和.hpp"
#include "_114_二叉树展开为链表.hpp"
#include "_198_打家劫舍.hpp"
#include "_36_有效的数独.hpp"
#include "_347_前K个高频元素.hpp"
#include "_237_删除链表中的节点.hpp"
#include "_206_反转链表.hpp"
#include "_88_合并两个有序数组.hpp"
#include "_141_环形链表.hpp"
#include "_203_移除链表元素.hpp"

using namespace std;

#pragma mark - 数组

/// 509-斐波那契数
void test_509() {
    /**
     输入：2
     输出：1
     解释：F(2) = F(1) + F(0) = 1 + 0 = 1.
     
     输入：3
     输出：2
     解释：F(3) = F(2) + F(1) = 1 + 1 = 2.
     
     输入：4
     输出：3
     解释：F(4) = F(3) + F(2) = 2 + 1 = 3.
     */
    _509_斐波那契数 solution = _509_斐波那契数();
    cout << solution.fib(0) << endl;
    cout << solution.fib(1) << endl;
    cout << solution.fib(2) << endl;
    cout << solution.fib(3) << endl;
    cout << solution.fib(4) << endl;
    cout << solution.fib(5) << endl;
    cout << solution.fib(6) << endl;
    cout << solution.fib(7) << endl;
}

/// 88-合并两个有序数组
void test_88() {
    /**
     输入:
     nums1 = [1,2,3,0,0,0], m = 3
     nums2 = [2,5,6],       n = 3

     输出: [1,2,2,3,5,6]
     */
    _88_合并两个有序数组 solution = _88_合并两个有序数组();
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    solution.merge(nums1, 3, nums2, 3);
    for (int num: nums1) {
        cout << num << " ";
    }
    cout << endl;

    nums1 = {1, 2, 4, 5, 6, 0};
    nums2 = {3};
    solution.merge(nums1, 5, nums2, 1);
    for (int num: nums1) {
        cout << num << " ";
    }
    cout << endl;

    nums1 = {2, 0};
    nums2 = {1};
    solution.merge(nums1, 1, nums2, 1);
    for (int num: nums1) {
        cout << num << " ";
    }
    cout << endl;
}

#pragma mark - 链表

ListNode* creatNodeList(vector<int> nodes) {
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    for (int node:nodes) {
        p->next = new ListNode(node);
        p = p->next;
    }
    return head->next;
}

void printNodeList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val;
        node = node->next;
        if (node != nullptr) {
            cout << "->";
        }
    }
    cout << endl;
}

/// 21-合并两个有序链表
void test_21() {
    // 1->2->4, 1->3->4
    ListNode* node1 = creatNodeList({1, 2, 4});
    ListNode* node2 = creatNodeList({1, 3, 4});

    _21_合并两个有序链表 solution = _21_合并两个有序链表();
    ListNode *result = solution.mergeTwoLists(node1, node2);
    printNodeList(result);
}

/// 23-合并K个有序链表
void test_23() {
    /**
     [
        1->4->5,
        1->3->4,
        2->6
     ]
     */
    ListNode *node1 = creatNodeList({1, 4, 5});
    ListNode *node2 = creatNodeList({1, 3, 4});
    ListNode *node3 = creatNodeList({2, 6});
    
    _23_合并K个排序链表 solution = _23_合并K个排序链表();
    vector<ListNode *> tokens = {node1, node2, node3};
    ListNode *result = solution.mergeKLists(tokens);
    printNodeList(result);
}

/// 237-删除链表中的节点
void test_237() {
    /**
     输入: head = [4,5,1,9], node = 5
     输出: [4,1,9]
     解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.

     输入: head = [4,5,1,9], node = 1
     输出: [4,5,9]
     解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
     */

    ListNode *node1 = creatNodeList({4, 5, 1, 9});
    _237_删除链表中的节点 solution = _237_删除链表中的节点();
//    solution.deleteNode(node1->next);
    solution.deleteNode(node1->next->next);
    printNodeList(node1);
}

/// 206-反转链表
void test_206() {
    /**
     输入: 1->2->3->4->5->NULL
     输出: 5->4->3->2->1->NULL
     */
//    ListNode *node1 = creatNodeList({1, 2, 3, 4, 5});
    ListNode *node1 = creatNodeList({5, 4, 3, 2, 1});
    _206_反转链表 solution = _206_反转链表();
    node1 = solution.reverseList(node1);
    printNodeList(node1);
}

/// 141-环形链表
void test_141() {
    /**
     输入：head = [3,2,0,-4], pos = 1
     输出：true
     解释：链表中有一个环，其尾部连接到第二个节点。
     
     输入：head = [1,2], pos = 0
     输出：true
     解释：链表中有一个环，其尾部连接到第一个节点。
     
     输入：head = [1], pos = -1
     输出：false
     解释：链表中没有环。
     */
    ListNode* node1 = creatNodeList({3, 2, 0, -4});
    node1->next->next->next->next = node1->next;
//    ListNode* node1 = creatNodeList({1, 2});
//    node1->next->next = node1;
//    ListNode* node1 = creatNodeList({1});
    _141_环形链表 solution = _141_环形链表();
    cout << solution.hasCycle(node1) << endl;
}

/// 203-移除链表元素
void test_203() {
    /**
     输入: 1->2->6->3->4->5->6, val = 6
     输出: 1->2->3->4->5
     */
    ListNode *node1 = creatNodeList({1, 2, 6, 3, 4, 5, 6});
    _203_移除链表元素 solution = _203_移除链表元素();
    node1 = solution.removeElements(node1, 6);
    printNodeList(node1);
}

#pragma mark - 栈

/// 150-逆波兰表达式求值
void test_150() {
//    vector<string> tokens = {"2", "1", "+", "3", "*"};
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    _150_逆波兰表达式求值 solution = _150_逆波兰表达式求值();
    cout << solution.evalRPN(tokens) << endl;
}

#pragma mark - 二叉树

/// 创建二叉搜索树
TreeNode* generageTree(vector<int> trees) {
    if (trees.size() == 0) return nullptr;
    TreeNode *root = new TreeNode(trees[0]);
    for (int i = 1; i < trees.size(); i++) {
        int value = trees[i];
        TreeNode *parent = root;
        TreeNode *node = root;
        do {
            parent = node;
            if (value < node->val) {
                node = node->left;
            } else {
                node = node->right;
            }
        } while (node != nullptr);
        
        if (value < parent->val) {
            parent->left = new TreeNode(value);
        } else {
            parent->right = new TreeNode(value);
        }
    }
    return root;
}

/// 98-验证二叉搜索树
void test_98() {
    TreeNode* root = generageTree({2, 1, 3});
    _98_验证二叉搜索树 solution = _98_验证二叉搜索树();
    cout << solution.isValidBST(root) << endl;
}

/// 114-二叉树展开为链表
void test_114() {
    /**
    输入：
           1
           / \
          2   5
          / \    \
         3   4    6
    输出：
      1
       \
        2
         \
          3
           \
            4
             \
              5
               \
                6
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    
    _114_二叉树展开为链表 solution = _114_二叉树展开为链表();
    solution.flatten(root);
    while (root != nullptr) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

/// 124-二叉树中的最大路径和
void test_124() {
//    TreeNode* root = new TreeNode(-10);
//    root->left = new TreeNode(9);
//    TreeNode *right = new TreeNode(20);
//    root->right = right;
//    right->left = new TreeNode(15);
//    right->right = new TreeNode(7);
    
//    TreeNode* root = new TreeNode(3);
//    root->left = new TreeNode(-1);
//    root->right = new TreeNode(-1);
    
    TreeNode* root = generageTree({10, 9, 20, 15, 35});
    
    _124_二叉树中的最大路径和 solution = _124_二叉树中的最大路径和();
    cout << solution.maxPathSum(root) << endl;
}

#pragma mark - 动态规划

/// 198-打家劫舍
void test_198() {
    /**
     输入: [1,2,3,1]
     输出: 4
     
     输入: [2,7,9,3,1]
     输出: 12
     */
    _198_打家劫舍 solution = _198_打家劫舍();
//    vector<int> nums = {1, 2, 3, 1};
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << solution.rob(nums) << endl;
}

#pragma mark - 哈希

/// 36-有效的数独
void test_36() {
    /**
    输入:
    [
      ["5","3",".",".","7",".",".",".","."],
      ["6",".",".","1","9","5",".",".","."],
      [".","9","8",".",".",".",".","6","."],
      ["8",".",".",".","6",".",".",".","3"],
      ["4",".",".","8",".","3",".",".","1"],
      ["7",".",".",".","2",".",".",".","6"],
      [".","6",".",".",".",".","2","8","."],
      [".",".",".","4","1","9",".",".","5"],
      [".",".",".",".","8",".",".","7","9"]
    ]
    输出: true

    输入:
    [
      ["8","3",".",".","7",".",".",".","."],
      ["6",".",".","1","9","5",".",".","."],
      [".","9","8",".",".",".",".","6","."],
      ["8",".",".",".","6",".",".",".","3"],
      ["4",".",".","8",".","3",".",".","1"],
      ["7",".",".",".","2",".",".",".","6"],
      [".","6",".",".",".",".","2","8","."],
      [".",".",".","4","1","9",".",".","5"],
      [".",".",".",".","8",".",".","7","9"]
    ]
    输出: false
    */
    _36_有效的数独 solution = _36_有效的数独();
//    vector<vector<char>> board = {
//        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
//        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
//        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
//        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
//        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
//        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
//        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
//        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
//        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
//    };
    vector<vector<char>> board = {
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    cout << solution.isValidSudoku(board) << endl;

}

#pragma mark - 堆

/// 347-前K个高频元素
void test_347() {
    /**
     输入: nums = [1,1,1,2,2,3], k = 2
     输出: [1,2]
     
     输入: nums = [1], k = 1
     输出: [1]
     */
//    vector<int> nums = {1, 1, 1, 2, 2, 3};
//    vector<int> nums = {1};
    vector<int> nums = {3, 1, 2, 1, 3, 2, 1, 3};

    _347_前K个高频元素 solution = _347_前K个高频元素();
    vector<int> result = solution.topKFrequent(nums, 2);
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;
}

#pragma mark - Test

int main(int argc, const char * argv[]) {
    // insert code here...
//    cout << "Hello, World!\n";
    
    test_203();
    
    return 0;
}
