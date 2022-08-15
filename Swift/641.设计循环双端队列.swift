/*
 * @lc app=leetcode.cn id=641 lang=swift
 *
 * [641] 设计循环双端队列
 */

// @lc code=start

class MyCircularDeque {
    
    private var nums: [Int]
    private var front: Int = 0
    private var rear: Int = 0
    private let capacity: Int

    init(_ k: Int) {
        capacity = k + 1
        nums = [Int](repeating: 0, count: capacity)
    }
    
    func insertFront(_ value: Int) -> Bool {
        if isFull() {
            return false
        }
        front = (front - 1 + capacity) % capacity
        nums[front] = value
        return true
    }
    
    func insertLast(_ value: Int) -> Bool {
        if isFull() {
            return false
        }
        nums[rear] = value
        rear = (rear + 1) % capacity
        return true
    }
    
    func deleteFront() -> Bool {
        if isEmpty() {
            return false
        }
        front = (front + 1 + capacity) % capacity
        return true
    }
    
    func deleteLast() -> Bool {
        if isEmpty() {
            return false
        }
        rear = (rear - 1 + capacity) % capacity
        return true
    }
    
    func getFront() -> Int {
        if isEmpty() {
            return -1
        }
        return nums[front]
    }
    
    func getRear() -> Int {
        if isEmpty() {
            return -1
        }
        return nums[(rear - 1 + capacity) % capacity]
    }
    
    func isEmpty() -> Bool {
        rear == front
    }
    
    func isFull() -> Bool {
        (rear + 1) % capacity == front
    }
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * let obj = MyCircularDeque(k)
 * let ret_1: Bool = obj.insertFront(value)
 * let ret_2: Bool = obj.insertLast(value)
 * let ret_3: Bool = obj.deleteFront()
 * let ret_4: Bool = obj.deleteLast()
 * let ret_5: Int = obj.getFront()
 * let ret_6: Int = obj.getRear()
 * let ret_7: Bool = obj.isEmpty()
 * let ret_8: Bool = obj.isFull()
 */
// @lc code=end

func main() {
    /**
     输入
     ["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
     [[3], [1], [2], [3], [4], [], [], [], [4], []]
     输出
     [null, true, true, true, false, 2, true, true, true, 4]

     解释
     MyCircularDeque circularDeque = new MycircularDeque(3); // 设置容量大小为3
     circularDeque.insertLast(1);                    // 返回 true
     circularDeque.insertLast(2);                    // 返回 true
     circularDeque.insertFront(3);                    // 返回 true
     circularDeque.insertFront(4);                    // 已经满了，返回 false
     circularDeque.getRear();                  // 返回 2
     circularDeque.isFull();                        // 返回 true
     circularDeque.deleteLast();                    // 返回 true
     circularDeque.insertFront(4);                    // 返回 true
     circularDeque.getFront();                // 返回 4
     */
    let obj = MyCircularDeque(3)
    assert(true == obj.insertLast(1))
    assert(true == obj.insertLast(2))
    assert(true == obj.insertFront(3))
    assert(false == obj.insertFront(4))
    assert(2 == obj.getRear())
    assert(true == obj.isFull())
    assert(true == obj.deleteLast())
    assert(true == obj.insertFront(4))
    assert(4 == obj.getFront())
}
