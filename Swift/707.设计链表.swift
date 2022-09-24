/*
 * @lc app=leetcode.cn id=707 lang=swift
 *
 * [707] 设计链表
 */

// @lc code=start

class MyLinkedList {
    
    private class Node {
        let value: Int
        var prev: Node?
        var next: Node?
        
        init(value: Int, prev: Node? = nil, next: Node? = nil) {
            self.value = value
            self.prev = prev
            self.next = next
        }
    }
    
    private var size = 0
    private var head = Node(value: 0)
    private var tail = Node(value: 0)

    init() {
        head.next = tail
        tail.prev = head
    }
    
    func get(_ index: Int) -> Int {
        guard (0..<size).contains(index) else { return -1 }
        
        var node: Node?
        if index + 1 < size - index {
            node = head;
            for _ in 0...index {
                node = node?.next
            }
        } else {
            node = tail
            for _ in 0..<(size - index) {
                node = node?.prev
            }
        }
        return node?.value ?? -1
    }
    
    func addAtHead(_ val: Int) {
        addAtIndex(0, val)
    }
    
    func addAtTail(_ val: Int) {
        addAtIndex(size, val)
    }
    
    func addAtIndex(_ index: Int, _ val: Int) {
        guard index <= size else { return }
        
        if (index > size) {
            return;
        }
        var index = max(0, index)
        var prev: Node?
        var succ: Node?
        if index < size - index {
            prev = head
            for _ in 0..<index {
                prev = prev?.next
            }
            succ = prev?.next
        } else {
            succ = tail
            for _ in 0..<(size - index) {
                succ = succ?.prev
            }
            prev = succ?.prev
        }
        size += 1
        let node = Node(value: val)
        node.prev = prev;
        node.next = succ
        prev?.next = node
        succ?.prev = node
    }
    
    func deleteAtIndex(_ index: Int) {
        guard (0..<size).contains(index) else { return }
        
        var prev: Node?
        var succ: Node?
        if index < size - index {
            prev = head
            for _ in 0..<index {
                prev = prev?.next
            }
            succ = prev?.next?.next
        } else {
            succ = tail
            for _ in 0..<(size - index - 1) {
                succ = succ?.prev
            }
            prev = succ?.prev?.prev
        }
        size -= 1
        prev?.next = succ
        succ?.prev = prev
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * let obj = MyLinkedList()
 * let ret_1: Int = obj.get(index)
 * obj.addAtHead(val)
 * obj.addAtTail(val)
 * obj.addAtIndex(index, val)
 * obj.deleteAtIndex(index)
 */
// @lc code=end

func main() {
    /**
     MyLinkedList linkedList = new MyLinkedList();
     linkedList.addAtHead(1);
     linkedList.addAtTail(3);
     linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
     linkedList.get(1);            //返回2
     linkedList.deleteAtIndex(1);  //现在链表是1-> 3
     linkedList.get(1);            //返回3
     */
    let linkedList = MyLinkedList()
    linkedList.addAtHead(1)
    linkedList.addAtTail(3)
    linkedList.addAtIndex(1, 2)
    assert(2 == linkedList.get(1))
    linkedList.deleteAtIndex(1)
    assert(3 == linkedList.get(1))
}
