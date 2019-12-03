//
//  _225_用队列实现栈.hpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/3.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/implement-stack-using-queues/

#ifndef _225________hpp
#define _225________hpp

#include <stdio.h>
#include <queue>

using namespace std;

class _225_用队列实现栈 {
private:
    queue<int> nums;
public:
    /** Initialize your data structure here. */
    _225_用队列实现栈();
    
    /** Push element x onto stack. */
    void push(int x);
    
    /** Removes the element on top of the stack and returns that element. */
    int pop();
    
    /** Get the top element. */
    int top();
    
    /** Returns whether the stack is empty. */
    bool empty();
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

#endif /* _225________hpp */
