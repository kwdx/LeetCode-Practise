/*
 * @lc app=leetcode.cn id=640 lang=swift
 *
 * [640] 求解方程
 */

// @lc code=start
class Solution {
    func solveEquation(_ equation: String) -> String {
        var factor = 0, val = 0
        var index = 0, sign1 = 1
        let chars = Array(equation)
        while index < chars.count {
            if chars[index] == "=" {
                sign1 = -1  // 等式右边默认系数为负
                index += 1
                continue
            }
            var sign2 = sign1, number = 0
            var valid = false  // 记录 number 是否有效
            if chars[index] == "-" || chars[index] == "+" { // 去掉前面的符号
                sign2 = chars[index] == "-" ? -sign1 : sign1
                index += 1
            }
            while index < chars.count && chars[index].isNumber {
                number = number * 10 + chars[index].wholeNumberValue!
                index += 1
                valid = true
            }
            
            if index < chars.count && chars[index] == "x" { // 变量
                factor += valid ? sign2 * number : sign2
                index += 1
            } else { // 数值
                val += sign2 * number
            }
        }
        
        if factor == 0 {
            return val == 0 ? "Infinite solutions" : "No solution"
        }
        if val % factor != 0 {
            return "No solution"
        }
        return "x=\(-val / factor)"
    }
}
// @lc code=end

func main() {
    var equation: String
    var res: String
    
    /**
     输入: equation = "x+5-3+x=6+x-2"
     输出: "x=2"
     */
    equation = "x+5-3+x=6+x-2"
    res = "x=2"
    assert(res == Solution().solveEquation(equation))
    
    /**
     输入: equation = "x=x"
     输出: "Infinite solutions"
     */
    equation = "x+5-3+x=6+x-2"
    res = "x=2"
    assert(res == Solution().solveEquation(equation))

    /**
     输入: equation = "2x=x"
     输出: "x=0"
     */
    equation = "2x=x"
    res = "x=0"
    assert(res == Solution().solveEquation(equation))
}
