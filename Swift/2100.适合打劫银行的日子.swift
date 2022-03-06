/*
 * @lc app=leetcode.cn id=2100 lang=swift
 *
 * [2100] 适合打劫银行的日子
 */

// @lc code=start
class Solution {
    func goodDaysToRobBank(_ security: [Int], _ time: Int) -> [Int] {
        guard security.count > time * 2 else { return [] }
        var g = [Int](repeating: 0, count: security.count)
        for i in 1..<security.count {
            if security[i] != security[i - 1] {
                g[i] = security[i] > security[i - 1] ? 1 : -1
            }
        }
        var a = [Int](repeating: 0, count: security.count + 1)
        var b = [Int](repeating: 0, count: security.count + 1)
        for i in 1...security.count {
            a[i] = a[i - 1] + (g[i - 1] == 1 ? 1 : 0)
            b[i] = b[i - 1] + (g[i - 1] == -1 ? 1 : 0)
        }
        return (time..<(security.count-time)).compactMap { i in
            if a[i + 1] - a[i + 1 - time] == 0,
               b[i + 1 + time] - b[i + 1] == 0 {
                return i
            }
            return nil
        }
    }
}
// @lc code=end

func main() {
    var security: [Int]
    var time: Int
    var res: [Int]
    
    /**
     输入：security = [5,3,3,3,5,6,2], time = 2
     输出：[2,3]
     解释：
     第 2 天，我们有 security[0] >= security[1] >= security[2] <= security[3] <= security[4] 。
     第 3 天，我们有 security[1] >= security[2] >= security[3] <= security[4] <= security[5] 。
     没有其他日子符合这个条件，所以日子 2 和 3 是适合打劫银行的日子。
     */
    security = [5,3,3,3,5,6,2]
    time = 2
    res = [2,3]
    assert(res == Solution().goodDaysToRobBank(security, time))
    
    /**
     输入：security = [1,1,1,1,1], time = 0
     输出：[0,1,2,3,4]
     解释：
     因为 time 等于 0 ，所以每一天都是适合打劫银行的日子，所以返回每一天。
     */
    security = [1,1,1,1,1]
    time = 0;
    res = [0,1,2,3,4]
    assert(res == Solution().goodDaysToRobBank(security, time))
    
    /**
     输入：security = [1,2,3,4,5,6], time = 2
     输出：[]
     解释：
     没有任何一天的前 2 天警卫数目是非递增的。
     所以没有适合打劫银行的日子，返回空数组。
     */
    security = [1,2,3,4,5,6]
    time = 2
    res = []
    assert(res == Solution().goodDaysToRobBank(security, time))
    
    /**
     输入：security = [1], time = 5
     输出：[]
     解释：
     没有日子前面和后面有 5 天时间。
     所以没有适合打劫银行的日子，返回空数组。
     */
    security = [1]
    time = 5
    res = []
    assert(res == Solution().goodDaysToRobBank(security, time))
}
