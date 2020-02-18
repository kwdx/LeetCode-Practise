//
//  _23_合并K个排序链表.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/merge-k-sorted-lists

#include <stdio.h>
#include "ListNode.hpp"
#include <vector>

using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        size_t size = lists.size();
        if (size == 0) return nullptr;
        
        int step = 1;
        while (step < size) {
            int nextStep = step << 1;
            for (int i = 0; i + step < size; i += nextStep) {
                lists[i] = mergeTwoLists(lists[i], lists[i + step]);
            }
            step = nextStep;
        }
        
        return lists[0];
    }
    
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
 输入:
 [
   1->4->5,
   1->3->4,
   2->6
 ]
 输出: 1->1->2->3->4->4->5->6
*/
/**
int main(int argc, const char * argv[]) {
    
    ListNode *node1 = creatNodeList({1, 4, 5});
    ListNode *node2 = creatNodeList({1, 3, 4});
    ListNode *node3 = creatNodeList({2, 6});
    
    Solution solution = Solution();
    vector<ListNode *> tokens = {node1, node2, node3};
    ListNode *result = solution.mergeKLists(tokens);
    printNodeList(result);
    
    return 0;
}
*/
