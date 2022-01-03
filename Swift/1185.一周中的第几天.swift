/*
 * @lc app=leetcode.cn id=1185 lang=swift
 *
 * [1185] 一周中的第几天
 */

// @lc code=start
class Solution {
    func dayOfTheWeek(_ day: Int, _ month: Int, _ year: Int) -> String {
        let weekdays = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"]
        let days = [31,28,31,30,31,30,31,31,30,31,30,31]
        var ans = 4
        let isRun: (Int) -> Bool = {
            (($0 % 4 == 0) && ($0 % 100 != 0)) || ($0 % 400 == 0)
        }
        for i in 1971..<year {
            ans += isRun(i) ? 366 : 365
        }
        for i in 1..<month {
            ans += days[i - 1]
            if i == 2 && isRun(year) {
                ans += 1
            }
        }
        ans += day
        return weekdays[ans % 7]
    }
}
// @lc code=end

func main() {
    var day: Int
    var month: Int
    var year: Int
    var res: String
    
    /**
     输入：day = 31, month = 8, year = 2019
     输出："Saturday"
     */
    day = 31
    month = 8
    year = 2019
    res = "Saturday"
    assert(res == Solution().dayOfTheWeek(day, month, year))

    /**
     输入：day = 18, month = 7, year = 1999
     输出："Sunday"
     */
    day = 18
    month = 7
    year = 1999
    res = "Sunday"
    assert(res == Solution().dayOfTheWeek(day, month, year))

    /**
     输入：day = 15, month = 8, year = 1993
     输出："Sunday"
     */
    day = 15
    month = 8
    year = 1993
    res = "Sunday"
    assert(res == Solution().dayOfTheWeek(day, month, year))
    
    /**
     输入：day = 21, month = 12, year = 1980
     输出："Sunday"
     */
    day = 21
    month = 12
    year = 1980
    res = "Sunday"
    assert(res == Solution().dayOfTheWeek(day, month, year))
}
