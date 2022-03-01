/*
 * @lc app=leetcode.cn id=6 lang=swift
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
    func convert(_ s: String, _ numRows: Int) -> String {
        guard numRows > 1 else { return s }
        let step = (numRows - 1) << 1;
        var ans: [Character] = []
        let chars = Array(s)
        for i in 0..<numRows {
            for j in stride(from: i, to: s.count, by: step) {
                ans.append(chars[j])
                let next = j + step - i * 2
                if i > 0 && i < numRows - 1 && next < s.count {
                    ans.append(chars[next])
                }
            }
        }
        return String(ans)
    }
}
// @lc code=end

func main() {
    var s: String
    var numRows: Int
    var res: String
    
    /**
     输入：s = "PAYPALISHIRING", numRows = 3
     输出："PAHNAPLSIIGYIR"
     */
    s = "PAYPALISHIRING"
    numRows = 3
    res = "PAHNAPLSIIGYIR"
    assert(res == Solution().convert(s, numRows))
    
    /**
     输入：s = "PAYPALISHIRING", numRows = 4
     输出："PINALSIGYAHRPI"
     解释：
     P     I    N
     A   L S  I G
     Y A   H R
     P     I
     */
    s = "PAYPALISHIRING"
    numRows = 4
    res = "PINALSIGYAHRPI"
    assert(res == Solution().convert(s, numRows))
    
    /**
     输入：s = "A", numRows = 1
     输出："A"
     */
    s = "A"
    numRows = 1
    res = "A"
    assert(res == Solution().convert(s, numRows))
}
