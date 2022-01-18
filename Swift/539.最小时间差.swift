/*
 * @lc app=leetcode.cn id=539 lang=swift
 *
 * [539] 最小时间差
 */

// @lc code=start
class Solution {
    func findMinDifference(_ timePoints: [String]) -> Int {
        if timePoints.count >= 1440 {
            return 0
        }
        var cnts: [Int] = .init(repeating: 0, count: 1440 * 2 + 1)
        for timePoint in timePoints {
            let components = timePoint.components(separatedBy: ":")
            let hour = Int(components[0])!
            let minute = Int(components[1])!
            cnts[hour * 60 + minute] += 1
            cnts[hour * 60 + minute + 1440] += 1
            if cnts[hour * 60 + minute] > 1 {
                return 0
            }
        }
        var ans = 1440, last = -1
        for i in 0...1440*2 {
            if cnts[i] == 0 {
                continue;
            } else if last != -1 {
                ans = min(ans, i - last)
            }
            last = i
            if ans == 0 {
                return 0
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var timePoints: [String]
    var res: Int
    
    /**
     输入：timePoints = ["23:59","00:00"]
     输出：1
     */
    timePoints = ["23:59","00:00"]
    res = 1
    assert(res == Solution().findMinDifference(timePoints))
    
    /**
     输入：timePoints = ["00:00","23:59","00:00"]
     输出：0
     */
    timePoints = ["00:00","23:59","00:00"]
    res = 0
    assert(res == Solution().findMinDifference(timePoints))
}
