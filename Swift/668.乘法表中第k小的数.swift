/*
 * @lc app=leetcode.cn id=668 lang=swift
 *
 * [668] 乘法表中第k小的数
 */

// @lc code=start
class Solution {
    func findKthNumber(_ m: Int, _ n: Int, _ k: Int) -> Int {
        var l = 1, r = m * n + 1
        while l < r {
            let mid = l + (r - l) / 2
            var cnt = 0
            for i in 1...m {
                cnt += mid / i >= n ? n : mid / i
            }
            if cnt >= k {
                r = mid
            } else {
                l = mid + 1
            }
        }
        return l
    }
}
// @lc code=end

func main() {
    var m: Int
    var n: Int
    var k: Int
    var res: Int
    
    /**
     输入: m = 3, n = 3, k = 5
     输出: 3
     解释:
     乘法表:
     1    2    3
     2    4    6
     3    6    9

     第5小的数字是 3 (1, 2, 2, 3, 3).
     */
    m = 3
    n = 3
    k = 5
    res = 3
//    assert(res == Solution().findKthNumber(m, n, k))
    
    /**
     输入: m = 2, n = 3, k = 6
     输出: 6
     解释:
     乘法表:
     1    2    3
     2    4    6

     第6小的数字是 6 (1, 2, 2, 3, 4, 6).
     */
    m = 2
    n = 3
    k = 6
    res = 6
    assert(res == Solution().findKthNumber(m, n, k))
}
