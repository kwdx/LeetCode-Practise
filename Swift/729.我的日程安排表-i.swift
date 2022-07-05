/*
 * @lc app=leetcode.cn id=729 lang=swift
 *
 * [729] 我的日程安排表 I
 */

// @lc code=start

class MyCalendar {

    private var calendars: [(Int, Int)] = []
    
    init() {

    }
    
    func book(_ start: Int, _ end: Int) -> Bool {
        if let idx = calendars.firstIndex(where: { $0.1 > start }) {
            // 查找第一个结束时间start的日程
            if end <= calendars[idx].0 {
                calendars.insert((start, end), at: idx)
                return true
            }
        } else {
            calendars.append((start, end))
            return true
        }
        return false
//        auto start_it  = upper_bound(ends.begin(), ends.end(), start);  // 二分查找第一个大于start的日程
//        if (start_it == ends.end()) {
//            // 没找到，直接插入到末尾
//            starts.emplace_back(start);
//            ends.emplace_back(end);
//            return true;
//        }
//        int idx  = (int)(start_it - ends.begin()); // 找出下标
//        if (end <= starts[idx]) {
//            // 插入到idx前面
//            starts.insert(starts.begin() + idx, start);
//            ends.insert(ends.begin() + idx, end);
//            return true;
//        }
//        return false;
//
//        for item in calendars {
//            if start >= item.0 && start < item.1 {
//                return false
//            }
//            if end > item.0 && end < item.1 {
//                return false
//            }
//            if start < item.0 && end >= item.1 {
//                return false
//            }
//        }
//        calendars.append((start, end))
//        return true
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * let obj = MyCalendar()
 * let ret_1: Bool = obj.book(start, end)
 */
// @lc code=end

func main() {
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
    let myCalendar = MyCalendar()
    assert(true == myCalendar.book(10, 20))     // return True
    assert(false == myCalendar.book(15, 25))    // return False ，这个日程安排不能添加到日历中，因为时间 15 已经被另一个日程安排预订了。
    assert(true == myCalendar.book(20, 30))     // return True ，这个日程安排可以添加到日历中，因为第一个日程安排预订的每个时间都小于 20 ，且不包含时间 20 。
}
