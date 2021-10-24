/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *t = node->next;
        node->val = t->val;
        node->next = t->next;
        delete t;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ListNode *head, *node;
    vector<int> res;
    
    /**
     输入：head = [4,5,1,9], node = 5
     输出：[4,1,9]
     解释：给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
     */
    head = creatNodeList({4,5,1,9});
    node = head->next;
    res = {4,1,9};
    Solution().deleteNode(node);
    assert(res == getNodeList(head));
    
    /**
     输入：head = [4,5,1,9], node = 1
     输出：[4,5,9]
     解释：给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
     */
    head = creatNodeList({4,5,1,9});
    node = head->next->next;
    res = {4,5,9};
    Solution().deleteNode(node);
    assert(res == getNodeList(head));
    
    cout << "OK~" << endl;
    
    return 0;
}
