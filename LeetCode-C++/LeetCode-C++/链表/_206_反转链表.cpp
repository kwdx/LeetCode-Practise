//
//  _206_反转链表.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/27.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/reverse-linked-list/

#include <stdio.h>
#include "ListNode.hpp"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* node = head->next;
        ListNode* prev = head;
        while (head->next) {
            head->next = node->next;
            node->next = prev;
            prev = node;
            node = head->next;
        }
        head->next = nullptr;
        return prev;
    }
};

/**
 输入: 1->2->3->4->5->NULL
 输出: 5->4->3->2->1->NULL
 */
/**
int main(int argc, const char * argv[]) {
    //    ListNode *node1 = creatNodeList({1, 2, 3, 4, 5});
    ListNode *node1 = creatNodeList({5, 4, 3, 2, 1});
    Solution solution = Solution();
    node1 = solution.reverseList(node1);
    printNodeList(node1);
    return 0;
}
*/
