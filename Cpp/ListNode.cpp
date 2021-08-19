//
//  ListNode.cpp
//  Cpp
//
//  Created by warden on 2021/8/6.
//

#include "ListNode.h"

ListNode* creatNodeList(std::vector<int> nodes) {
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    for (int node:nodes) {
        p->next = new ListNode(node);
        p = p->next;
    }
    p = head->next;
    delete head;
    return p;
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

