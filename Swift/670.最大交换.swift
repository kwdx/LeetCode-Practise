/*
 * @lc app=leetcode.cn id=670 lang=swift
 *
 * [670] 最大交换
 */

// @lc code=start
class Solution {
    func maximumSwap(_ num: Int) -> Int {
        var chars = Array(String(num))
        let n = chars.count
        var maxIdx = n - 1
        var idx1 = -1, idx2 = -1
        for i in (0..<n).reversed() {
            if chars[i] > chars[maxIdx] {
                maxIdx = i
            } else if chars[i] < chars[maxIdx] {
                idx1 = i
                idx2 = maxIdx
            }
        }
        if idx1 >= 0 {
            chars.swapAt(idx1, idx2)
            return Int(String(chars))!
        }
        return num
    }
}
// @lc code=end

func main() {
    var num: Int
    var res: Int
    
    /**
     输入: 2736
     输出: 7236
     解释: 交换数字2和数字7。
     */
    num = 2736
    res = 7236
    assert(res == Solution().maximumSwap(num))
    
    /**
     输入: 9973
     输出: 9973
     解释: 不需要交换。
     */
    num = 9973
    res = 9973
    assert(res == Solution().maximumSwap(num))
}
