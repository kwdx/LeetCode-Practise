/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class MyCircularDeque {
private:
    vector<int> nums;
    int front, rear;
    int capacity;
public:
    MyCircularDeque(int k) {
        capacity = k + 1;
        nums.resize(k + 1);
        front = 0;
        rear = 0;
    }
    
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        front = (front - 1 + capacity) % capacity;
        nums[front] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        nums[rear] = value;
        rear = (rear + 1 + capacity) % capacity;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1 + capacity) % capacity;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        rear = (rear - 1 + capacity) % capacity;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return nums[front];
    }
    
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return nums[(rear - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return rear == front;
    }
    
    bool isFull() {
        return (rear + 1) % capacity == front;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     输入
     ["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
     [[3], [1], [2], [3], [4], [], [], [], [4], []]
     输出
     [null, true, true, true, false, 2, true, true, true, 4]

     解释
     MyCircularDeque circularDeque = new MycircularDeque(3); // 设置容量大小为3
     circularDeque.insertLast(1);                    // 返回 true
     circularDeque.insertLast(2);                    // 返回 true
     circularDeque.insertFront(3);                    // 返回 true
     circularDeque.insertFront(4);                    // 已经满了，返回 false
     circularDeque.getRear();                  // 返回 2
     circularDeque.isFull();                        // 返回 true
     circularDeque.deleteLast();                    // 返回 true
     circularDeque.insertFront(4);                    // 返回 true
     circularDeque.getFront();                // 返回 4
     */
    MyCircularDeque* obj = new MyCircularDeque(3);
    assert(true == obj->insertLast(1));
    assert(true == obj->insertLast(2));
    assert(true == obj->insertFront(3));
    assert(false == obj->insertFront(4));
    assert(2 == obj->getRear());
    assert(true == obj->isFull());
    assert(true == obj->deleteLast());
    assert(true == obj->insertFront(4));
    assert(4 == obj->getFront());

    delete obj;
    
    cout << "OK~" << endl;
    
    return 0;
}
