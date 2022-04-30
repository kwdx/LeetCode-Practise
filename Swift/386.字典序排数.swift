/*
 * @lc app=leetcode.cn id=386 lang=swift
 *
 * [386] 字典序排数
 */

// @lc code=start
class Solution {
    func lexicalOrder(_ n: Int) -> [Int] {
        var ans: [Int] = .init(repeating: 0, count: n)
        var num = 1
        for i in 0..<n {
            ans[i] = num
            if num * 10 <= n {
                num *= 10
            } else {
                while num % 10 == 9 || num + 1 > n {
                    num /= 10
                }
                num += 1
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var n: Int
    var res: [Int]
    
    /**
     输入：n = 13
     输出：[1,10,11,12,13,2,3,4,5,6,7,8,9]
     */
    n = 13
    res = [1,10,11,12,13,2,3,4,5,6,7,8,9]
    assert(res == Solution().lexicalOrder(n))
    
    /**
     输入：n = 2
     输出：[1,2]
     */
    n = 2
    res = [1,2]
    assert(res == Solution().lexicalOrder(n))
}
