/*
 * @lc app=leetcode.cn id=731 lang=swift
 *
 * [731] 我的日程安排表 II
 */

// @lc code=start

class MyCalendarTwo {
    private var tree: [Int: (Int, Int)]  = [:]

    init() {

    }
    
    func book(_ start: Int, _ end: Int) -> Bool {
        update(start, end - 1, 1, 0, Int(1e9), 1)
        if let v = tree[1], v.0 > 2 {
            update(start, end - 1, -1, 0, Int(1e9), 1)
            return false;
        }
        return true
    }
    
    private func update(_ start: Int, _ end: Int, _ val: Int, _ l: Int, _ r: Int, _ idx: Int) {
        if r < start || end < l {
            return
        }
        if tree[idx] == nil {
            tree[idx] = (0, 0)
        }
        if start <= l && r <= end {
            tree[idx]!.0 += val
            tree[idx]!.1 += val
        } else {
            let mid = (l + r) >> 1
            update(start, end, val, l, mid, 2 * idx)
            update(start, end, val, mid + 1, r, 2 * idx + 1)
            tree[idx]!.0 = tree[idx]!.1 + max((tree[2 * idx]?.0 ?? 0), (tree[2 * idx + 1]?.0 ?? 0));
        }
    }
}

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * let obj = MyCalendarTwo()
 * let ret_1: Bool = obj.book(start, end)
 */
// @lc code=end

func main() {
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
    let obj = MyCalendarTwo()
    assert(obj.book(10, 20))
    assert(obj.book(50, 60))
    assert(obj.book(10, 40))
    assert(!obj.book(5, 15))
    assert(obj.book(5, 10))
    assert(obj.book(25, 55))
}
