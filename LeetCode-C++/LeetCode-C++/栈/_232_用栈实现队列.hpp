//
//  _232_用栈实现队列.hpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/3.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/implement-queue-using-stacks/

#ifndef _232________hpp
#define _232________hpp

#include <stdio.h>
#include <stack>

using namespace std;

class _232_用栈实现队列 {
private:
    stack<int> a;
    stack<int> b;
    
    void pushInToOutIfEmpty();
public:
    /** Initialize your data structure here. */
    _232_用栈实现队列();
    
    /** Push element x to the back of queue. */
    void push(int x);
    
    /** Removes the element from in front of queue and returns that element. */
    int pop();
    
    /** Get the front element. */
    int peek();
    
    /** Returns whether the queue is empty. */
    bool empty();
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

#endif /* _232________hpp */
