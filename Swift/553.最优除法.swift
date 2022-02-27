/*
 * @lc app=leetcode.cn id=553 lang=swift
 *
 * [553] 最优除法
 */

// @lc code=start
class Solution {
    func optimalDivision(_ nums: [Int]) -> String {
        guard nums.count > 0 else { return "" }
        
        if nums.count > 2 {
            return "\(nums[0])/(\(nums[1...].map { String($0) }.joined(separator: "/")))"
        } else if nums.count > 1 {
            return "\(nums[0])/\(nums[1])"
        } else {
            return String(nums[0])
        }
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: String
    
    /**
     输入: [1000,100,10,2]
     输出: "1000/(100/10/2)"
     解释:
     1000/(100/10/2) = 1000/((100/10)/2) = 200
     但是，以下加粗的括号 "1000/((100/10)/2)" 是冗余的，
     因为他们并不影响操作的优先级，所以你需要返回 "1000/(100/10/2)"。

     其他用例:
     1000/(100/10)/2 = 50
     1000/(100/(10/2)) = 50
     1000/100/10/2 = 0.5
     1000/100/(10/2) = 2
     */
    nums = [1000,100,10,2]
    res = "1000/(100/10/2)"
    assert(res == Solution().optimalDivision(nums))
}
