/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
// @lc code=end

