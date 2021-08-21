/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> nums, res;
    ListNode* node = nullptr;
    
    /**
     输入：[1,2,3,4,5]
     输出：此列表中的结点 3 (序列化形式：[3,4,5])
     返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
     注意，我们返回了一个 ListNode 类型的对象 ans，这样：
     ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.
     */
    nums = {1,2,3,4,5};
    res = {3,4,5};
    node = creatNodeList(nums);
    node = Solution().middleNode(node);
    cout << (res == getNodeList(node)) << endl;
    
    /**
     输入：[1,2,3,4,5,6]
     输出：此列表中的结点 4 (序列化形式：[4,5,6])
     由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
     */
    nums = {1,2,3,4,5,6};
    res = {4,5,6};
    node = creatNodeList(nums);
    node = Solution().middleNode(node);
    cout << (res == getNodeList(node)) << endl;
    
    return 0;
}
