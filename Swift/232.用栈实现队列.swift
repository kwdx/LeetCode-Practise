/*
 * @lc app=leetcode.cn id=232 lang=swift
 *
 * [232] 用栈实现队列
 */

// @lc code=start

class MyQueue {
    
    private var inS = [Int]()
    private var outS = [Int]()
    
    private func pushInToOutIfEmpty() {
        if (outS.isEmpty) {
            while !inS.isEmpty {
                outS.append(inS.removeLast())
            }
        }
    }
    
    /** Initialize your data structure here. */
    init() {
        
    }
    
    /** Push element x to the back of queue. */
    func push(_ x: Int) {
        inS.append(x)
    }
    
    /** Removes the element from in front of queue and returns that element. */
    func pop() -> Int {
        pushInToOutIfEmpty()
        return outS.removeLast()
    }
    
    /** Get the front element. */
    func peek() -> Int {
        pushInToOutIfEmpty();
        return outS.last ?? 0
    }
    
    /** Returns whether the queue is empty. */
    func empty() -> Bool {
        pushInToOutIfEmpty();
        return outS.isEmpty;
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * let obj = MyQueue()
 * obj.push(x)
 * let ret_2: Int = obj.pop()
 * let ret_3: Int = obj.peek()
 * let ret_4: Bool = obj.empty()
 */
// @lc code=end

func main() {
    /**
     输入：
     ["MyQueue", "push", "push", "peek", "pop", "empty"]
     [[], [1], [2], [], [], []]
     输出：
     [null, null, null, 1, 1, false]

     解释：
     MyQueue myQueue = new MyQueue();
     myQueue.push(1); // queue is: [1]
     myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
     myQueue.peek(); // return 1
     myQueue.pop(); // return 1, queue is [2]
     myQueue.empty(); // return false
     */
    let myQueue = MyQueue()
    myQueue.push(1)
    myQueue.push(2)
    assert(myQueue.peek() == 1)
    assert(myQueue.pop() == 1)
    assert(!myQueue.empty())
}
