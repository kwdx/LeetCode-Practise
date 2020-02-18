//
//  ListNode.cpp
//  LeetCode-C++
//
//  Created by warden on 2020/2/18.
//  Copyright © 2020 warden. All rights reserved.
//

#include "ListNode.hpp"

ListNode* creatNodeList(std::vector<int> nodes) {
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
        printf("%d", node->val);
        node = node->next;
        if (node != nullptr) {
            printf("->");
        }
    }
    printf("\n");
}
