/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *virtualHead = new ListNode(0);
        virtualHead->next = head;
        ListNode *node = virtualHead;
        while (node->next) {
            if (node->next->val == val) {
                ListNode *deleteNode = node->next;
                node->next = node->next->next;
                delete deleteNode;
            } else {
                node = node->next;
            }
        }
        return virtualHead->next;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> head;
    int val;
    vector<int> res;
    
    /**
     输入：head = [1,2,6,3,4,5,6], val = 6
     输出：[1,2,3,4,5]
     */
    head = {1,2,6,3,4,5,6};
    val = 6;
    res = {1,2,3,4,5};
    assert(res == getNodeList(Solution().removeElements(creatNodeList(head), val)));
    
    /**
     输入：head = [], val = 1
     输出：[]
     */
    head = {};
    val = 1;
    res = {};
    assert(res == getNodeList(Solution().removeElements(creatNodeList(head), val)));
    
    /**
     输入：head = [7,7,7,7], val = 7
     输出：[]
     */
    head = {7,7,7,7};
    val = 7;
    res = {};
    assert(res == getNodeList(Solution().removeElements(creatNodeList(head), val)));

    cout << "OK~" << endl;
    
    return 0;
}
