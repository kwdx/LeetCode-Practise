//
//  _225_用队列实现栈.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/3.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_225_用队列实现栈.hpp"

_225_用队列实现栈::_225_用队列实现栈() {
}
    
/** Push element x onto stack. */
void _225_用队列实现栈::push(int x) {
    int size = (int)nums.size();
    nums.push(x);
    for (int i = 0; i < size; i++) {
        nums.push(nums.front());
        nums.pop();
    }
}
    
/** Removes the element on top of the stack and returns that element. */
int _225_用队列实现栈::pop() {
    int x = nums.front();
    nums.pop();
    return x;
}
    
/** Get the top element. */
int _225_用队列实现栈::top() {
    return nums.front();
}
    
/** Returns whether the stack is empty. */
bool _225_用队列实现栈::empty() {
    return nums.empty();
}
