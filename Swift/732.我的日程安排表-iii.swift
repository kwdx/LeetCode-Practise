/*
 * @lc app=leetcode.cn id=732 lang=swift
 *
 * [732] 我的日程安排表 III
 */

// @lc code=start

class MyCalendarThree {
    var list: [Int] = []
    var map: [Int: Int] = [:]

    init() {

    }
    
    func book(_ start: Int, _ end: Int) -> Int {
        insert(start)
        insert(end)
        map[start] = (map[start] ?? 0) + 1
        map[end] = (map[end] ?? 0) - 1
        
        var ans = 0
        var count = 0
        for key in list {
            count += map[key] ?? 0
            ans = max(ans, count)
        }
        
        return ans
    }
    
    func insert(_ val: Int) {
        var left = 0
        var right = list.count
        
        while left < right {
            let mid = (left + right) >> 1
            if list[mid] > val {
                right = mid
            } else if list[mid] < val {
                left = mid + 1
            } else {
                return
            }
        }
        
        list.insert(val, at: left)
    }
}

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * let obj = MyCalendarThree()
 * let ret_1: Int = obj.book(start, end)
 */
// @lc code=end

func main() {
    /**
     输入：
     ["MyCalendarThree", "book", "book", "book", "book", "book", "book"]
     [[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
     输出：
     [null, 1, 1, 2, 3, 3, 3]

     解释：
     MyCalendarThree myCalendarThree = new MyCalendarThree();
     myCalendarThree.book(10, 20); // 返回 1 ，第一个日程安排可以预订并且不存在相交，所以最大 k 次预订是 1 次预订。
     myCalendarThree.book(50, 60); // 返回 1 ，第二个日程安排可以预订并且不存在相交，所以最大 k 次预订是 1 次预订。
     myCalendarThree.book(10, 40); // 返回 2 ，第三个日程安排 [10, 40) 与第一个日程安排相交，所以最大 k 次预订是 2 次预订。
     myCalendarThree.book(5, 15); // 返回 3 ，剩下的日程安排的最大 k 次预订是 3 次预订。
     myCalendarThree.book(5, 10); // 返回 3
     myCalendarThree.book(25, 55); // 返回 3
     */
    let myCalendarThree = MyCalendarThree()
    assert(1 == myCalendarThree.book(10, 20))   // 返回 1 ，第一个日程安排可以预订并且不存在相交，所以最大 k 次预订是 1 次预订。
    assert(1 == myCalendarThree.book(50, 60))   // 返回 1 ，第二个日程安排可以预订并且不存在相交，所以最大 k 次预订是 1 次预订。
    assert(2 == myCalendarThree.book(10, 40))   // 返回 2 ，第三个日程安排 [10, 40) 与第一个日程安排相交，所以最大 k 次预订是 2 次预订。
    assert(3 == myCalendarThree.book(5, 15))    // 返回 3 ，剩下的日程安排的最大 k 次预订是 3 次预订。
    assert(3 == myCalendarThree.book(5, 10))    // 返回 3
    assert(3 == myCalendarThree.book(25, 55))   // 返回 3
}
