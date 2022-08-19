/*
 * @lc app=leetcode.cn id=1450 lang=swift
 *
 * [1450] 在既定时间做作业的学生人数
 */

// @lc code=start
class Solution {
    func busyStudent(_ startTime: [Int], _ endTime: [Int], _ queryTime: Int) -> Int {
        var ans = 0
        for i in 0..<startTime.count {
            if startTime[i] <= queryTime && endTime[i] >= queryTime {
                ans += 1
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var startTime: [Int]
    var endTime: [Int]
    var queryTime: Int
    var res: Int
    
    /**
     输入：startTime = [1,2,3], endTime = [3,2,7], queryTime = 4
     输出：1
     解释：一共有 3 名学生。
     第一名学生在时间 1 开始写作业，并于时间 3 完成作业，在时间 4 没有处于做作业的状态。
     第二名学生在时间 2 开始写作业，并于时间 2 完成作业，在时间 4 没有处于做作业的状态。
     第三名学生在时间 3 开始写作业，预计于时间 7 完成作业，这是是唯一一名在时间 4 时正在做作业的学生。
     */
    startTime = [1,2,3]
    endTime = [3,2,7]
    queryTime = 4
    res = 1
    assert(res == Solution().busyStudent(startTime, endTime, queryTime))
    
    /**
     输入：startTime = [4], endTime = [4], queryTime = 4
     输出：1
     解释：在查询时间只有一名学生在做作业。
     */
    startTime = [4]
    endTime = [4]
    queryTime = 4
    res = 1
    assert(res == Solution().busyStudent(startTime, endTime, queryTime))
    
    /**
     输入：startTime = [4], endTime = [4], queryTime = 5
     输出：0
     */
    startTime = [4]
    endTime = [4]
    queryTime = 5
    res = 0
    assert(res == Solution().busyStudent(startTime, endTime, queryTime))
    
    /**
     输入：startTime = [1,1,1,1], endTime = [1,3,2,4], queryTime = 7
     输出：0
     */
    startTime = [1,1,1,1]
    endTime = [1,3,2,4]
    queryTime = 7
    res = 0
    assert(res == Solution().busyStudent(startTime, endTime, queryTime))
    
    /**
     输入：startTime = [9,8,7,6,5,4,3,2,1], endTime = [10,10,10,10,10,10,10,10,10], queryTime = 5
     输出：5
     */
    startTime = [9,8,7,6,5,4,3,2,1]
    endTime = [10,10,10,10,10,10,10,10,10]
    queryTime = 5
    res = 5
    assert(res == Solution().busyStudent(startTime, endTime, queryTime))
}
