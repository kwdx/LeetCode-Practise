//
//  _83_删除排序链表中的重复元素.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/2.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_83_删除排序链表中的重复元素.hpp"

ListNode* _83_删除排序链表中的重复元素::deleteDuplicates(ListNode* head) {
    if (!head) {
        return nullptr;
    }
    ListNode* n = head;
    ListNode* deleteNode;
    while (n->next) {
        if (n->val == n->next->val) {
            deleteNode = n->next;
            n->next = n->next->next;
            delete deleteNode;
        } else {
            n = n->next;
        }
    }
    return head;
}

