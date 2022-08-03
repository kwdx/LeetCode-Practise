/*
 * @lc app=leetcode.cn id=622 lang=swift
 *
 * [622] 设计循环队列
 */

// @lc code=start

class MyCircularQueue {
    
    private var idx = -1
    private var cnt = 0
    private var nums: [Int] = []

    init(_ k: Int) {
        nums = [Int](repeating: 0, count: k)
    }
    
    func enQueue(_ value: Int) -> Bool {
        guard cnt < nums.count else {
            return false
        }
        cnt += 1
        idx = (idx + 1) % nums.count
        nums[idx] = value
        return true
    }
    
    func deQueue() -> Bool {
        guard cnt > 0 else {
            return false
        }
        cnt -= 1
        return true
    }
    
    func Front() -> Int {
        if cnt == 0 {
            return -1
        }
        return nums[(idx + 1 - cnt + nums.count) % nums.count]
    }
    
    func Rear() -> Int {
        if cnt == 0 {
            return -1
        }
        return nums[idx]
    }
    
    func isEmpty() -> Bool {
        cnt == 0
    }
    
    func isFull() -> Bool {
        cnt == nums.count
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * let obj = MyCircularQueue(k)
 * let ret_1: Bool = obj.enQueue(value)
 * let ret_2: Bool = obj.deQueue()
 * let ret_3: Int = obj.Front()
 * let ret_4: Int = obj.Rear()
 * let ret_5: Bool = obj.isEmpty()
 * let ret_6: Bool = obj.isFull()
 */
// @lc code=end

func main()  {
    /**
     MyCircularQueue circularQueue = new MyCircularQueue(3); // 设置长度为 3
     circularQueue.enQueue(1);  // 返回 true
     circularQueue.enQueue(2);  // 返回 true
     circularQueue.enQueue(3);  // 返回 true
     circularQueue.enQueue(4);  // 返回 false，队列已满
     circularQueue.Rear();  // 返回 3
     circularQueue.isFull();  // 返回 true
     circularQueue.deQueue();  // 返回 true
     circularQueue.enQueue(4);  // 返回 true
     circularQueue.Rear();  // 返回 4
     */
    let circularQueue = MyCircularQueue(3)
    assert(circularQueue.enQueue(1))
    assert(circularQueue.enQueue(2))
    assert(circularQueue.enQueue(3))
    assert(!circularQueue.enQueue(4))
    assert(3 == circularQueue.Rear())
    assert(circularQueue.isFull())
    assert(circularQueue.deQueue())
    assert(circularQueue.enQueue(4))
    assert(4 == circularQueue.Rear())
}
