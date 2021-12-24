/*
 * @lc app=leetcode.cn id=475 lang=swift
 *
 * [475] 供暖器
 */

// @lc code=start
class Solution {
    func findRadius(_ houses: [Int], _ heaters: [Int]) -> Int {
        let houses_ = houses.sorted()
        let heaters_ = heaters.sorted()
        
        let n = houses_.count
        let m = heaters_.count
        let check: (Int) -> Bool = { r in
            var j = 0
            for i in 0..<n {
                while j < m && houses_[i] > heaters_[j] + r {
                    j += 1
                }
                if j < m && heaters_[j] - r <= houses_[i] && heaters_[j] + r >= houses_[i] {
                    continue
                }
                return false
            }
            return true
        }
        
        var l = 0, r = Int(1e9)
        while l < r {
            let mid = (l + r) >> 1
            if check(mid) {
                r = mid
            } else {
                l = mid + 1
            }
        }
        return r
    }
}
// @lc code=end

func main() {
    var houses: [Int]
    var heaters: [Int]
    var res: Int
    
    /**
     输入: houses = [1,2,3], heaters = [2]
     输出: 1
     解释: 仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖。
     */
    houses = [1,2,3]
    heaters = [2]
    res = 1
    assert(res == Solution().findRadius(houses, heaters))
    
    /**
     输入: houses = [1,2,3,4], heaters = [1,4]
     输出: 1
     解释: 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，这样所有房屋就都能得到供暖。
     */
    houses = [1,2,3,4]
    heaters = [1,4]
    res = 1
    assert(res == Solution().findRadius(houses, heaters))
    
    /**
     输入：houses = [1,5], heaters = [2]
     输出：3
     */
    houses = [1,5]
    heaters = [2]
    res = 3
    assert(res == Solution().findRadius(houses, heaters))
}
