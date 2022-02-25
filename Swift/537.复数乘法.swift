/*
 * @lc app=leetcode.cn id=537 lang=swift
 *
 * [537] 复数乘法
 */

// @lc code=start
class Solution {
    func complexNumberMultiply(_ num1: String, _ num2: String) -> String {
        let split: (String) -> (Int, Int) = { num in
            var arr = num.components(separatedBy: "+")
            arr[1].removeLast()
            return (Int(arr[0])!, Int(arr[1])!)
        }
        let (a, b) = split(num1)
        let (c, d) = split(num2)
        return "\(a * c - b * d)+\(a * d + b * c)i"
    }
}
// @lc code=end

func main() {
    var num1: String
    var num2: String
    var res: String
    
    /**
     输入：num1 = "1+1i", num2 = "1+1i"
     输出："0+2i"
     解释：(1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。
     */
    num1 = "1+1i"
    num2 = "1+1i"
    res = "0+2i"
    assert(res == Solution().complexNumberMultiply(num1, num2))
    
    /**
     输入：num1 = "1+-1i", num2 = "1+-1i"
     输出："0+-2i"
     解释：(1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。
     */
    num1 = "1+-1i"
    num2 = "1+-1i"
    res = "0+-2i"
    assert(res == Solution().complexNumberMultiply(num1, num2))
}
