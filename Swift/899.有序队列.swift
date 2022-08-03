/*
 * @lc app=leetcode.cn id=899 lang=swift
 *
 * [899] 有序队列
 */

// @lc code=start
class Solution {
    func orderlyQueue(_ s: String, _ k: Int) -> String {
        if k > 1 {
            return String(s.sorted())
        }
        var ans = s
        var str = s
        for _ in 1..<s.count {
            str.append(str.removeFirst())
            if str < ans {
                ans = str
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var s: String
    var k: Int
    var res: String
    
    /**
     输入：s = "cba", k = 1
     输出："acb"
     解释：
     在第一步中，我们将第一个字符（“c”）移动到最后，获得字符串 “bac”。
     在第二步中，我们将第一个字符（“b”）移动到最后，获得最终结果 “acb”。
     */
    s = "cba"
    k = 1
    res = "acb"
    assert(res == Solution().orderlyQueue(s, k))
    
    /**
     输入：s = "baaca", k = 3
     输出："aaabc"
     解释：
     在第一步中，我们将第一个字符（“b”）移动到最后，获得字符串 “aacab”。
     在第二步中，我们将第三个字符（“c”）移动到最后，获得最终结果 “aaabc”。
     */
    s = "baaca"
    k = 3
    res = "aaabc"
    assert(res == Solution().orderlyQueue(s, k))
}
