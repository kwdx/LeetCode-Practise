//
//  ListNode.hpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//

#ifndef ListNode_hpp
#define ListNode_hpp

#include <stdio.h>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* creatNodeList(std::vector<int> nodes);

void printNodeList(ListNode* node);

#endif /* ListNode_hpp */
