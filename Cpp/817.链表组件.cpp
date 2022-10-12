/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] 链表组件
 */

#include <iostream>
#include <unordered_set>
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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> sets;
        for (int num : nums) {
            sets.emplace(num);
        }
        int ans = 0, cur = 0;
        while (head != nullptr) {
            if (sets.count(head->val)) {
                cur += 1;
            } else {
                ans += cur > 0 ? 1 : 0;
                cur = 0;
            }
            head = head->next;
        }
        return cur > 0 ? ans + 1 : ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ListNode* head;
    vector<int> nums;
    int res;
    
    /**
     输入: head = [0,1,2,3], nums = [0,1,3]
     输出: 2
     解释: 链表中,0 和 1 是相连接的，且 nums 中不包含 2，所以 [0, 1] 是 nums 的一个组件，同理 [3] 也是一个组件，故返回 2。
     */
    head = creatNodeList({0,1,2,3});
    nums = {0,1,3};
    res = 2;
    assert(res == Solution().numComponents(head, nums));
    
    /**
     输入: head = [0,1,2,3,4], nums = [0,3,1,4]
     输出: 2
     解释: 链表中，0 和 1 是相连接的，3 和 4 是相连接的，所以 [0, 1] 和 [3, 4] 是两个组件，故返回 2。

     */
    head = creatNodeList({0,1,2,3,4});
    nums = {0,3,1,4};
    res = 2;
    assert(res == Solution().numComponents(head, nums));

    cout << "OK~" << endl;
    
    return 0;
}

