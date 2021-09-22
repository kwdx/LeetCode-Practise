/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* node = head;
        while (node) {
            ++n;
            node = node->next;
        }
        int p = n / k, remain = n % k;
        vector<ListNode*> res(k, nullptr);
        node = head;
        for (int i = 0; i < k && node; ++i) {
            res[i] = node;
            int len = p + (i < remain ? 1 : 0);
            for (int j = 1; j < len; ++j) {
                node = node->next;
            }
            ListNode* next = node->next;
            node->next = nullptr;
            node = next;
        }
        return res;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    ListNode* head;
    int k;
    vector<ListNode*> res;
    vector<vector<int>> result;
    vector<vector<int>> resVals;
    
    /**
     输入：head = [1,2,3], k = 5
     输出：[[1],[2],[3],[],[]]
     解释：
     第一个元素 output[0] 为 output[0].val = 1 ，output[0].next = null 。
     最后一个元素 output[4] 为 null ，但它作为 ListNode 的字符串表示是 [] 。
     */
    head = creatNodeList({1,2,3});
    k = 5;
    resVals = {
        {1},
        {2},
        {3},
        {},
        {}
    };
    res = Solution().splitListToParts(head, k);
    result = getNodeList(res);
    for (int i = 0; i < resVals.size(); ++i) {
        assert(resVals[i] == result[i]);
    }
    
    /**
     输入：head = [1,2,3,4,5,6,7,8,9,10], k = 3
     输出：[[1,2,3,4],[5,6,7],[8,9,10]]
     解释：
     输入被分成了几个连续的部分，并且每部分的长度相差不超过 1 。前面部分的长度大于等于后面部分的长度。
     */
    head = creatNodeList({1,2,3,4,5,6,7,8,9,10});
    k = 3;
    resVals = {
        {1,2,3,4},
        {5,6,7},
        {8,9,10}
    };
    res = Solution().splitListToParts(head, k);
    result = getNodeList(res);
    for (int i = 0; i < resVals.size(); ++i) {
        assert(resVals[i] == result[i]);
    }
    
    cout << "OK~" << endl;
    
    return 0;
}
