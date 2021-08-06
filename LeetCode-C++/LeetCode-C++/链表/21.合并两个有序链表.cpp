//
//  21.合并两个有序链表.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/merge-two-sorted-lists

#include <stdio.h>
#include "ListNode.hpp"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
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
};

/**
 输入：1->2->4, 1->3->4
 输出：1->1->2->3->4->4
 */
/**
int main(int argc, const char * argv[]) {
    ListNode* node1 = creatNodeList({1, 2, 4});
    ListNode* node2 = creatNodeList({1, 3, 4});

    Solution solution = Solution();
    ListNode *result = solution.mergeTwoLists(node1, node2);
    printNodeList(result);
    
    return 0;
}
*/
