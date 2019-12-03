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
func generateListNode(_ nodes: Int ...) -> ListNode? {
    let head = ListNode(0)
    var p = head
    for node in nodes {
        p.next = ListNode(node)
        p = p.next!
    }
    return head.next
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
//    print(arr.joined(separator: "->"))
    print(arr)
}

/// 21-合并两个有序链表
func test_21() {
    /**
     输入：1->2->4, 1->3->4
     输出：1->1->2->3->4->4
     */
    let node1 = generateListNode(1, 2, 4)
    let node2 = generateListNode(1, 3, 4)
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
    let node1 = generateListNode(1, 4, 5)
    let node2 = generateListNode(1, 3, 4)
    let node3 = generateListNode(2, 6)
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
    let node1 = generateListNode(4, 5, 1, 9)
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
    var node = generateListNode(1, 2, 3, 4, 5)
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
    var node = generateListNode(3, 2, 0, -4)
    node?.next?.next?.next?.next = node?.next
    let solution = _141_环形链表()
    print(solution.hasCycle(node!))
    node = generateListNode(1, 2)
    node?.next?.next = node
    print(solution.hasCycle(node!))
    node = generateListNode(1)
    print(solution.hasCycle(node!))
}

/// 203-移除链表元素
func test_203() {
    /**
     输入: 1->2->6->3->4->5->6, val = 6
     输出: 1->2->3->4->5
     */
    var node = generateListNode(1, 2, 6, 3, 4, 5, 6)
    let solution = _203_移除链表元素()
    node = solution.removeElements(node, 6)
    printListNode(node)
}


/// 83-删除排序链表中的重复元素
func test_83() {
    /**
     示例 1:
     输入: 1->1->2
     输出: 1->2
     
     示例 2:
     输入: 1->1->2->3->3
     输出: 1->2->3
     */
    let node = generateListNode(1)
    let solution = _83_删除排序链表中的重复元素()
    printListNode(solution.deleteDuplicates(node))
}

func test_876() {
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
    let node = generateListNode(1, 2, 3, 4, 5)
    let solution = _876_链表的中间结点()
    print(solution.middleNode(node)!.val)
}

// MARK: 栈

/// 150-逆波兰表达式求值
func test_150() {
    let solution = _150_逆波兰表达式求值()
    print(solution.evalRPN(["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]))
}

/// 20-有效的括号
func test_20() {
    /**
     输入: "()"
     输出: true
     
     输入: "()[]{}"
     输出: true
     
     输入: "(]"
     输出: false
     
     输入: "([)]"
     输出: false
     
     输入: "{[]}"
     输出: true
     */
    let solution = _20_有效的括号()
    print(solution.isValid("{[]}"))
}

/// 856-括号的分数
func test_856() {
    /**
    () 得 1 分。
    AB 得 A + B 分，其中 A 和 B 是平衡括号字符串。
    (A) 得 2 * A 分，其中 A 是平衡括号字符串。
    
    输入： "()"
    输出： 1
    
    输入： "(())"
    输出： 2
    
    输入： "()()"
    输出： 2
    
    输入： "(()(()))"
    输出： 6
     */
    let solution = _856_括号的分数()
    print(solution.scoreOfParentheses("(()(()))"))
}

/// 225-用队列实现栈
func test_225() {
    /**
     let obj = MyStack()
     obj.push(x)
     let ret_2: Int = obj.pop()
     let ret_3: Int = obj.top()
     let ret_4: Bool = obj.empty()
     */
    let obj = _225_用队列实现栈()
    obj.push(1)
    let ret_2: Int = obj.pop()
    let ret_3: Int = obj.top()
    let ret_4: Bool = obj.empty()
    print(ret_2, ret_3, ret_4)
}

/// 232-用栈实现队列
func test_232() {
    /**
     let obj = MyQueue()
     obj.push(x)
     let ret_2: Int = obj.pop()
     let ret_3: Int = obj.peek()
     let ret_4: Bool = obj.empty()
     */
    let obj = _232_用栈实现队列()
    obj.push(1)
//    obj.push(2)
    let ret_2: Int = obj.pop()
    let ret_3: Int = obj.peek()
    let ret_4: Bool = obj.empty()
    print(ret_2, ret_3, ret_4)
    for i in 0..<5 {
        obj.push(i)
    }
    while !obj.empty() {
        print(obj.pop(), separator: " ", terminator: "")
    }
    print()
}

/// 224-基本计算器
func test_224() {
    /**
    输入: "1 + 1"
    输出: 2
    
    输入: " 2-1 + 2 "
    输出: 3
    
    输入: "(1+(4+5+2)-3)+(6+8)"
    输出: 23
     */
    let solution = _224_基本计算器()
    print(solution.calculate("1 + 1"))
    print(solution.calculate(" 2-1 + 2 "))
    print(solution.calculate("(1+(4+5+2)-3)+(6+8)"))
    print(solution.calculate("2-(5-6)"))
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
test_224()

