/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* vNode = new ListNode(0, head);
        
        ListNode* slow = vNode;
        ListNode* fast = vNode;
        while (n--) {
            fast = fast->next;
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return vNode->next;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> nums, res;
    int n;
    ListNode* node = nullptr;
    
    /**
     输入：head = [1,2,3,4,5], n = 2
     输出：[1,2,3,5]
     */
    nums = {1,2,3,4,5};
    n = 2;
    res = {1,2,3,5};
    node = creatNodeList(nums);
    node = Solution().removeNthFromEnd(node, n);
    cout << (res == getNodeList(node)) << endl;
    
    /**
     输入：head = [1], n = 1
     输出：[]
     */
    nums = {1};
    n = 1;
    res = {};
    node = creatNodeList(nums);
    node = Solution().removeNthFromEnd(node, n);
    cout << (res == getNodeList(node)) << endl;
    
    /**
     输入：head = [1,2], n = 1
     输出：[1]
     */
    nums = {1,2};
    n = 1;
    res = {1};
    node = creatNodeList(nums);
    node = Solution().removeNthFromEnd(node, n);
    cout << (res == getNodeList(node)) << endl;
    
    return 0;
}
