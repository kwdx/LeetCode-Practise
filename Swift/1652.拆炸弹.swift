/*
 * @lc app=leetcode.cn id=1652 lang=swift
 *
 * [1652] 拆炸弹
 */

// @lc code=start
class Solution {
    func decrypt(_ code: [Int], _ k: Int) -> [Int] {
        let n = code.count
        var ans = [Int](repeating: 0, count: n)
        if k == 0 {
            return ans
        }
        var sum = [Int](repeating: 0, count: 2 * n + 1)
        for i in 1...(2 * n) {
            sum[i] += sum[i - 1] + code[(i - 1) % n]
        }
        for i in 1...n {
            if k < 0 {
                ans[i - 1] = sum[i + n - 1] - sum[i + n + k - 1]
            } else {
                ans[i - 1] = sum[i + k] - sum[i]
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var code: [Int]
    var k: Int
    var res: [Int]
    
    /**
     输入：code = [5,7,1,4], k = 3
     输出：[12,10,16,13]
     解释：每个数字都被接下来 3 个数字之和替换。解密后的密码为 [7+1+4, 1+4+5, 4+5+7, 5+7+1]。注意到数组是循环连接的。
     */
    code = [5,7,1,4]
    k = 3
    res = [12,10,16,13]
    assert(res == Solution().decrypt(code, k))
    
    /**
     输入：code = [1,2,3,4], k = 0
     输出：[0,0,0,0]
     解释：当 k 为 0 时，所有数字都被 0 替换。
     */
    code = [1,2,3,4]
    k = 0
    res = [0,0,0,0]
    assert(res == Solution().decrypt(code, k))
    
    /**
     输入：code = [2,4,9,3], k = -2
     输出：[12,5,6,13]
     解释：解密后的密码为 [3+9, 2+3, 4+2, 9+4] 。注意到数组是循环连接的。如果 k 是负数，那么和为 之前 的数字。
     */
    code = [2,4,9,3]
    k = -2
    res = [12,5,6,13]
    assert(res == Solution().decrypt(code, k))
}
