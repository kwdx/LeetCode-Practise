//
//  _876_链表的中间结点.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/2.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_876_链表的中间结点.hpp"

ListNode* _876_链表的中间结点::middleNode(ListNode* head) {
    ListNode* slowNode = head;
    ListNode* fastNode = head->next;
    while (fastNode && fastNode->next) {
        fastNode = fastNode->next->next;
        slowNode = slowNode->next;
    }
    return fastNode ? slowNode->next : slowNode;
}
