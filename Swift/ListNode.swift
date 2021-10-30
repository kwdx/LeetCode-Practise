//
//  ListNode.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//

import Foundation

class ListNode: Equatable {
    
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
    
    static func == (lhs: ListNode, rhs: ListNode) -> Bool {
        var n1: ListNode? = lhs
        var n2: ListNode? = rhs
        while n1 != nil && n2 != nil {
            if n1?.val != n2?.val {
                return false;
            }
            n1 = n1?.next
            n2 = n2?.next
        }
        return n1 == nil && n2 == nil;
    }
    
    var nodes: [Int] {
        var nodes_: [Int] = []
        var node: ListNode? = self
        while let n = node {
            nodes_.append(n.val)
            node = node?.next
        }
        return nodes_
    }
}

// 生成节点链表
func generateListNode(_ nodes: [Int]) -> ListNode? {
    let head = ListNode(0)
    var p = head
    for node in nodes {
        p.next = ListNode(node)
        p = p.next!
    }
    return head.next
}

// 生成节点链表
func generateListNode(_ nodes: [[Int]]) -> [ListNode?] {
    return nodes.map(generateListNode(_:))
}

// 打印节点链表
func printListNode(_ node: ListNode?) {
    if node == nil {
        return
    }
    var printNode = node;
    var arr = [String]()
    while printNode != nil {
        arr.append(String(printNode!.val))
        printNode = printNode?.next
    }
    print(arr)
}
