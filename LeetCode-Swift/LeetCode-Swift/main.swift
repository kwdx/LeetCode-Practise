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
func generateBinaryTree(_ nodes: [Int]) -> TreeNode? {
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

/// 按照层序遍历生成二叉树
func generateTreeByLevel(_ nodes: [Int?]) -> TreeNode? {
    guard nodes.count > 0 else {
        return nil
    }
    let root = TreeNode(nodes[0]!)
    var nodeArr = [root]
    var isLeft = true
    for i in 1..<nodes.count {
        let parent = nodeArr.first
        if nodes[i] != nil {
            let child = TreeNode(nodes[i]!)
            if isLeft {
                parent?.left = child
            } else {
                parent?.right = child
            }
            nodeArr.append(child)
        }
        if !isLeft {
            nodeArr.removeFirst()
        }
        
        isLeft = !isLeft
    }
    return root
}

/// 按照层序遍历打印二叉树
func printTreeByLevel(_ root: TreeNode?) {
    guard root != nil else {
        return
    }
    var nodes = [root]
    var vals = [Int]()
    while !nodes.isEmpty {
        let node = nodes.removeFirst()
        if node != nil {
            vals.append(node!.val)
            nodes.append(node!.left)
            nodes.append(node!.right)
        }
    }
    print(vals)
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

/// 226-翻转二叉树
func test_226() {
    /**
     输入：

          4
        /   \
       2     7
      / \   / \
     1   3 6   9
     输出：

          4
        /   \
       7     2
      / \   / \
     9   6 3   1
     */
    var root = generateTreeByLevel([4, 2, 7, 1, 3, 6, 9])
    let solution = _226_翻转二叉树()
    root = solution.invertTree(root);
    print(root!)
}

/// 144-二叉树的前序遍历
func test_144() {
    /**
    输入: [1,null,2,3]
       1
        \
         2
        /
       3

    输出: [1,2,3]
    输入: [2,1,3,null,4]
    输出: [2,1,4,3]
     */
    let root = generateTreeByLevel([2, 1, 3, nil, 4])
    let solution = _144_二叉树的前序遍历()
    print(solution.preorderTraversal(root))
}

/// 94-二叉树的中序遍历
func test_94() {
    /**
     输入: [1,null,2,3]
        1
         \
          2
         /
        3

     输出: [1,3,2]
     */
    let root = generateTreeByLevel([1, nil, 2, 3])
    let solution = _94_二叉树的中序遍历()
    print(solution.inorderTraversal(root))
}

/// 145-二叉树的后序遍历
func test_145() {
    /**
     输入: [1,null,2,3]
        1
         \
          2
         /
        3

     输出: [3,2,1]
     */
//    let root = generateTreeByLevel([1, nil, 2, 3])
    let root = generateTreeByLevel([3, 1, 2])
    let solution = _145_二叉树的后序遍历()
    print(solution.postorderTraversal(root))
}

/// 102-二叉树的层序遍历
func test_102() {
    /**
     给定二叉树: [3,9,20,null,null,15,7],

        3
       / \
      9  20
        /  \
       15   7
    返回其层次遍历结果：

    [
      [3],
      [9,20],
      [15,7]
    ]
     */
    let root = generateTreeByLevel([3, 9, 20, nil, nil, 15, 7])
    let solution = _102_二叉树的层次遍历()
    print(solution.levelOrder(root))
}

/// 104-二叉树的最大深度
func test_104() {
    /**
     给定二叉树 [3,9,20,null,null,15,7]，

         3
        / \
       9  20
         /  \
        15   7
     返回它的最大深度 3
     */
    let root = generateTreeByLevel([3, 9, 20, nil, nil, 15, 7])
//    let root: TreeNode? = nil
    let solution = _104_二叉树的最大深度()
    print(solution.maxDepth(root))
}

/// 105-从前序与中序遍历序列构造二叉树
func test_105() {
    /**
     前序遍历 preorder = [3,9,20,15,7]
     中序遍历 inorder = [9,3,15,20,7]
     返回如下的二叉树：

            3
           / \
          9  20
            /  \
           15   7
     */
    let solution = _105_从前序与中序遍历序列构造二叉树()
    let root = solution.buildTree([3, 9, 20, 15, 7], [9, 3, 15, 20, 7])
    print(root!)
}

/// 106-从中序与后序遍历序列构造二叉树
func test_106() {
    /**
     中序遍历 inorder = [9,3,15,20,7]
     后序遍历 postorder = [9,15,7,20,3]
     返回如下的二叉树：

            3
           / \
          9  20
            /  \
           15   7
     */
    let solution = _106_从中序与后序遍历序列构造二叉树()
    let root = solution.buildTree([9, 3, 15, 20, 7], [9, 15, 7, 20, 3])
    print(root!)
}

/// 889-根据前序和后序遍历构造二叉树
func test_889() {
    /**
     输入：pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
     输出：[1,2,3,4,5,6,7]
     */
    let solution = _889_根据前序和后序遍历构造二叉树()
    let root = solution.constructFromPrePost([1, 2, 4, 5, 3, 6, 7], [4, 5, 2, 6, 7, 3, 1])
    print(root!)
}

/// 101-对称二叉树
func test_101() {
    /**
    例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

        1
       / \
      2   2
     / \ / \
    3  4 4  3
    但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

        1
       / \
      2   2
       \   \
       3    3
     */
//    let root = generateTreeByLevel([1, 2, 2, 3, 4, 4, 3])
    let root = generateTreeByLevel([1, 2, 2, nil, 3, nil, 3])
    let solution = _101_对称二叉树()
    print(solution.isSymmetric(root))
}

/// 450-删除二叉搜索树中的节点
func test_450() {
    /**
    [5, 3, 6, 2, 4, nil, 7] - 3
    [5, 4, 6, 2, 7], [5, 2, 6, 4, 7]
    
    [2, 1] - 2
    [1]
    
    [1, nil, 2] - 1
    [2]
    
    [1, nil, 2] - 2
    [1]
     */
    let solution = _450_删除二叉搜索树中的节点()
//    let root = generateTreeByLevel([5, 3, 6, 2, 4, nil, 7])
    printTreeByLevel(solution.deleteNode(generateTreeByLevel([5, 3, 6, 2, 4, nil, 7]), 3))
    printTreeByLevel(solution.deleteNode(generateTreeByLevel([2, 1]), 2))
    printTreeByLevel(solution.deleteNode(generateTreeByLevel([1, nil, 2]), 1))
    printTreeByLevel(solution.deleteNode(generateTreeByLevel([1, nil, 2]), 2))
}

/// 700-二叉搜索树中的搜索
func test_700() {
    /**
     给定二叉搜索树:

             4
            / \
           2   7
          / \
         1   3

     和值: 2
     你应该返回如下子树:

           2
          / \
         1   3
     */
    let nodes = generateTreeByLevel([4, 2, 7, 1, 3])
    let solution = _700_二叉搜索树中的搜索()
    printTreeByLevel(solution.searchBST(nodes, 2))
}

/// 530
func test_530() {
    /**
     输入:

        1
         \
          3
         /
        2

     输出:
     1

     解释:
     最小绝对差为1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
     */
//    let nodes = generateTreeByLevel([1, nil, 3, 2])
//    let nodes = generateTreeByLevel([236, 104, 701, nil, 227, nil, 911])
    let nodes = generateTreeByLevel([0, nil, 2236, 1277, 2776, 519])
    let solution = _530_二叉搜索树的最小绝对差()
    print(solution.getMinimumDifference(nodes))
}

/// 783-二叉搜索树结点最小距离
func test_783() {
    /**
     输入: root = [4,2,6,1,3,null,null]
     输出: 1
     解释:
     注意，root是树结点对象(TreeNode object)，而不是数组。

     给定的树 [4,2,6,1,3,null,null] 可表示为下图:

               4
             /   \
           2      6
          / \
         1   3

     最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。
     */
    let nodes = generateTreeByLevel([4, 2, 6, 1, 3])
    let solution = _783_二叉搜索树结点最小距离()
    print(solution.minDiffInBST(nodes))
}

/// 701-二叉搜索树中的插入操作
func test_701() {
    /**
     给定二叉搜索树:

             4
            / \
           2   7
          / \
         1   3

     和 插入的值: 5
     你可以返回这个二叉搜索树:

              4
            /   \
           2     7
          / \   /
         1   3 5
     或者这个树也是有效的:

              5
            /   \
           2     7
          / \
         1   3
              \
               4
     */
    let nodes = generateTreeByLevel([4, 2, 7, 1, 3])
    let solution = _701_二叉搜索树中的插入操作()
    printTreeByLevel(solution.insertIntoBST(nodes, 5))
}

/// 108-将有序数组转换为二叉搜索树
func test_108() {
    /**
     给定有序数组: [-10,-3,0,5,9],

     一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

           0
          / \
        -3   9
        /   /
      -10  5
     */
    let solution = _108_将有序数组转换为二叉搜索树()
    let root = solution.sortedArrayToBST([-10, -3, 0, 5, 9])
    printTreeByLevel(root);
}

/// 938-二叉搜索树的范围和
func test_938() {
    /**
     示例 1：

     输入：root = [10,5,15,3,7,null,18], L = 7, R = 15
     输出：32
     示例 2：

     输入：root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
     输出：23
     */
    let solution = _938_二叉搜索树的范围和()
    let root = generateTreeByLevel([10, 5, 15, 3, 7, nil, 18])
    print(solution.rangeSumBST(root, 7, 15))
    let root1 = generateTreeByLevel([10, 5, 15, 3, 7, 13, 18, 1, nil, 6])
    print(solution.rangeSumBST(root1, 6, 10))
}

/// 230-二叉搜索树中第K小的元素
func test_230() {
    /**
     输入: root = [3,1,4,null,2], k = 1
        3
       / \
      1   4
       \
        2
     输出: 1
     示例 2:

     输入: root = [5,3,6,2,4,null,null,1], k = 3
            5
           / \
          3   6
         / \
        2   4
       /
      1
     输出: 3
     */
    let solution = _230_二叉搜索树中第K小的元素()
    let root = generateTreeByLevel([3, 1, 4, nil, 2])
    print(solution.kthSmallest(root, 1))
    let root1 = generateTreeByLevel([5,3,6,2,4,nil,nil,1])
    print(solution.kthSmallest(root1, 3))
}

/// 173-二叉搜索树迭代器
func test_173() {
    /**
    示例：
           7
          /\
         3  15
            /\
           9 20
    

    BSTIterator iterator = new BSTIterator(root);
    iterator.next();    // 返回 3
    iterator.next();    // 返回 7
    iterator.hasNext(); // 返回 true
    iterator.next();    // 返回 9
    iterator.hasNext(); // 返回 true
    iterator.next();    // 返回 15
    iterator.hasNext(); // 返回 true
    iterator.next();    // 返回 20
    iterator.hasNext(); // 返回 false
     */
    let root = generateTreeByLevel([7,3,15,nil,nil,9,20]);
    
    let solution = _173_二叉搜索树迭代器(root);
    print(solution.next())      // 返回3
    print(solution.next())      // 返回7
    print(solution.hasNext())   // 返回true
    print(solution.next())      // 返回9
    print(solution.hasNext())   // 返回true
    print(solution.next())      // 返回15
    print(solution.hasNext())   // 返回true
    print(solution.next())      // 返回20
    print(solution.hasNext())   // 返回false
}

/// 99-恢复二叉搜索树
func test_99() {
    /**
     输入: [1,3,null,null,2]

        1
       /
      3
       \
        2

     输出: [3,1,null,null,2]

        3
       /
      1
       \
        2
     示例 2:

     输入: [3,1,4,null,null,2]

       3
      / \
     1   4
        /
       2

     输出: [2,1,4,null,null,3]

       2
      / \
     1   4
        /
       3
     */
    let solution = _99_恢复二叉搜索树();
    var root = generateTreeByLevel([1,3,nil,nil,2])
//    solution.recoverTree(root)
//    printTreeByLevel(root)
    root = generateTreeByLevel([3,1,4,nil,nil,2])
    solution.recoverTree(root)
    printTreeByLevel(root)
}

/// 110-平衡二叉树
func test_110() {
    /**
     示例 1:

     给定二叉树 [3,9,20,null,null,15,7]

         3
        / \
       9  20
         /  \
        15   7
     返回 true 。

     示例 2:

     给定二叉树 [1,2,2,3,3,null,null,4,4]

            1
           / \
          2   2
         / \
        3   3
       / \
      4   4
     返回 false 。
     */
    let solution = _110_平衡二叉树();
    print(solution.isBalanced(generateTreeByLevel([3,9,20,nil,nil,15,7])))
    print(solution.isBalanced(generateTreeByLevel([1,2,2,3,3,nil,nil,4,4])))
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
test_99()

