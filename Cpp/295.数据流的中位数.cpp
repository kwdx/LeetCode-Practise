/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

#include <iostream>
#include <queue>

using namespace std;

// @lc code=start
class MedianFinder {
private:
    // 放置前面的数字（大顶堆）
    priority_queue<int> small;
    // 放置后面的数字（小顶堆）
    priority_queue<int, vector<int>, greater<int>> large;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (small.size() >= large.size()) {
            small.push(num);
            large.push(small.top());
            small.pop();
        } else {
            large.push(num);
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if (small.size() > large.size()) return small.top();
        if (small.size() < large.size()) return large.top();
        return (small.top() + large.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    /**
     addNum(1)
     addNum(2)
     findMedian() -> 1.5
     addNum(3)
     findMedian() -> 2
     */
    MedianFinder finder;
    finder.addNum(1);
    finder.addNum(2);
    // 1.5
    cout << finder.findMedian() << endl;
    finder.addNum(3);
    // 2
    cout << finder.findMedian() << endl;

    return 0;
}
