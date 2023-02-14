/*
 * @lc app=leetcode.cn id=1124 lang=swift
 *
 * [1124] 表现良好的最长时间段
 */

// @lc code=start
class Solution {
    func longestWPI(_ hours: [Int]) -> Int {
        var s = [Int](repeating: 0, count: hours.count + 1)
        var st: [Int] = [0]
        for i in 1...hours.count {
            s[i] = s[i - 1] + (hours[i - 1] > 8 ? 1 : -1)
            if s[st.last!] > s[i] {
                st.append(i)
            }
        }
        var ans = 0
        for i in (1...hours.count).reversed() {
            while let top = st.last, s[top] < s[i] {
                ans = max(ans, i - top)
                st.removeLast()
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var hours: [Int]
    var res: Int
    
    /**
     输入：hours = [9,9,6,0,6,6,9]
     输出：3
     解释：最长的表现良好时间段是 [9,9,6]。
     */
    hours = [9,9,6,0,6,6,9]
    res = 3
    assert(res == Solution().longestWPI(hours))
    
    /**
     输入：hours = [6,6,6]
     输出：0
     */
    hours = [6,6,6]
    res = 0
    assert(res == Solution().longestWPI(hours))
}
