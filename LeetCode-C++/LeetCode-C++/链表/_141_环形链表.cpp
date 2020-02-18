//
//  _141_环形链表.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/29.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/linked-list-cycle/

#include <stdio.h>
#include "ListNode.hpp"

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }
        ListNode* slowNode = head;
        ListNode* fastNode = head->next;
        while (fastNode && fastNode->next) {
            if (slowNode == fastNode) {
                return true;
            }
            slowNode = slowNode->next;
            fastNode = fastNode->next->next;
        }
        return false;
    }
};

/**
输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。

输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。

输入：head = [1], pos = -1
输出：false
解释：链表中没有环。
*/
/**
int main(int argc, const char * argv[]) {
    ListNode* node1 = creatNodeList({3, 2, 0, -4});
    node1->next->next->next->next = node1->next;
//    ListNode* node1 = creatNodeList({1, 2});
//    node1->next->next = node1;
//    ListNode* node1 = creatNodeList({1});
    Solution solution = Solution();
    printf("%d\n", solution.hasCycle(node1));
    return 0;
}
*/
