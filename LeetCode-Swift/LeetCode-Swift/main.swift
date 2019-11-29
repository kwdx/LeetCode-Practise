//
//  main.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//

import Foundation

// MARK: 数组

/// 509-斐波那契数
func test_509() {
    /**
    输入：2
    输出：1
    解释：F(2) = F(1) + F(0) = 1 + 0 = 1.
    
    输入：3
    输出：2
    解释：F(3) = F(2) + F(1) = 1 + 1 = 2.
    
    输入：4
    输出：3
    解释：F(4) = F(3) + F(2) = 2 + 1 = 3.
    */
    let solution = _509_斐波那契数()
    print(solution.fib(0))
    print(solution.fib(1))
    print(solution.fib(2))
    print(solution.fib(3))
    print(solution.fib(4))
    print(solution.fib(5))
    print(solution.fib(6))
    print(solution.fib(7))
    print(solution.fib(8))
}

/// 88-合并两个有序数组
func test_88() {
    /**
    输入:
    nums1 = [1,2,3,0,0,0], m = 3
    nums2 = [2,5,6],       n = 3

    输出: [1,2,2,3,5,6]
    */
    let solution = _88_合并两个有序数组()
    var nums1 = [1, 2, 3, 0, 0, 0]
    var nums2 = [2, 5, 6]
    solution.merge(&nums1, 3, nums2, 3)
    print(nums1)
    
    nums1 = [1, 2, 4, 5, 6, 0]
    nums2 = [3]
    solution.merge(&nums1, 5, nums2, 1)
    print(nums1)
    
    nums1 = [2, 0]
    nums2 = [1]
    solution.merge(&nums1, 1, nums2, 1)
    print(nums1)
}

// MARK: 链表

// 生成节点链表
func generagteListNode(_ nodes: Int ...) -> ListNode? {
    let head = ListNode(0)
    var p = head
    for node in nodes {
        p.next = ListNode(node)
        p = p.next!
    }
    return head.next
}

// 生成节点链表
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
//    print(arr.joined(separator: "->"))
    print(arr)
}

/// 21-合并两个有序链表
func test_21() {
    /**
     输入：1->2->4, 1->3->4
     输出：1->1->2->3->4->4
     */
    let node1 = generagteListNode(1, 2, 4)
    let node2 = generagteListNode(1, 3, 4)
    let solution = _21_合并两个有序链表()
    let result = solution.mergeTwoLists(node1, node2)
    printListNode(result)
}

/// 23-合并K个有序链表
func test_23() {
    /**
     输入:
     [
       1->4->5,
       1->3->4,
       2->6
     ]
     输出: 1->1->2->3->4->4->5->6
     */
    let node1 = generagteListNode(1, 4, 5)
    let node2 = generagteListNode(1, 3, 4)
    let node3 = generagteListNode(2, 6)
    let solution = _23_合并K个排序链表()
    let result = solution.mergeKLists([node1, node2, node3])
    printListNode(result)
}

/// 237-删除链表中的节点
func test_237() {
    /**
     输入: head = [4,5,1,9], node = 5
     输出: [4,1,9]
     解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.

     输入: head = [4,5,1,9], node = 1
     输出: [4,5,9]
     解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
     */
    let node1 = generagteListNode(4, 5, 1, 9)
    let solution = _237_删除链表中的节点()
//    solution.deleteNode(node1!.next!)
    solution.deleteNode(node1!.next!.next!)
    printListNode(node1)
}

/// 206-反转链表
func test_206() {
    /**
     输入: 1->2->3->4->5->NULL
     输出: 5->4->3->2->1->NULL
     */
    var node = generagteListNode(1, 2, 3, 4, 5)
    let solution = _206_反转链表()
    node = solution.reverseList(node)
    printListNode(node)
}

/// 141-环形链表
func test_141() {
    /**
     输入：head = [3,2,0,-4], pos = 1
     输出：true
     解释：链表中有一个环，其尾部连接到第二个节点。
     
     输入：head = [1,2], pos = 0
     输出：true
     解释：链表中有一个环，其尾部连接到第一个节点。
     
     输入：head = [1], pos = -1
     输出：false
     解释：链表中没有环。
     */
    var node = generagteListNode(3, 2, 0, -4)
    node?.next?.next?.next?.next = node?.next
    let solution = _141_环形链表()
    print(solution.hasCycle(node!))
    node = generagteListNode(1, 2)
    node?.next?.next = node
    print(solution.hasCycle(node!))
    node = generagteListNode(1)
    print(solution.hasCycle(node!))
}

/// 203-移除链表元素
func test_203() {
    /**
     输入: 1->2->6->3->4->5->6, val = 6
     输出: 1->2->3->4->5
     */
    var node = generagteListNode(1, 2, 6, 3, 4, 5, 6)
    let solution = _203_移除链表元素()
    node = solution.removeElements(node, 6)
    printListNode(node)
}

// MARK: 栈

/// 150-逆波兰表达式求值
func test_150() {
    let solution = _150_逆波兰表达式求值()
    print(solution.evalRPN(["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]))
}

// MARK: 二叉树

// 生成二叉搜索树
func generateTree(_ nodes: [Int]) -> TreeNode? {
    if nodes.count == 0 {
        return nil;
    }
    let root = Optional(TreeNode(nodes[0]))
    for i in 1..<nodes.count {
        var parent = root
        var node = root
        while node != nil {
            parent = node
            if nodes[i] < node!.val {
                node = node!.left
            } else {
                node = node!.right
            }
        }
        
        if (nodes[i] < parent!.val) {
            parent!.left = TreeNode(nodes[i]);
        } else {
            parent!.right = TreeNode(nodes[i]);
        }
    }
    return root;
}

/// 98-验证二叉搜索树
func test_98() {
    /**
     输入:
         2
        / \
       1   3
     输出: true
     */
    let root = TreeNode(2)
    root.left = TreeNode(1)
    root.right = TreeNode(3)
    let solution = _98_验证二叉搜索树()
    print(solution.isValidBST(root))
}

/// 114-二叉树展开为链表
func test_114() {
    /**
     输入：
            1
            / \
           2   5
           / \    \
          3   4    6
     输出：
       1
        \
         2
          \
           3
            \
             4
              \
               5
                \
                 6
     */
    var root = Optional(TreeNode(1))
    root?.left = TreeNode(2)
    root?.right = TreeNode(5)
    root?.left?.left = TreeNode(3)
    root?.left?.right = TreeNode(4)
    root?.right?.right = TreeNode(6)
    
    let solution = _114_二叉树展开为链表()
    solution.flatten(root)
    var result = [String]()
    while root != nil {
        result.append(String(root!.val))
        root = root?.right
    }
//    print(result.joined(separator: "-"))
    print(result)
}

/// 124-二叉树中的最大路径和
func test_124() {
    /**
     输入: [1,2,3]

            1
           / \
          2   3

     输出: 6
     
     输入: [-10,9,20,null,null,15,7]

        -10
        / \
       9  20
         /  \
        15   7

     输出: 42
     */
    let right = TreeNode(20)
    right.left = TreeNode(15)
    right.right = TreeNode(7)
    
    let root = TreeNode(-10)
    root.left = TreeNode(9)
    root.right = right
    
    let solution = _124_二叉树中的最大路径和()
    print(solution.maxPathSum(root))
}

// MARK: 动态规划

/// 198-打家劫舍
func test_198() {
    /**
     输入: [1,2,3,1]
     输出: 4
     
     输入: [2,7,9,3,1]
     输出: 12
     */
//    let nums = [1, 2, 3, 1]
    let nums = [2, 7, 9, 3, 1]
    let solution = _198_打家劫舍()
    print(solution.rob(nums))
}

// MARK: 堆

/// 347-前K个高频元素
func test_347() {
    /**
     输入: nums = [1,1,1,2,2,3], k = 2
     输出: [1,2]
     
     输入: nums = [1], k = 1
     输出: [1]
     */
//    let nums = [1, 1, 1, 2, 2, 3]
    let nums = [3, 1, 2, 1, 3, 2, 1, 3]
    let solution = _347_前K个高频元素()
    print(solution.topKFrequent(nums, 2))
}

// MARK: 哈希

/// 36-有效的数独
func test_36() {
    /**
     输入:
     [
       ["5","3",".",".","7",".",".",".","."],
       ["6",".",".","1","9","5",".",".","."],
       [".","9","8",".",".",".",".","6","."],
       ["8",".",".",".","6",".",".",".","3"],
       ["4",".",".","8",".","3",".",".","1"],
       ["7",".",".",".","2",".",".",".","6"],
       [".","6",".",".",".",".","2","8","."],
       [".",".",".","4","1","9",".",".","5"],
       [".",".",".",".","8",".",".","7","9"]
     ]
     输出: true

     输入:
     [
       ["8","3",".",".","7",".",".",".","."],
       ["6",".",".","1","9","5",".",".","."],
       [".","9","8",".",".",".",".","6","."],
       ["8",".",".",".","6",".",".",".","3"],
       ["4",".",".","8",".","3",".",".","1"],
       ["7",".",".",".","2",".",".",".","6"],
       [".","6",".",".",".",".","2","8","."],
       [".",".",".","4","1","9",".",".","5"],
       [".",".",".",".","8",".",".","7","9"]
     ]
     输出: false
     */
    let solution = _36_有效的数独()
//    let board: [[Character]] = [
//        ["5", "3", ".", ".", "7", ".", ".", ".", "."],
//        ["6", ".", ".", "1", "9", "5", ".", ".", "."],
//        [".", "9", "8", ".", ".", ".", ".", "6", "."],
//        ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
//        ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
//        ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
//        [".", "6", ".", ".", ".", ".", "2", "8", "."],
//        [".", ".", ".", "4", "1", "9", ".", ".", "5"],
//        [".", ".", ".", ".", "8", ".", ".", "7", "9"]
//    ]
    let board: [[Character]] = [
        ["8", "3", ".", ".", "7", ".", ".", ".", "."],
        ["6", ".", ".", "1", "9", "5", ".", ".", "."],
        [".", "9", "8", ".", ".", ".", ".", "6", "."],
        ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
        ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
        ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
        [".", "6", ".", ".", ".", ".", "2", "8", "."],
        [".", ".", ".", "4", "1", "9", ".", ".", "5"],
        [".", ".", ".", ".", "8", ".", ".", "7", "9"]
    ]
    print(solution.isValidSudoku(board))
}

// MARK: Test
test_203()

