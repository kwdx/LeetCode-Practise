/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *node = new ListNode();
        ListNode *head = node;
        int val = 0;
        while (l1 != nullptr || l2 != nullptr)
        {
            if (l1 != nullptr) {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                val += l2->val;
                l2 = l2->next;
            }
            node->next = new ListNode(val % 10);
            val = val / 10;
            node = node->next;
        }
        if (val > 0) {
            node->next = new ListNode(val);
        }

        return head->next;
    }
};
// @lc code=end

