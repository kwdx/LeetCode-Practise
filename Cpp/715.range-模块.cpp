/*
 * @lc app=leetcode.cn id=715 lang=cpp
 *
 * [715] Range 模块
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// @lc code=start
class RangeModule {
private:
    map<int, int> intervals;
public:
    RangeModule() {

    }
    
    void addRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it != intervals.begin()) {
            auto start = prev(it);
            if (start->second >= right) {
                return;
            }
            if (start->second >= left) {
                left = start->first;
                intervals.erase(start);
            }
        }
        while (it != intervals.end() && it->first <= right) {
            right = max(right, it->second);
            it = intervals.erase(it);
        }
        intervals[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it == intervals.begin()) {
            return false;
        }
        it = prev(it);
        return right <= it->second;
    }
    
    void removeRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it != intervals.begin()) {
            auto start = prev(it);
            if (start->second >= right) {
                int ri = start->second;
                if (start->first == left) {
                    intervals.erase(start);
                } else {
                    start->second = left;
                }
                if (right != ri) {
                    intervals[right] = ri;
                }
                return;
            } else if (start->second > left) {
                start->second = left;
            }
        }
        
        while (it != intervals.end() && it->first < right) {
            if (it->second <= right) {
                it = intervals.erase(it);
            } else {
                intervals[right] = it->second;
                intervals.erase(it);
                break;
            }
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     输入
     ["RangeModule", "addRange", "removeRange", "queryRange", "queryRange", "queryRange"]
     [[], [10, 20], [14, 16], [10, 14], [13, 15], [16, 17]]
     输出
     [null, null, null, true, false, true]

     解释
     RangeModule rangeModule = new RangeModule();
     rangeModule.addRange(10, 20);
     rangeModule.removeRange(14, 16);
     rangeModule.queryRange(10, 14); 返回 true （区间 [10, 14) 中的每个数都正在被跟踪）
     rangeModule.queryRange(13, 15); 返回 false（未跟踪区间 [13, 15) 中像 14, 14.03, 14.17 这样的数字）
     rangeModule.queryRange(16, 17); 返回 true （尽管执行了删除操作，区间 [16, 17) 中的数字 16 仍然会被跟踪）
     */
    RangeModule rangeModule;
    rangeModule.addRange(10, 20);
    rangeModule.removeRange(14, 16);
    assert(rangeModule.queryRange(10, 14));     // 返回 true （区间 [10, 14) 中的每个数都正在被跟踪）
    assert(!rangeModule.queryRange(13, 15));    // 返回 false（未跟踪区间 [13, 15) 中像 14, 14.03, 14.17 这样的数字）
    assert(rangeModule.queryRange(16, 17));     // 返回 true （尽管执行了删除操作，区间 [16, 17) 中的数字 16 仍然会被跟踪）
    
    cout << "OK~" << endl;
    
    return 0;
}
