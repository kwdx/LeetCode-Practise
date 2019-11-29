//
//  _206_反转链表.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/27.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_206_反转链表.hpp"

ListNode* _206_反转链表::reverseList(ListNode* head) {
    if (head == nullptr) {
        return head;
    }
    ListNode* node = head->next;
    ListNode* prev = head;
    while (head->next) {
        head->next = node->next;
        node->next = prev;
        prev = node;
        node = head->next;
    }
    head->next = nullptr;
    return prev;
}
