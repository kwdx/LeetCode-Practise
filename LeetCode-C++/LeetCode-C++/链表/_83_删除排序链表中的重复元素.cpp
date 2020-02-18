//
//  _83_删除排序链表中的重复元素.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/2.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/

#include <stdio.h>
#include "ListNode.hpp"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
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
};

/**
示例 1:
输入: 1->1->2
输出: 1->2

示例 2:
输入: 1->1->2->3->3
输出: 1->2->3
*/
/**
int main(int argc, const char * argv[]) {
    ListNode *node1 = creatNodeList({1, 1, 2, 3, 3});
    Solution solution = Solution();
    node1 = solution.deleteDuplicates(node1);
    printNodeList(node1);
    return 0;
}
*/
