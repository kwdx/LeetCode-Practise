//
//  _232_用栈实现队列.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/3.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/implement-queue-using-stacks/

#include <stdio.h>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> a;
    stack<int> b;

    void pushInToOutIfEmpty() {
        if (b.empty()) {
            while (!a.empty()) {
                b.push(a.top());
                a.pop();
            }
        }
    }
    
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        a.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        pushInToOutIfEmpty();
        int x = b.top();
        b.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        pushInToOutIfEmpty();
        return b.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        pushInToOutIfEmpty();
        return b.empty();
    }
};

/**
 MyQueue* obj = new MyQueue();
 obj->push(x);
 int param_2 = obj->pop();
 int param_3 = obj->peek();
 bool param_4 = obj->empty();
*/
/**
int main(int argc, const char * argv[]) {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();
    printf("%d %d %d\n", param_2, param_3, param_4);
    delete obj;
    return 0;
}
*/
