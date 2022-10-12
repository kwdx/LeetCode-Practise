/*
 * @lc app=leetcode.cn id=817 lang=swift
 *
 * [817] 链表组件
 */

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
    func numComponents(_ head: ListNode?, _ nums: [Int]) -> Int {
        let sets = Set(nums)
        var ans = 0
        var node = head
        var cur = 0
        while node != nil {
            if sets.contains(node!.val) {
                cur += 1
            } else {
                if cur > 0 {
                    ans += 1
                }
                cur = 0
            }
            node = node?.next
        }
        if cur > 0 {
            ans += 1
        }
        return ans
    }
}
// @lc code=end

func main() {
    var head: ListNode?
    var nums: [Int]
    var res: Int
    
    /**
     输入: head = [0,1,2,3], nums = [0,1,3]
     输出: 2
     解释: 链表中,0 和 1 是相连接的，且 nums 中不包含 2，所以 [0, 1] 是 nums 的一个组件，同理 [3] 也是一个组件，故返回 2。
     */
    head = generateListNode([0,1,2,3])
    nums = [0,1,3]
    res = 2
    assert(res == Solution().numComponents(head, nums))
    
    /**
     输入: head = [0,1,2,3,4], nums = [0,3,1,4]
     输出: 2
     解释: 链表中，0 和 1 是相连接的，3 和 4 是相连接的，所以 [0, 1] 和 [3, 4] 是两个组件，故返回 2。

     */
    head = generateListNode([0,1,2,3,4])
    nums = [0,3,1,4]
    res = 2
    assert(res == Solution().numComponents(head, nums))
}
