//
//  041.cpp
//  Cpp
//
//  Created by warden on 2022/7/17.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class MovingAverage {
private:
    deque<int> nums;
    double sum;
    int n;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->n = size;
    }
    
    double next(int val) {
        nums.push_back(val);
        sum += val;
        if (nums.size() > n) {
            sum -= nums.front();
            nums.pop_front();
        }
        return sum / nums.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     输入：
     inputs = ["MovingAverage", "next", "next", "next", "next"]
     inputs = [[3], [1], [10], [3], [5]]
     输出：
     [null, 1.0, 5.5, 4.66667, 6.0]

     解释：
     MovingAverage movingAverage = new MovingAverage(3);
     movingAverage.next(1); // 返回 1.0 = 1 / 1
     movingAverage.next(10); // 返回 5.5 = (1 + 10) / 2
     movingAverage.next(3); // 返回 4.66667 = (1 + 10 + 3) / 3
     movingAverage.next(5); // 返回 6.0 = (10 + 3 + 5) / 3
     */
    MovingAverage movingAverage(3);
    assert(1 == movingAverage.next(1));
    assert(5.5 == movingAverage.next(10));
    assert(14 / 3.0 == movingAverage.next(3));
    assert(6 == movingAverage.next(5));
    
    cout << "OK~" << endl;
    
    return 0;
}
