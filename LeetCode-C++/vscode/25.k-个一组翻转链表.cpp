/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

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
// @lc code=end

