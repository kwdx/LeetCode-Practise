/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

#include <iostream>
#include <queue>

using namespace std;

// @lc code=start
class MyStack {
private:
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        int x = q.front();
        q.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return q.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    /**
     输入：
     ["MyStack", "push", "push", "top", "pop", "empty", "pop", "empty"]
     [[], [1], [2], [], [], [], [], []]
     输出：
     [null, null, null, 2, 2, false, 1, true]
     */
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    // 2
    cout << obj->top() << endl;
    // 2
    cout << obj->pop() << endl;
    // false
    cout << obj->empty() << endl;
    // 1
    cout << obj->pop() << endl;
    // true
    cout << obj->empty() << endl;
    return 0;
}
