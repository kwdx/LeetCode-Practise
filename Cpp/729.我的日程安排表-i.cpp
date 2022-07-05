/*
 * @lc app=leetcode.cn id=729 lang=cpp
 *
 * [729] 我的日程安排表 I
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class MyCalendar {
private:
    vector<int> starts, ends;
public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        auto start_it  = upper_bound(ends.begin(), ends.end(), start);  // 二分查找第一个大于start的日程
        if (start_it == ends.end()) {
            // 没找到，直接插入到末尾
            starts.emplace_back(start);
            ends.emplace_back(end);
            return true;
        }
        int idx  = (int)(start_it - ends.begin()); // 找出下标
        if (end <= starts[idx]) {
            // 插入到idx前面
            starts.insert(starts.begin() + idx, start);
            ends.insert(ends.begin() + idx, end);
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     输入：
     ["MyCalendar", "book", "book", "book"]
     [[], [10, 20], [15, 25], [20, 30]]
     输出：
     [null, true, false, true]

     解释：
     MyCalendar myCalendar = new MyCalendar();
     myCalendar.book(10, 20); // return True
     myCalendar.book(15, 25); // return False ，这个日程安排不能添加到日历中，因为时间 15 已经被另一个日程安排预订了。
     myCalendar.book(20, 30); // return True ，这个日程安排可以添加到日历中，因为第一个日程安排预订的每个时间都小于 20 ，且不包含时间 20 。
     */
    MyCalendar myCalendar;
    assert(true == myCalendar.book(10, 20));    // return True
    assert(false == myCalendar.book(15, 25));   // return False ，这个日程安排不能添加到日历中，因为时间 15 已经被另一个日程安排预订了。
    assert(true == myCalendar.book(20, 30));    // return True ，这个日程安排可以添加到日历中，因为第一个日程安排预订的每个时间都小于 20 ，且不包含时间 20 。
    
    cout << "OK~" << endl;
    
    return 0;
}
