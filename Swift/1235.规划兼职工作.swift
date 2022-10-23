/*
 * @lc app=leetcode.cn id=1235 lang=swift
 *
 * [1235] 规划兼职工作
 */

// @lc code=start
class Solution {
    func jobScheduling(_ startTime: [Int], _ endTime: [Int], _ profit: [Int]) -> Int {
        let n = startTime.count
        var jobs = [(Int, Int, Int)]()
        for i in 0..<n {
            jobs.append((startTime[i], endTime[i], profit[i]))
        }
        jobs.sort { $0.1 < $1.1 }
        var dp = [Int](repeating: 0, count: n + 1)
        for i in 1...n {
            let k = jobs.prefix(i).firstIndex {
                $0.1 > jobs[i - 1].0
            } ?? 0
            dp[i] = max(dp[i - 1], dp[k] + jobs[i - 1].2)
        }
        return dp[n]
    }
}
// @lc code=end

func main() {
    var startTime: [Int]
    var endTime: [Int]
    var profit: [Int]
    var res: Int
    
    /**
     输入：startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
     输出：120
     解释：
     我们选出第 1 份和第 4 份工作，
     时间范围是 [1-3]+[3-6]，共获得报酬 120 = 50 + 70。
     */
    startTime = [1,2,3,3]
    endTime = [3,4,5,6]
    profit = [50,10,40,70]
    res = 120
    assert(res == Solution().jobScheduling(startTime, endTime, profit))
    
    /**
     输入：startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
     输出：150
     解释：
     我们选择第 1，4，5 份工作。
     共获得报酬 150 = 20 + 70 + 60。
     */
    startTime = [1,2,3,4,6]
    endTime = [3,5,10,6,9]
    profit = [20,20,100,70,60]
    res = 150
    assert(res == Solution().jobScheduling(startTime, endTime, profit))
    
    /**
     输入：startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
     输出：6
     */
    startTime = [1,1,1]
    endTime = [2,3,4]
    profit = [5,6,4]
    res = 6
    assert(res == Solution().jobScheduling(startTime, endTime, profit))
}
