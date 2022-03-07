/*
 * @lc app=leetcode.cn id=504 lang=swift
 *
 * [504] 七进制数
 */

// @lc code=start
class Solution {
    func convertToBase7(_ num: Int) -> String {
        var ans = ""
        let flag = num < 0
        var num_ = abs(num)
        
        repeat {
            ans = "\(num_ % 7)" + ans
            num_ /= 7
        } while num_ != 0
        
        if flag {
            ans = "-" + ans
        }
        return ans
    }
}
// @lc code=end

func main() {
    var num: Int
    var res: String
    
    /**
     输入: num = 100
     输出: "202"
     */
    num = 100
    res = "202"
    assert(res == Solution().convertToBase7(num))
    
    /**
     输入: num = -7
     输出: "-10"
     */
    num = -7
    res = "-10"
    assert(res == Solution().convertToBase7(num))
}
