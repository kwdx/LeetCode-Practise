//
//  _237_删除链表中的节点.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/27.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/delete-node-in-a-linked-list

#include <stdio.h>
#include "ListNode.hpp"

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *t = node->next;
        node->val = t->val;
        node->next = t->next;
        delete t;
    }
};

/**
 输入: head = [4,5,1,9], node = 5
 输出: [4,1,9]
 解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.

 输入: head = [4,5,1,9], node = 1
 输出: [4,5,9]
 解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
*/
/**
int main(int argc, const char * argv[]) {
    ListNode *node1 = creatNodeList({4, 5, 1, 9});
    Solution solution = Solution();
//    solution.deleteNode(node1->next);
    solution.deleteNode(node1->next->next);
    printNodeList(node1);
    return 0;
}
*/

