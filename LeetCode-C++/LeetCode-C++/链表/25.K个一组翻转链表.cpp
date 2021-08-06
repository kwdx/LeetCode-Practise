//
//  25.K个一组翻转链表.cpp
//  LeetCode-C++
//
//  Created by warden on 2021/8/3.
//  Copyright © 2021 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/reverse-nodes-in-k-group/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "ListNode.hpp"

using namespace std;

class Solution {
private:

public:
    ListNode* reverseBetween(ListNode* a, ListNode* b) {
        ListNode *pre = nullptr, *cur = a, *next = a;
        while (cur != b) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        ListNode* a = head, * b = head;
        for (int i = 0; i < k; i++) {
            if (b == nullptr) return head;
            b = b->next;
        }
        ListNode* newHead = reverseBetween(a, b);
        head->next = reverseKGroup(b, k);
        return newHead;
    }

};

//int main(int argc, const char * argv[]) {
//    // insert code here...
//
//    vector<int> nodes = {1,2,3,4,5};
//    ListNode *head = creatNodeList(nodes);
//    ListNode *reversedNode = Solution().reverseKGroup(head, 2);
//    // 2,1,4,3,5
//    printNodeList(reversedNode);
//
//    nodes = {1,2,3,4,5};
//    head = creatNodeList(nodes);
//    reversedNode = Solution().reverseKGroup(head, 3);
//    // 3,2,1,4,5
//    printNodeList(reversedNode);
//
//    nodes = {1,2,3,4,5};
//    head = creatNodeList(nodes);
//    reversedNode = Solution().reverseKGroup(head, 1);
//    // 1,2,3,4,5
//    printNodeList(reversedNode);
//
//    nodes = {1};
//    head = creatNodeList(nodes);
//    reversedNode = Solution().reverseKGroup(head, 1);
//    // 1,2,3,4,5
//    printNodeList(reversedNode);
//
//    return 0;
//}
