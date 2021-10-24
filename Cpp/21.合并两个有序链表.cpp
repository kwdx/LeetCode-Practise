/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

#include <iostream>
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        
        // 虚拟头节点
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1 ? l1 : l2;
        return head->next;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ListNode *l1, *l2, *l3;
    vector<int> res;
    
    /**
     输入：l1 = [1,2,4], l2 = [1,3,4]
     输出：[1,1,2,3,4,4]
     */
    l1 = creatNodeList({1,2,4});
    l2 = creatNodeList({1,3,4});
    res = {1,1,2,3,4,4};
    l3 = Solution().mergeTwoLists(l1, l2);
    assert(res == getNodeList(l3));
    
    /**
     输入：l1 = [], l2 = []
     输出：[]
     */
    l1 = creatNodeList({});
    l2 = creatNodeList({});
    res = {};
    l3 = Solution().mergeTwoLists(l1, l2);
    assert(res == getNodeList(l3));
    
    /**
     输入：l1 = [], l2 = [0]
     输出：[0]
     */
    l1 = creatNodeList({});
    l2 = creatNodeList({0});
    res = {0};
    l3 = Solution().mergeTwoLists(l1, l2);
    assert(res == getNodeList(l3));
    
    cout << "OK~" << endl;
    
    return 0;
}
