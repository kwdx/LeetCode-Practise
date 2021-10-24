/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* node = head->next;
        ListNode* prev = head;
        while (head->next) {
            head->next = node->next;
            node->next = prev;
            prev = node;
            node = head->next;
        }
        head->next = nullptr;
        return prev;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> head;
    vector<int> res;
    
    /**
     输入：head = [1,2,3,4,5]
     输出：[5,4,3,2,1]
     */
    head = {1,2,3,4,5};
    res = {5,4,3,2,1};
    assert(res == getNodeList(Solution().reverseList(creatNodeList(head))));
    
    /**
     输入：head = [1,2]
     输出：[2,1]
     */
    head = {1,2};
    res = {2,1};
    assert(res == getNodeList(Solution().reverseList(creatNodeList(head))));
    
    /**
     输入：head = []
     输出：[]
     */
    head = {};
    res = {};
    assert(res == getNodeList(Solution().reverseList(creatNodeList(head))));

    cout << "OK~" << endl;
    
    return 0;
}
