/*
 * @lc app=leetcode.cn id=306 lang=swift
 *
 * [306] 累加数
 */

// @lc code=start
class Solution {
    private var num: [Int] = []
    private var n: Int = 0
    private var list: [[Int]] = []
    
    func isAdditiveNumber(_ num: String) -> Bool {
        self.num = num.map { Int($0.asciiValue!) }
        n = num.count
        return dfs(0)
    }
    
    func dfs(_ idx: Int) -> Bool {
        // 现在已经确定的数字数量
        let m = list.count
        if idx == n {
            return m >= 3
        }
        // 判断 '0' 的情况
        let max = num[idx] == 48 ? idx + 1 : n
        var cur: [Int] = []
        for i in idx..<max {
            cur.insert(num[i] - 48, at: 0)
            if (m < 2 || check(list[m - 2], list[m - 1], cur)){
                // 回溯
                list.append(cur)
                if dfs(i + 1) {
                    return true
                }
                list.removeLast()
            }
        }
        return false
    }
    
    func check(_ a: [Int], _ b: [Int], _ c: [Int]) -> Bool {
        var sum: [Int] = []
        let m = a.count
        let n = b.count
        let x = c.count
        if x < m || x < n {
            return false
        }
        var carry = 0
        for i in 0..<max(m, n) {
            if i < m {
                carry += a[i]
            }
            if i < n {
                carry += b[i]
            }
            sum.append(carry % 10)
            carry /= 10
        }
        while carry != 0 {
            sum.append(carry % 10)
            carry /= 10
        }
        return c == sum
    }
}
// @lc code=end

func main() {
    var num: String
    var res: Bool
    
    /**
     输入："112358"
     输出：true
     解释：累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
     */
    num = "112358"
    res = true
    assert(res == Solution().isAdditiveNumber(num))
    
    /**
     输入："199100199"
     输出：true
     解释：累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199
     */
    num = "199100199"
    res = true
    assert(res == Solution().isAdditiveNumber(num))
}
