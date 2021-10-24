/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ListNode *l1, *l2, *l3;
    vector<int> res;
    
    /**
     输入：l1 = [2,4,3], l2 = [5,6,4]
     输出：[7,0,8]
     解释：342 + 465 = 807.
     */
    l1 = creatNodeList({2,4,3});
    l2 = creatNodeList({5,6,4});
    res = {7,0,8};
    l3 = Solution().addTwoNumbers(l1, l2);
    assert(res == getNodeList(l3));
    
    /**
     输入：l1 = [0], l2 = [0]
     输出：[0]
     */
    l1 = creatNodeList({0});
    l2 = creatNodeList({0});
    res = {0};
    l3 = Solution().addTwoNumbers(l1, l2);
    assert(res == getNodeList(l3));
    
    /**
     输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
     输出：[8,9,9,9,0,0,0,1]
     */
    l1 = creatNodeList({9,9,9,9,9,9,9});
    l2 = creatNodeList({9,9,9,9});
    res = {8,9,9,9,0,0,0,1};
    l3 = Solution().addTwoNumbers(l1, l2);
    assert(res == getNodeList(l3));

    cout << "OK~" << endl;
    
    return 0;
}
