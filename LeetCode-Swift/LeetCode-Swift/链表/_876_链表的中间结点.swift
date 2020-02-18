//
//  _876_链表的中间结点.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/12/2.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/middle-of-the-linked-list/

import Foundation

class _876_链表的中间结点 {
    func middleNode(_ head: ListNode?) -> ListNode? {
        var slow = head
        var fast = head?.next
        while fast != nil && fast?.next != nil {
            slow = slow?.next
            fast = fast?.next?.next
        }
        return fast != nil ? slow?.next : slow
    }
}

/**
 输入：[1,2,3,4,5]
 输出：此列表中的结点 3 (序列化形式：[3,4,5])
 返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
 注意，我们返回了一个 ListNode 类型的对象 ans，这样：
 ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.

 输入：[1,2,3,4,5,6]
 输出：此列表中的结点 4 (序列化形式：[4,5,6])
 由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
*/
func test_876() {
    let node = generateListNode(1, 2, 3, 4, 5)
    let solution = _876_链表的中间结点()
    print(solution.middleNode(node)!.val)
}
