/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

#include <iostream>
#include <vector>
#include "ListNode.h"
using namespace std;

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* reverse(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode *prev = nullptr, *cur = head, *next = head;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;

        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast != nullptr) {
            slow = slow->next;
        }

        ListNode *left = head, *right = reverse(slow);
        while (left != nullptr && right != nullptr) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...

    vector<int> nodes;
    ListNode *head;
    
    nodes = {1,2};
    head = creatNodeList(nodes);
    // false
    cout << Solution().isPalindrome(head) << endl;

    nodes = {1,2,2,1};
    head = creatNodeList(nodes);
    // true
    cout << Solution().isPalindrome(head) << endl;
    
    nodes = {1,3,2,3,1};
    head = creatNodeList(nodes);
    // true
    cout << Solution().isPalindrome(head) << endl;

    return 0;
}
