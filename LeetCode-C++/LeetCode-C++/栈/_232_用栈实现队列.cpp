//
//  _232_用栈实现队列.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/3.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_232_用栈实现队列.hpp"

/** Initialize your data structure here. */
_232_用栈实现队列::_232_用栈实现队列() {
    
}

void _232_用栈实现队列::pushInToOutIfEmpty() {
    if (b.empty()) {
        while (!a.empty()) {
            b.push(a.top());
            a.pop();
        }
    }
}

/** Push element x to the back of queue. */
void _232_用栈实现队列::push(int x) {
    a.push(x);
}
    
/** Removes the element from in front of queue and returns that element. */
int _232_用栈实现队列::pop() {
    pushInToOutIfEmpty();
    int x = b.top();
    b.pop();
    return x;
}
    
/** Get the front element. */
int _232_用栈实现队列::peek() {
    pushInToOutIfEmpty();
    return b.top();
}
    
/** Returns whether the queue is empty. */
bool _232_用栈实现队列::empty() {
    pushInToOutIfEmpty();
    return b.empty();
}
