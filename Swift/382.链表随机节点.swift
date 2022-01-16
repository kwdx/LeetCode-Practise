/*
 * @lc app=leetcode.cn id=382 lang=swift
 *
 * [382] 链表随机节点
 */

import Darwin

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init() { self.val = 0; self.next = nil; }
 *     public init(_ val: Int) { self.val = val; self.next = nil; }
 *     public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
 * }
 */

class Solution {
    
    private let head: ListNode?

    init(_ head: ListNode?) {
        self.head = head
    }
    
    func getRandom() -> Int {
        var ans = 0, idx = 0
        var node = head
        while let n = node {
            idx += 1
            if (Int.random(in: 0..<10^4) % idx == 0) {
                ans = n.val
            }
            node = n.next
        }
        return ans
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution(head)
 * let ret_1: Int = obj.getRandom()
 */
// @lc code=end

func main() {
    var head: ListNode?
    
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
    head = generateListNode([1,2,3])
    let solution = Solution(head);
    print(solution.getRandom())
    print(solution.getRandom())
    print(solution.getRandom())
    print(solution.getRandom())
    print(solution.getRandom())
}
