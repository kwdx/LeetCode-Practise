//
//  _237_删除链表中的节点.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/27.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_237_删除链表中的节点.hpp"

void _237_删除链表中的节点::deleteNode(ListNode* node) {
    ListNode *t = node->next;
    node->val = t->val;
    node->next = t->next;
    delete t;
}
