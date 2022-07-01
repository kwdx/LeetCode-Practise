/*
 * @lc app=leetcode.cn id=241 lang=swift
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
class Solution {
    var chars: [Character] = []
    private var caches: [ClosedRange<Int>: [Int]] = [:]
    func diffWaysToCompute(_ expression: String) -> [Int] {
        self.chars = Array(expression)
        return dfs(0, expression.count - 1)
    }
    
    func dfs(_ l: Int, _ r: Int) -> [Int] {
        guard r >= l else { return [] }
        if let cache = caches[l...r] {
            return cache
        }
        var ans: [Int] = []
        for i in l...r {
            if ("0"..."9").contains(chars[i]) {
                continue
            }
            let num1 = dfs(l, i - 1), num2 = dfs(i + 1, r)
            for a in num1 {
                for b in num2 {
                    var cur = 0
                    switch chars[i] {
                    case "+":
                        cur = a + b
                    case "-":
                        cur = a - b
                    default:
                        cur = a * b
                    }
                    ans.append(cur)
                }
            }
        }
        if ans.isEmpty {
            ans.append(Int(String(chars[l...r]))!)
        }
        caches[l...r] = ans
        return ans
    }
}
// @lc code=end

func main() {
    var expression: String
    var res: [Int]
    
    /**
     输入：expression = "2-1-1"
     输出：[0,2]
     解释：
     ((2-1)-1) = 0
     (2-(1-1)) = 2
     */
    expression = "2-1-1"
    res = [0,2]
    assert(res == Solution().diffWaysToCompute(expression))
    
    /**
     输入：expression = "2*3-4*5"
     输出：[-34,-14,-10,-10,10]
     解释：
     (2*(3-(4*5))) = -34
     ((2*3)-(4*5)) = -14
     ((2*(3-4))*5) = -10
     (2*((3-4)*5)) = -10
     (((2*3)-4)*5) = 10
     */
    expression = "2*3-4*5"
    res = [-34,-14,-10,-10,10]
    assert(res == Solution().diffWaysToCompute(expression))
}
