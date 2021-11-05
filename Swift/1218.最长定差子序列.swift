/*
 * @lc app=leetcode.cn id=1218 lang=swift
 *
 * [1218] 最长定差子序列
 */

// @lc code=start
class Solution {
    func longestSubsequence(_ arr: [Int], _ difference: Int) -> Int {
        var numToLengths: [Int: Int] = [:]
        var ans = 0
        for num in arr {
            var len = numToLengths[num - difference] ?? 0
            len += 1
            numToLengths[num] = len
            ans = max(ans, len)
        }
        return ans
    }
}
// @lc code=end

func main() {
    var arr: [Int]
    var difference: Int
    var res: Int

    /**
     输入：arr = [1,2,3,4], difference = 1
     输出：4
     解释：最长的等差子序列是 [1,2,3,4]。
     */
    arr = [1,2,3,4]
    difference = 1
    res = 4
    assert(res == Solution().longestSubsequence(arr, difference))

    /**
     输入：arr = [1,3,5,7], difference = 1
     输出：1
     解释：最长的等差子序列是任意单个元素。
     */
    arr = [1,3,5,7]
    difference = 1
    res = 1
    assert(res == Solution().longestSubsequence(arr, difference))

    /**
     输入：arr = [1,5,7,8,5,3,4,2,1], difference = -2
     输出：4
     解释：最长的等差子序列是 [7,5,3,1]。
     */
    arr = [1,5,7,8,5,3,4,2,1]
    difference = -2
    res = 4
    assert(res == Solution().longestSubsequence(arr, difference))
}
