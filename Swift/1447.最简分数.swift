/*
 * @lc app=leetcode.cn id=1447 lang=swift
 *
 * [1447] 最简分数
 */

// @lc code=start
class Solution {
    func gcd(_ a: Int, _ b: Int) -> Int {
        return b == 0 ? a : gcd(b, a % b)
    }
    
    func simplifiedFractions(_ n: Int) -> [String] {
        (1..<n)
            .flatMap { i in
                (i+1...n)
                    .compactMap { j in
                        if gcd(i, j) == 1 {
                            return "\(i)/\(j)"
                        } else {
                            return nil
                        }
                    }
            }
    }
}
// @lc code=end

func main() {
    var n: Int
    var res: [String]
    
    /**
     输入：n = 2
     输出：["1/2"]
     解释："1/2" 是唯一一个分母小于等于 2 的最简分数。
     */
    n = 2
    res = ["1/2"]
    assert(res == Solution().simplifiedFractions(n))
    
    /**
     输入：n = 3
     输出：["1/2","1/3","2/3"]
     */
    n = 3
    res = ["1/2","1/3","2/3"]
    assert(res == Solution().simplifiedFractions(n))
    
    /**
     输入：n = 4
     输出：["1/2","1/3","1/4","2/3","3/4"]
     解释："2/4" 不是最简分数，因为它可以化简为 "1/2" 。
     */
    n = 4
    res = ["1/2","1/3","1/4","2/3","3/4"]
    assert(res == Solution().simplifiedFractions(n))
    
    /**
     输入：n = 1
     输出：[]
     */
    n = 1
    res = []
    assert(res == Solution().simplifiedFractions(n))
}
