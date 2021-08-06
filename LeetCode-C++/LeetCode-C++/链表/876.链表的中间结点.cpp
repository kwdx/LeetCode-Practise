//
//  876.链表的中间结点.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/2.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/middle-of-the-linked-list/

#include <stdio.h>
#include "ListNode.hpp"

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slowNode = head;
        ListNode* fastNode = head->next;
        while (fastNode && fastNode->next) {
            fastNode = fastNode->next->next;
            slowNode = slowNode->next;
        }
        return fastNode ? slowNode->next : slowNode;
    }
};

/**
 输入：[1,2,3,4,5]
 输出：此列表中的结点 3 (序列化形式：[3,4,5])
 返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
 注意，我们返回了一个 ListNode 类型的对象 ans，这样：
 ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.

 输入：[1,2,3,4,5,6]
 输出：此列表中的结点 4 (序列化形式：[4,5,6])
 由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
*/
/**
int main(int argc, const char * argv[]) {
    ListNode *node1 = creatNodeList({1, 2, 3, 4, 5, 6});
    Solution solution = Solution();
    printf("%d\n", solution.middleNode(node1)->val);
    return 0;
}
*/
