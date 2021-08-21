/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) break;
        }
        
        if (!fast || !fast->next) return nullptr;

        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> nums;
    int pos;
    ListNode* head;

    /**
     输入：head = [3,2,0,-4], pos = 1
     输出：返回索引为 1 的链表节点
     解释：链表中有一个环，其尾部连接到第二个节点。
     */
    nums = {3,2,0,-4};
    pos = 1;
    head = creatCycleNodeList(nums, pos);
    cout << (2 == Solution().detectCycle(head)->val) << endl;

    /**
     输入：head = [1,2], pos = 0
     输出：返回索引为 0 的链表节点
     解释：链表中有一个环，其尾部连接到第一个节点。
     */
    nums = {1,2};
    pos = 0;
    head = creatCycleNodeList(nums, pos);
    cout << (1 == Solution().detectCycle(head)->val) << endl;

    /**
     输入：head = [1], pos = -1
     输出：false
     解释：链表中没有环。
     */
    nums = {1};
    pos = -1;
    head = creatCycleNodeList(nums, pos);
    cout << (!Solution().detectCycle(head)) << endl;

    return 0;
}
