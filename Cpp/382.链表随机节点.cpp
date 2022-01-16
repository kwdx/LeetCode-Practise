/*
 * @lc app=leetcode.cn id=382 lang=cpp
 *
 * [382] 链表随机节点
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
private:
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        int ans = 0, idx = 0;
        ListNode* node = head;
        while (node != NULL) {
            ++idx;
            if (rand() % idx == 0) {
                ans = node->val;
            }
            node = node->next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ListNode* head;
    
    /**
     输入
     ["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
     [[[1, 2, 3]], [], [], [], [], []]
     输出
     [null, 1, 3, 2, 2, 3]

     解释
     Solution solution = new Solution([1, 2, 3]);
     solution.getRandom(); // 返回 1
     solution.getRandom(); // 返回 3
     solution.getRandom(); // 返回 2
     solution.getRandom(); // 返回 2
     solution.getRandom(); // 返回 3
     // getRandom() 方法应随机返回 1、2、3中的一个，每个元素被返回的概率相等。
     */
    head = creatNodeList({1,2,3});
    Solution* solution = new Solution(head);
    cout << solution->getRandom() << endl;
    cout << solution->getRandom() << endl;
    cout << solution->getRandom() << endl;
    cout << solution->getRandom() << endl;
    cout << solution->getRandom() << endl;
    
    cout << "OK~" << endl;

    return 0;
}
