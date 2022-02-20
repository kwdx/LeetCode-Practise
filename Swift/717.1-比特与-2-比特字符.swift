/*
 * @lc app=leetcode.cn id=717 lang=swift
 *
 * [717] 1比特与2比特字符
 */

// @lc code=start
class Solution {
    func isOneBitCharacter(_ bits: [Int]) -> Bool {
        var idx = 0
        while idx < bits.count - 1 {
            if bits[idx] == 0 {
                idx += 1
            } else {
                idx += 2
            }
        }
        return idx == bits.count - 1
    }
}
// @lc code=end

func main() {
    var bits: [Int]
    var res: Bool
    
    /**
     输入: bits = [1, 0, 0]
     输出: true
     解释: 唯一的编码方式是一个两比特字符和一个一比特字符。
     所以最后一个字符是一比特字符。
     */
    bits = [1, 0, 0]
    res = true
    assert(res == Solution().isOneBitCharacter(bits))
    
    /**
     输入: bits = [1, 1, 1, 0]
     输出: false
     解释: 唯一的编码方式是两比特字符和两比特字符。
     所以最后一个字符不是一比特字符。
     */
    bits = [1, 1, 1, 0]
    res = false
    assert(res == Solution().isOneBitCharacter(bits))
}
