/*
 * @lc app=leetcode.cn id=731 lang=cpp
 *
 * [731] 我的日程安排表 II
 */

#include <iostream>
#include <unordered_map>

using namespace std;

// @lc code=start
class MyCalendarTwo {
private:
    unordered_map<int, pair<int, int>> tree;
public:
    MyCalendarTwo() {

    }
    
    void update(int start, int end, int val, int l, int r, int idx) {
        if (r < start || end < l) {
            return;
        }
        if (start <= l && r <= end) {
            tree[idx].first += val;
            tree[idx].second += val;
        } else {
            int mid = (l + r) >> 1;
            update(start, end, val, l, mid, 2 * idx);
            update(start, end, val, mid + 1, r, 2 * idx + 1);
            tree[idx].first = tree[idx].second + max(tree[2 * idx].first, tree[2 * idx + 1].first);
        }
    }
    
    bool book(int start, int end) {
        update(start, end - 1, 1, 0, 1e9, 1);
        if (tree[1].first > 2) {
            update(start, end - 1, -1, 0, 1e9, 1);
            return false;
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     MyCalendar();
     MyCalendar.book(10, 20); // returns true
     MyCalendar.book(50, 60); // returns true
     MyCalendar.book(10, 40); // returns true
     MyCalendar.book(5, 15); // returns false
     MyCalendar.book(5, 10); // returns true
     MyCalendar.book(25, 55); // returns true
     解释：
     前两个日程安排可以添加至日历中。 第三个日程安排会导致双重预订，但可以添加至日历中。
     第四个日程安排活动（5,15）不能添加至日历中，因为它会导致三重预订。
     第五个日程安排（5,10）可以添加至日历中，因为它未使用已经双重预订的时间10。
     第六个日程安排（25,55）可以添加至日历中，因为时间 [25,40] 将和第三个日程安排双重预订；
     时间 [40,50] 将单独预订，时间 [50,55）将和第二个日程安排双重预订。
     */
    MyCalendarTwo obj;
    assert(obj.book(10, 20));
    assert(obj.book(50, 60));
    assert(obj.book(10, 40));
    assert(!obj.book(5, 15));
    assert(obj.book(5, 10));
    assert(obj.book(25, 55));
    
    cout << "OK~" << endl;
    
    return 0;
}
