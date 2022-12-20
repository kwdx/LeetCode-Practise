/*
 * @lc app=leetcode.cn id=1945 lang=swift
 *
 * [1945] 字符串转化后的各位数字之和
 */

// @lc code=start
class Solution {
    func getLucky(_ s: String, _ k: Int) -> Int {
        var s = s.map { String($0.asciiValue! - 96) }.joined()
        var i = 1
        while i <= k && s.count > 1 {
            var sum = 0
            for c in s {
                sum += c.wholeNumberValue!
            }
            s = String(sum)
            i += 1
        }
        return Int(s)!
    }
}
// @lc code=end

func main() {
    var s: String
    var k: Int
    var res: Int
    
    /**
     输入：s = "iiii", k = 1
     输出：36
     解释：操作如下：
     - 转化："iiii" ➝ "(9)(9)(9)(9)" ➝ "9999" ➝ 9999
     - 转换 #1：9999 ➝ 9 + 9 + 9 + 9 ➝ 36
     因此，结果整数为 36 。
     */
    s = "iiii"
    k = 1
    res = 36
    assert(res == Solution().getLucky(s, k))
    
    /**
     输入：s = "leetcode", k = 2
     输出：6
     解释：操作如下：
     - 转化："leetcode" ➝ "(12)(5)(5)(20)(3)(15)(4)(5)" ➝ "12552031545" ➝ 12552031545
     - 转换 #1：12552031545 ➝ 1 + 2 + 5 + 5 + 2 + 0 + 3 + 1 + 5 + 4 + 5 ➝ 33
     - 转换 #2：33 ➝ 3 + 3 ➝ 6
     因此，结果整数为 6 。
     */
    s = "leetcode"
    k = 2
    res = 6
    assert(res == Solution().getLucky(s, k))
}
