/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        size_t size = lists.size();
        if (size == 0) return nullptr;
        
        int step = 1;
        while (step < size) {
            int nextStep = step << 1;
            for (int i = 0; i + step < size; i += nextStep) {
                lists[i] = mergeTwoLists(lists[i], lists[i + step]);
            }
            step = nextStep;
        }
        
        return lists[0];
    }
    
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
    
    vector<ListNode*> lists;
    ListNode *node;
    vector<int> res;
    
    /**
     输入：lists = [[1,4,5],[1,3,4],[2,6]]
     输出：[1,1,2,3,4,4,5,6]
     解释：链表数组如下：
     [
       1->4->5,
       1->3->4,
       2->6
     ]
     将它们合并到一个有序链表中得到。
     1->1->2->3->4->4->5->6
     */
    lists = {
        creatNodeList({1,4,5}),
        creatNodeList({1,3,4}),
        creatNodeList({2,6}),
    };
    res = {1,1,2,3,4,4,5,6};
    node = Solution().mergeKLists(lists);
    assert(res == getNodeList(node));
    
    /**
     输入：lists = []
     输出：[]
     */
    lists = {
    };
    res = {};
    node = Solution().mergeKLists(lists);
    assert(res == getNodeList(node));
    
    /**
     输入：lists = [[]]
     输出：[]
     */
    lists = {
        {}
    };
    res = {};
    node = Solution().mergeKLists(lists);
    assert(res == getNodeList(node));
    
    cout << "OK~" << endl;
    
    return 0;
}
