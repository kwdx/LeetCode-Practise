//
//  _141_环形链表.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/29.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_141_环形链表.hpp"

bool _141_环形链表::hasCycle(ListNode *head) {
    if (!head) {
        return false;
    }
    ListNode* slowNode = head;
    ListNode* fastNode = head->next;
    while (fastNode && fastNode->next) {
        if (slowNode == fastNode) {
            return true;
        }
        slowNode = slowNode->next;
        fastNode = fastNode->next->next;
    }
    return false;
}
