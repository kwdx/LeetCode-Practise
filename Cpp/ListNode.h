//
//  ListNode.h
//  Cpp
//
//  Created by warden on 2021/8/6.
//

#ifndef ListNode_hpp
#define ListNode_hpp

#include <stdio.h>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* creatNodeList(std::vector<int> nodes);
ListNode* creatCycleNodeList(std::vector<int> nodes, int pos);
std::vector<int> getNodeList(ListNode *node);
std::vector<std::vector<int>> getNodeList(std::vector<ListNode*> nodes);

void printNodeList(ListNode* node);

#endif /* ListNode_hpp */
