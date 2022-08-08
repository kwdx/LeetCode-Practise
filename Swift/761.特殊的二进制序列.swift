/*
 * @lc app=leetcode.cn id=761 lang=swift
 *
 * [761] 特殊的二进制序列
 */

// @lc code=start
class Solution {
    func makeLargestSpecial(_ s: String) -> String {
        if s.count == 0 { return "" }
        
        var subStrs = [String]()
        let chars = Array(s)
        var (count, lastIndex) = (0, 0)
        
        func subString(_ lowerBound: Int, _ upperBound: Int) -> String {
            if lowerBound > upperBound { return "" }
            return String(s[s.index(s.startIndex, offsetBy: lowerBound) ..<
                            s.index(s.startIndex, offsetBy: upperBound)])
        }
        
        for i in 0 ..< s.count {
            count += chars[i] == "1" ? 1 : -1
            if count == 0 {
                subStrs.append("1" + makeLargestSpecial(subString(lastIndex + 1, i)) + "0")
                lastIndex = i + 1
            }
        }
        return subStrs.sorted(by: >).joined()
    }
}
// @lc code=end

func main() {
    var s: String
    var res: String
    
    /**
     输入: S = "11011000"
     输出: "11100100"
     解释:
     将子串 "10" （在S[1]出现） 和 "1100" （在S[3]出现）进行交换。
     这是在进行若干次操作后按字典序排列最大的结果。
     */
    s = "11011000"
    res = "11100100"
    assert(res == Solution().makeLargestSpecial(s))
}
