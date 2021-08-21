/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

#include <iostream>
#include <stack>

using namespace std;

// @lc code=start
class MyQueue {
private:
    stack<int> inSt;
    stack<int> outSt;
    
    void pushToOut() {
        while (!inSt.empty()) {
            outSt.push(inSt.top());
            inSt.pop();
        }
    }
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        inSt.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (outSt.empty()) pushToOut();
        int x = outSt.top();
        outSt.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        if (outSt.empty()) pushToOut();
        return outSt.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return inSt.empty() && outSt.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    /*
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
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    // 1
    cout << obj->peek() << endl;
    // 1
    cout << obj->pop() << endl;
    // false
    cout << obj->empty() << endl;
    // 2
    cout << obj->pop() << endl;
    // true
    cout << obj->empty() << endl;
    
    return 0;
}
