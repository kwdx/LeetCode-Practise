/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
private:
    ListNode* reverseBetween(ListNode* left, ListNode* right) {
        if (left == nullptr) return nullptr;

        ListNode *prev = nullptr, *cur = left, *next = left;
        while (cur != right) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return head;
        ListNode *left = head, *right = head;
        for (int i = 0; i < k; i++) {
            if (right == nullptr) return head;
            right = right->next;
        }
        ListNode *newHead = reverseBetween(left, right);
        head->next = reverseKGroup(right, k);
        return newHead;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...

    vector<int> nodes;
    ListNode *head;
    ListNode *reversedNode;
    
    nodes = {1,2,3,4,5};
    head = creatNodeList(nodes);
    reversedNode = Solution().reverseKGroup(head, 2);
    // 2,1,4,3,5
    printNodeList(reversedNode);

    nodes = {1,2,3,4,5};
    head = creatNodeList(nodes);
    reversedNode = Solution().reverseKGroup(head, 3);
    // 3,2,1,4,5
    printNodeList(reversedNode);
    
    nodes = {1,2,3,4,5};
    head = creatNodeList(nodes);
    reversedNode = Solution().reverseKGroup(head, 1);
    // 1,2,3,4,5
    printNodeList(reversedNode);
    
    nodes = {1};
    head = creatNodeList(nodes);
    reversedNode = Solution().reverseKGroup(head, 1);
    // 1
    printNodeList(reversedNode);

    return 0;
}
