/*
 * @lc app=leetcode.cn id=556 lang=swift
 *
 * [556] 下一个更大元素 III
 */

// @lc code=start
class Solution {
    func nextGreaterElement(_ n: Int) -> Int {
        var chars: [Character] = Array(String(n))
        var i = chars.count - 1
        var j = i
        while i > 0 && chars[i] <= chars[i - 1] {
            i -= 1
        }
        if i <= 0 {
            return -1
        }
        while chars[j] <= chars[i - 1] {
            j -= 1
        }
        chars.swapAt(i - 1, j)
        chars = Array(chars[0..<i]) + chars[i...].reversed()
        let ans = Int(String(chars)) ?? -1
        return ans > Int(Int32.max) ? -1 : ans
    }
}
// @lc code=end

func main() {
    var n: Int
    var res: Int
    
    n = 230241
    res = 230412
    assert(res == Solution().nextGreaterElement(n))
    
    /**
     输入：n = 12
     输出：21
     */
    n = 12
    res = 21
    assert(res == Solution().nextGreaterElement(n))
    
    /**
     输入：n = 21
     输出：-1
     */
    n = 21
    res = -1
    assert(res == Solution().nextGreaterElement(n))
}
