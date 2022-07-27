/*
 * @lc app=leetcode.cn id=592 lang=swift
 *
 * [592] 分数加减运算
 */

// @lc code=start
class Solution {
    func fractionAddition(_ expression: String) -> String {
        var denominator = 0     // 分子
        var numerator = 1       // 分母
        let chars = Array(expression)
        var index = 0
        while index < chars.count {
            // 读取分子
            var denominator1 = 0, sign = 1
            if chars[index] == "-" || chars[index] == "+" {
                sign = chars[index] == "-" ? -1 : 1
                index += 1
            }
            while index < chars.count && chars[index].isNumber {
                denominator1 = denominator1 * 10 + chars[index].wholeNumberValue!
                index += 1
            }
            denominator1 = sign * denominator1;
            index += 1
            
            // 读取分母
            var numerator1 = 0
            while index < chars.count && chars[index].isNumber {
                numerator1 = numerator1 * 10 + chars[index].wholeNumberValue!
                index += 1
            }
            
            denominator = denominator * numerator1 + denominator1 * numerator;
            numerator *= numerator1;
        }
        if denominator == 0 {
            return "0/1"
        }
        let g = gcd(abs(denominator), numerator);
        return "\(denominator / g)/\(numerator / g)"
    }
    
    private func gcd(_ a: Int, _ b: Int) -> Int {
        let r = a % b
        return r == 0 ? b : gcd(b, r)
    }
}
// @lc code=end

func main() {
    var expression: String
    var res: String
    
    /**
     输入: expression = "-1/2+1/2"
     输出: "0/1"
     */
    expression = "-1/2+1/2"
    res = "0/1"
    assert(res == Solution().fractionAddition(expression))
    
    /**
     输入: expression = "-1/2+1/2+1/3"
     输出: "1/3"
     */
    expression = "-1/2+1/2+1/3"
    res = "1/3"
    assert(res == Solution().fractionAddition(expression))
    
    /**
     输入: expression = "1/3-1/2"
     输出: "-1/6"
     */
    expression = "1/3-1/2"
    res = "-1/6"
    assert(res == Solution().fractionAddition(expression))
}
