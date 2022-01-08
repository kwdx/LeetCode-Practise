/*
 * @lc app=leetcode.cn id=89 lang=swift
 *
 * [89] 格雷编码
 */

// @lc code=start
class Solution {
    func grayCode(_ n: Int) -> [Int] {
        var ans: [Int] = []
        ans.append(0)
        var head = 1
        for _ in 0..<n {
//            ans.append(contentsOf: (0..<ans.count).reversed().map { head + ans[$0] })
            for j in (0..<ans.count).reversed() {
                ans.append(head + ans[j])
            }
            head <<= 1
        }
        return ans
    }
}
// @lc code=end

func main() {
    var n: Int
    var res: [Int]
    
    /**
     输入：n = 2
     输出：[0,1,3,2]
     解释：
     [0,1,3,2] 的二进制表示是 [00,01,11,10] 。
     - 00 和 01 有一位不同
     - 01 和 11 有一位不同
     - 11 和 10 有一位不同
     - 10 和 00 有一位不同
     [0,2,3,1] 也是一个有效的格雷码序列，其二进制表示是 [00,10,11,01] 。
     - 00 和 10 有一位不同
     - 10 和 11 有一位不同
     - 11 和 01 有一位不同
     - 01 和 00 有一位不同
     */
    n = 2
    res = [0,1,3,2]
    assert(res == Solution().grayCode(n))
    
    /**
     输入：n = 1
     输出：[0,1]
     */
    n = 1
    res = [0,1]
    assert(res == Solution().grayCode(n))
}
