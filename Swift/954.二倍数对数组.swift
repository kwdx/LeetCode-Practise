/*
 * @lc app=leetcode.cn id=954 lang=swift
 *
 * [954] 二倍数对数组
 */

// @lc code=start
class Solution {
    func canReorderDoubled(_ arr: [Int]) -> Bool {
        var cnt: [Int: Int] = [:]
        for x in arr {
            cnt[x] = 1 + (cnt[x] ?? 0)
        }
        
        if (cnt[0] ?? 0) & 1 == 1 {
            return false
        }
        let vals: [Int] = cnt.keys.sorted(by: { abs($0) < abs($1)})
        for x in vals {
            if (cnt[2 * x] ?? 0) < (cnt[x] ?? 0) {
                return false
            }
            cnt[2 * x] = (cnt[2 * x] ?? 0) - (cnt[x] ?? 0)
        }
        
        return true
    }
}
// @lc code=end

func main() {
    var arr: [Int]
    var res: Bool
    
    /**
     输入：arr = [3,1,3,6]
     输出：false
     */
    arr = [3,1,3,6]
    res = false
    assert(res == Solution().canReorderDoubled(arr))
    
    /**
     输入：arr = [2,1,2,6]
     输出：false
     */
    arr = [2,1,2,6]
    res = false
    assert(res == Solution().canReorderDoubled(arr))
    
    /**
     输入：arr = [4,-2,2,-4]
     输出：true
     解释：可以用 [-2,-4] 和 [2,4] 这两组组成 [-2,-4,2,4] 或是 [2,4,-2,-4]
     */
    arr = [4,-2,2,-4]
    res = true
    assert(res == Solution().canReorderDoubled(arr))
}
