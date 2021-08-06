//
//  92.反转链表II.cpp
//  LeetCode-C++
//
//  Created by warden on 2021/8/2.
//  Copyright © 2021 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/reverse-linked-list-ii/comments/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "ListNode.hpp"

using namespace std;

class Solution {
private:
    ListNode* successor = nullptr;
public:
    ListNode* reverse(ListNode* head, int m) {
        if (m == 1) {
            // 记录第 n + 1 个节点
            successor = head->next;
            return head;
        }
        // 以 head->next 为起点，需要反转前 n - 1 个节点
        ListNode* last = reverse(head->next, m - 1);
        head->next->next = head;
        // 让反转之后的 head 节点和后面的节点连起来
        head->next = successor;

        return last;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == 1) {
            return reverse(head, right);
        }
        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }
};

//int main(int argc, const char * argv[]) {
//    // insert code here...
//
//    vector<int> nodes = {1,2,3,4,5};
//    ListNode *head = creatNodeList(nodes);
//    ListNode *reversedNode = Solution().reverseBetween(head, 2, 4);
//    // 1, 4, 3, 2, 5
//    printNodeList(reversedNode);
//
//    nodes = {5};
//    head = creatNodeList(nodes);
//    reversedNode = Solution().reverseBetween(head, 1, 1);
//    // 5
//    printNodeList(reversedNode);
//
//    return 0;
//}
