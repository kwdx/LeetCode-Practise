/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast) {
            while (fast && fast->val == slow->val) {
                fast = fast->next;
            }
            slow->next = fast;
            slow = fast;
        }

        return head;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> nums, res;
    ListNode* node;

    /**
     输入：head = [1,1,2]
     输出：[1,2]
     */
    nums = {1,1,2};
    res = {1,2};
    node = creatNodeList(nums);
    node = Solution().deleteDuplicates(node);
    assert(res == getNodeList(node));

    /**
     输入：head = [1,1,2,3,3]
     输出：[1,2,3]
     */
    nums = {1,1,2,3,3};
    res = {1,2,3};
    node = creatNodeList(nums);
    node = Solution().deleteDuplicates(node);
    assert(res == getNodeList(node));

    cout << "OK~" << endl;
    
    return 0;
}
