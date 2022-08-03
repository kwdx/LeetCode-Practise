/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class MyCircularQueue {
private:
    int cnt = 0;
    int idx = -1;
    vector<int> nums;
public:
    MyCircularQueue(int k) {
        nums.resize(k);
    }
    
    bool enQueue(int value) {
        if (cnt >= nums.size()) {
            return false;
        }
        cnt += 1;
        idx = (idx + 1) % nums.size();
        nums[idx] = value;
        return true;
    }
    
    bool deQueue() {
        if (cnt == 0) {
            return false;
        }
        cnt -= 1;
        return true;
    }
    
    int Front() {
        if (cnt == 0) {
            return -1;
        }
        return nums[(idx + 1 - cnt + nums.size()) % nums.size()];
    }
    
    int Rear() {
        if (cnt == 0) {
            return -1;
        }
        return nums[idx];
    }
    
    bool isEmpty() {
        return cnt == 0;
    }
    
    bool isFull() {
        return cnt == nums.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     MyCircularQueue circularQueue = new MyCircularQueue(3); // 设置长度为 3
     circularQueue.enQueue(1);  // 返回 true
     circularQueue.enQueue(2);  // 返回 true
     circularQueue.enQueue(3);  // 返回 true
     circularQueue.enQueue(4);  // 返回 false，队列已满
     circularQueue.Rear();  // 返回 3
     circularQueue.isFull();  // 返回 true
     circularQueue.deQueue();  // 返回 true
     circularQueue.enQueue(4);  // 返回 true
     circularQueue.Rear();  // 返回 4
     */
    MyCircularQueue circularQueue(3);
    assert(circularQueue.enQueue(1));
    assert(circularQueue.enQueue(2));
    assert(circularQueue.enQueue(3));
    assert(!circularQueue.enQueue(4));
    assert(3 == circularQueue.Rear());
    assert(circularQueue.isFull());
    assert(circularQueue.deQueue());
    assert(circularQueue.enQueue(4));
    assert(4 == circularQueue.Rear());
    
    cout << "OK~" << endl;
    
    return 0;
}
