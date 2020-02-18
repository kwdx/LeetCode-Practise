//
//  _225_用队列实现栈.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/3.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/implement-stack-using-queues/

#include <stdio.h>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> nums;

public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        int size = (int)nums.size();
        nums.push(x);
        for (int i = 0; i < size; i++) {
            nums.push(nums.front());
            nums.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = nums.front();
        nums.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return nums.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return nums.empty();
    }
};

/**
 MyStack* obj = new MyStack();
 obj->push(x);
 int param_2 = obj->pop();
 int param_3 = obj->top();
 bool param_4 = obj->empty();
 */
/**
int main(int argc, const char * argv[]) {
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();
    printf("%d %d %d\n", param_2, param_3, param_4);
    delete obj;
    return 0;
}
*/
