/*
 * @lc app=leetcode.cn id=784 lang=swift
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution {
    func letterCasePermutation(_ s: String) -> [String] {
        let n = s.count
        var m = 0
        let chars = Array(s)
        for c in chars {
            if !c.isNumber {
                m += 1
            }
        }
        var ans = [String]()
        for mask in 0..<(1<<m) {
            var str = ""
            var k = 0
            for j in 0..<n {
                if chars[j].isNumber {
                    str.append(chars[j])
                } else {
                    if mask & (1 << k) != 0 {
                        str.append(chars[j].uppercased())
                    } else {
                        str.append(chars[j].lowercased())
                    }
                    k += 1
                }
            }
            ans.append(str)
        }
        return ans
    }
}
// @lc code=end

func main() {
    var s: String
    var res: [String]
    
    /**
     输入：s = "a1b2"
     输出：["a1b2", "a1B2", "A1b2", "A1B2"]
     */
    s = "a1b2"
    res = ["a1b2", "a1B2", "A1b2", "A1B2"].sorted()
    assert(res == Solution().letterCasePermutation(s).sorted())
    
    /**
     输入: s = "3z4"
     输出: ["3z4","3Z4"]
     */
    s = "3z4"
    res = ["3z4","3Z4"].sorted()
    assert(res == Solution().letterCasePermutation(s).sorted())
}
