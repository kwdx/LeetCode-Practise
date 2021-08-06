//
//  234.cpp
//  LeetCode-C++
//
//  Created by warden on 2021/8/3.
//  Copyright © 2021 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/palindrome-linked-list

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "ListNode.hpp"

using namespace std;

class Solution {
private:
    ListNode* reverse(ListNode* a) {
        ListNode *pre = nullptr, *cur = a, *next = a;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, * fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != nullptr) slow = slow->next;
        ListNode *right = reverse(slow);
        while (right != nullptr) {
            if (head->val != right->val) return false;
            head = head->next;
            right = right->next;
        }
        return true;
    }

};

//int main(int argc, const char * argv[]) {
//    // insert code here...
//
//    ListNode* node;
//    node = creatNodeList({1, 2});
//    // false
//    cout << Solution().isPalindrome(node) << endl;
//
//    node = creatNodeList({1, 2, 2, 1});
//    // true
//    cout << Solution().isPalindrome(node) << endl;
//
//    return 0;
//}
