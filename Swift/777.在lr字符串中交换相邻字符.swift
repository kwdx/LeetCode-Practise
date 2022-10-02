/*
 * @lc app=leetcode.cn id=777 lang=swift
 *
 * [777] 在LR字符串中交换相邻字符
 */

// @lc code=start
class Solution {
    func canTransform(_ start: String, _ end: String) -> Bool {
        let n = start.count
        var i = 0, j = 0
        let start = Array(start)
        let end = Array(end)
        while i < n || j < n {
            while i < n && start[i] == "X" {
                i += 1
            }
            while j < n && end[j] == "X" {
                j += 1
            }
            if i == n || j == n {
                return i == j
            }
            if start[i] != end[j] {
                return false
            }
            if start[i] == "L" && i < j {
                return false
            }
            if start[i] == "R" && i > j {
                return false
            }
            i += 1
            j += 1
        }
        return i == j
    }
}
// @lc code=end

func main() {
    var start: String
    var end: String
    var res: Bool
    
    /**
     输入: start = "RXXLRXRXL", end = "XRLXXRRLX"
     输出: True
     解释:
     我们可以通过以下几步将start转换成end:
     RXXLRXRXL ->
     XRXLRXRXL ->
     XRLXRXRXL ->
     XRLXXRRXL ->
     XRLXXRRLX
     */
    start = "RXXLRXRXL"
    end = "XRLXXRRLX"
    res = true
    assert(res == Solution().canTransform(start, end))
}
