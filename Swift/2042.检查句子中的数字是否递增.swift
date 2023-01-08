/*
 * @lc app=leetcode.cn id=2042 lang=swift
 *
 * [2042] 检查句子中的数字是否递增
 */

// @lc code=start
class Solution {
    func areNumbersAscending(_ s: String) -> Bool {
        let nums = s.split(separator: " ").compactMap { Int($0) }
        var pre = 0
        for num in nums {
            if num <= pre {
                return false
            }
            pre = num
        }
        return true
    }
}
// @lc code=end

func main() {
    var s: String
    var res: Bool
    
    /**
     输入：s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles"
     输出：true
     解释：句子中的数字是：1, 3, 4, 6, 12 。
     这些数字是按从左到右严格递增的 1 < 3 < 4 < 6 < 12 。
     */
    s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles"
    res = true
    assert(res == Solution().areNumbersAscending(s))
    
    /**
     输入：s = "hello world 5 x 5"
     输出：false
     解释：句子中的数字是：5, 5 。这些数字不是严格递增的。
     */
    s = "hello world 5 x 5"
    res = false
    assert(res == Solution().areNumbersAscending(s))
    
    /**
     输入：s = "sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s"
     输出：false
     解释：s 中的数字是：7, 51, 50, 60 。这些数字不是严格递增的。
     */
    s = "hello world 5 x 5"
    res = false
    assert(res == Solution().areNumbersAscending(s))
}
