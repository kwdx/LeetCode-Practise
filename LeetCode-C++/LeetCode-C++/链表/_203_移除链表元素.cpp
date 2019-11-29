//
//  _203_移除链表元素.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/29.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_203_移除链表元素.hpp"

ListNode* _203_移除链表元素::removeElements(ListNode* head, int val) {
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
