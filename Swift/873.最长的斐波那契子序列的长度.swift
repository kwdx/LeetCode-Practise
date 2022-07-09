/*
 * @lc app=leetcode.cn id=873 lang=swift
 *
 * [873] 最长的斐波那契子序列的长度
 */

import Darwin

// @lc code=start
class Solution {
    func lenLongestFibSubseq(_ arr: [Int]) -> Int {
        var ans = 0
        let n = arr.count
        var map: [Int: Int] = [:]
        for i in 0..<n {
            map[arr[i]] = i
        }
        var f: [[Int]] = .init(repeating: .init(repeating: 0, count: n), count: n)
        for i in 0..<n {
            var j = i - 1
            while j >= 0 && j + 2 > ans {
                if arr[i] - arr[j] >= arr[j] {
                    break
                }
                if let t = map[arr[i] - arr[j]] {
                    f[i][j] = max(3, f[j][t] + 1)
                    ans = max(ans, f[i][j])
                }
                j -= 1
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var arr: [Int]
    var res: Int
    
    /**
     输入: arr = [1,2,3,4,5,6,7,8]
     输出: 5
     解释: 最长的斐波那契式子序列为 [1,2,3,5,8] 。
     */
    arr = [1,2,3,4,5,6,7,8]
    res = 5
    assert(res == Solution().lenLongestFibSubseq(arr))
    
    /**
     输入: arr = [1,3,7,11,12,14,18]
     输出: 3
     解释: 最长的斐波那契式子序列有 [1,11,12]、[3,11,14] 以及 [7,11,18] 。
     */
    arr = [1,3,7,11,12,14,18]
    res = 3
    assert(res == Solution().lenLongestFibSubseq(arr))
}
