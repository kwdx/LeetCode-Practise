/*
 * @lc app=leetcode.cn id=1694 lang=swift
 *
 * [1694] 重新格式化电话号码
 */

// @lc code=start
class Solution {
    func reformatNumber(_ number: String) -> String {
        var number = number.filter { $0.isNumber }
        var ans = ""
        while !number.isEmpty {
            if number.count > 4 {
                ans += "\(number.prefix(3))-"
                number.removeFirst(3)
            } else {
                if number.count == 4 {
                    ans += "\(number.prefix(2))-\(number.suffix(2))"
                } else {
                    ans += number
                }
                break
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var number: String
    var res: String
    
    /**
     输入：number = "1-23-45 6"
     输出："123-456"
     解释：数字是 "123456"
     步骤 1：共有超过 4 个数字，所以先取 3 个数字分为一组。第 1 个块是 "123" 。
     步骤 2：剩下 3 个数字，将它们放入单个含 3 个数字的块。第 2 个块是 "456" 。
     连接这些块后得到 "123-456" 。
     */
    number = "1-23-45 6"
    res = "123-456"
    assert(res == Solution().reformatNumber(number))
    
    /**
     输入：number = "123 4-567"
     输出："123-45-67"
     解释：数字是 "1234567".
     步骤 1：共有超过 4 个数字，所以先取 3 个数字分为一组。第 1 个块是 "123" 。
     步骤 2：剩下 4 个数字，所以将它们分成两个含 2 个数字的块。这 2 块分别是 "45" 和 "67" 。
     连接这些块后得到 "123-45-67" 。
     */
    number = "123 4-567"
    res = "123-45-67"
    assert(res == Solution().reformatNumber(number))
    
    /**
     输入：number = "123 4-5678"
     输出："123-456-78"
     解释：数字是 "12345678" 。
     步骤 1：第 1 个块 "123" 。
     步骤 2：第 2 个块 "456" 。
     步骤 3：剩下 2 个数字，将它们放入单个含 2 个数字的块。第 3 个块是 "78" 。
     连接这些块后得到 "123-456-78" 。
     */
    number = "123 4-5678"
    res = "123-456-78"
    assert(res == Solution().reformatNumber(number))
    
    /**
     输入：number = "12"
     输出："12"
     */
    number = "12"
    res = "12"
    assert(res == Solution().reformatNumber(number))
    
    /**
     输入：number = "--17-5 229 35-39475 "
     输出："175-229-353-94-75"
     */
    number =  "--17-5 229 35-39475 "
    res = "175-229-353-94-75"
    assert(res == Solution().reformatNumber(number))
}
