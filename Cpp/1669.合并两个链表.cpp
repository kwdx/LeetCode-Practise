/*
 * @lc app=leetcode.cn id=1669 lang=cpp
 *
 * [1669] 合并两个链表
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* preNode = nullptr;
        ListNode* nextNode = list1;
        for (int i = 1; i <= b; ++i) {
            if (i == a) {
                preNode = nextNode;
            }
            nextNode = nextNode->next;
        }
        preNode->next = list2;
        while (list2->next != nullptr) {
            list2 = list2->next;
        }
        list2->next = nextNode->next;
        return list1;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ListNode* list1;
    int a;
    int b;
    ListNode* list2;
    vector<int> res;
    vector<int> res1;
    
    /**
     输入：list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
     输出：[0,1,2,1000000,1000001,1000002,5]
     解释：我们删除 list1 中下标为 3 和 4 的两个节点，并将 list2 接在该位置。上图中蓝色的边和节点为答案链表。
     */
    list1 = creatNodeList({0,1,2,3,4,5});
    a = 3;
    b = 4;
    list2 = creatNodeList({1000000,1000001,1000002});
    res = {0,1,2,1000000,1000001,1000002,5};
    res1 = getNodeList(Solution().mergeInBetween(list1, a, b, list2));
    assert(res == res1);
    
    /**
     输入：list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
     输出：[0,1,1000000,1000001,1000002,1000003,1000004,6]
     解释：上图中蓝色的边和节点为答案链表。
     */
    list1 = creatNodeList({0,1,2,3,4,5,6});
    a = 2;
    b = 5;
    list2 = creatNodeList({1000000,1000001,1000002,1000003,1000004});
    res = {0,1,1000000,1000001,1000002,1000003,1000004,6};
    res1 = getNodeList(Solution().mergeInBetween(list1, a, b, list2));
    assert(res == res1);

    cout << "OK~" << endl;
    
    return 0;
}
