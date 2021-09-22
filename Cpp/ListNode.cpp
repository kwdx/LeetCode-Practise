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

ListNode* creatCycleNodeList(std::vector<int> nodes, int pos) {
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    ListNode* cycleNode = nullptr;
    for (int node:nodes) {
        p->next = new ListNode(node);
        if (pos-- == 0) cycleNode = p->next;
        p = p->next;
    }
    p->next = cycleNode;
    p = head->next;
    
    delete head;
    return p;
}

std::vector<int> getNodeList(ListNode *node) {
    std::vector<int> res;
    while (node) {
        res.push_back(node->val);
        node = node->next;
    }
    return res;
}

std::vector<std::vector<int>> getNodeList(std::vector<ListNode*> nodes) {
    std::vector<std::vector<int>> res;
    for (ListNode *node : nodes) {
        res.push_back(getNodeList(node));
    }
    return res;
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

