//
//  _23_合并K个排序链表.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_23_合并K个排序链表.hpp"

ListNode* _23_合并K个排序链表::mergeKLists(vector<ListNode*>& lists) {
    size_t size = lists.size();
    if (size == 0) return nullptr;
    
    int step = 1;
    while (step < size) {
        int nextStep = step << 1;
        for (int i = 0; i + step < size; i += nextStep) {
            lists[i] = mergeTwoLists(lists[i], lists[i + step]);
        }
        step = nextStep;
    }
    
    return lists[0];
}

ListNode* _23_合并K个排序链表::mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;
    
    // 虚拟头节点
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    p->next = l1 ? l1 : l2;
    return head->next;
}
