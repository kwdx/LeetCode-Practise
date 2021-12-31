/*
 * @lc app=leetcode.cn id=825 lang=swift
 *
 * [825] 适龄的朋友
 */

// @lc code=start
class Solution {
    func numFriendRequests(_ ages: [Int]) -> Int {
        let ages_ = ages.sorted()
        var left = 0, right = 0
        var ans = 0
        for i in 0..<ages_.count {
            while left < i && !check(ages_[left], ages_[i]) {
                left += 1
            }
            if (right < i) {
                right = i
            }
            while right < ages_.count && check(ages_[right], ages_[i]) {
                right += 1
            }
            if (right > left) {
                ans += right - left - 1
            }
        }
        return ans
    }
    
    private func check(_ x: Int, _ y: Int) -> Bool {
        if y <= (x >> 1) + 7 {
            return false
        }
        if y > x {
            return false
        }
        if y > 100 && x < 100 {
            return false
        }
        return true
    }
}
// @lc code=end

func main() {
    var ages: [Int]
    var res: Int
    
    /**
     输入：ages = [16,16]
     输出：2
     解释：2 人互发好友请求。
     */
    ages = [16,16]
    res = 2
    assert(res == Solution().numFriendRequests(ages))
    
    /**
     输入：ages = [16,17,18]
     输出：2
     解释：产生的好友请求为 17 -> 16 ，18 -> 17 。
     */
    ages = [16,17,18]
    res = 2
    assert(res == Solution().numFriendRequests(ages))
    
    /**
     输入：ages = [20,30,100,110,120]
     输出：3
     解释：产生的好友请求为 110 -> 100 ，120 -> 110 ，120 -> 100 。
     */
    ages = [20,30,100,110,120]
    res = 3
    assert(res == Solution().numFriendRequests(ages))
}
