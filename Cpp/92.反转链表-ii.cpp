/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

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
private:
    ListNode* successor;
    
    ListNode* reverseNode(ListNode* head, int m) {
        if (m == 1) {
            successor = head->next;
            return head;
        }
        ListNode* last = reverseNode(head->next, m - 1);
        head->next->next = head;
        head->next = successor;
        return last;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == 1) {
            return reverseNode(head, right);
        }

        head->next = reverseBetween(head->next, left - 1, right - 1);

        return head;
    }
};
// @lc code=end

 int main(int argc, const char * argv[]) {
     // insert code here...

     vector<int> nodes = {1,2,3,4,5};
     ListNode *head = creatNodeList(nodes);
     ListNode *reversedNode = Solution().reverseBetween(head, 2, 4);
     // 1, 4, 3, 2, 5
     printNodeList(reversedNode);

     nodes = {5};
     head = creatNodeList(nodes);
     reversedNode = Solution().reverseBetween(head, 1, 1);
     // 5
     printNodeList(reversedNode);

     return 0;
 }
