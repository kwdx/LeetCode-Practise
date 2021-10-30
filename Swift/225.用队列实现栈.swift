/*
 * @lc app=leetcode.cn id=225 lang=swift
 *
 * [225] 用队列实现栈
 */

// @lc code=start

class MyStack {
    
    private var queue = [Int]()
    
    /** Initialize your data structure here. */
    init() {
    }
    
    /** Push element x onto stack. */
    func push(_ x: Int) {
        let count = queue.count
        queue.append(x)
        for _ in 0..<count {
            queue.append(queue.removeFirst())
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    func pop() -> Int {
        return queue.removeFirst()
    }
    
    /** Get the top element. */
    func top() -> Int {
        return queue.first ?? 0
    }
    
    /** Returns whether the stack is empty. */
    func empty() -> Bool {
        return queue.isEmpty
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * let obj = MyStack()
 * obj.push(x)
 * let ret_2: Int = obj.pop()
 * let ret_3: Int = obj.top()
 * let ret_4: Bool = obj.empty()
 */
// @lc code=end

func main() {    
    /**
     输入：
     ["MyStack", "push", "push", "top", "pop", "empty"]
     [[], [1], [2], [], [], []]
     输出：
     [null, null, null, 2, 2, false]

     解释：
     MyStack myStack = new MyStack();
     myStack.push(1);
     myStack.push(2);
     myStack.top(); // 返回 2
     myStack.pop(); // 返回 2
     myStack.empty(); // 返回 False
     */
    let myStack = MyStack()
    myStack.push(1)
    myStack.push(2)
    assert(myStack.top() == 2)
    assert(myStack.pop() == 2)
    assert(!myStack.empty())
}
