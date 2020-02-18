//
//  _203_移除链表元素.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/29.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/remove-linked-list-elements/

#include <stdio.h>
#include "ListNode.hpp"

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *virtualHead = new ListNode(0);
        virtualHead->next = head;
        ListNode *node = virtualHead;
        while (node->next) {
            if (node->next->val == val) {
                ListNode *deleteNode = node->next;
                node->next = node->next->next;
                delete deleteNode;
            } else {
                node = node->next;
            }
        }
        return virtualHead->next;
    }
};

/**
输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
*/
/**
int main(int argc, const char * argv[]) {
    ListNode *node1 = creatNodeList({1, 2, 6, 3, 4, 5, 6});
    Solution solution = Solution();
    node1 = solution.removeElements(node1, 6);
    printNodeList(node1);
    return 0;
}
*/
