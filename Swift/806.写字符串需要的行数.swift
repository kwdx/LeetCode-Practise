/*
 * @lc app=leetcode.cn id=806 lang=swift
 *
 * [806] 写字符串需要的行数
 */

// @lc code=start
class Solution {
    func numberOfLines(_ widths: [Int], _ s: String) -> [Int] {
        var lines = 1, cnt = 0
        let chars = s.unicodeScalars.map { Int($0.value) - 97 }
        for c in chars {
            if cnt + widths[c] > 100 {
                // 换行
                cnt = 0
                lines += 1
            }
            cnt += widths[c]
        }
        return [lines, cnt]
    }
}
// @lc code=end

func main() {
    var widths: [Int]
    var s: String
    var res: [Int]
    
    /**
     输入:
     widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
     S = "abcdefghijklmnopqrstuvwxyz"
     输出: [3, 60]
     解释:
     所有的字符拥有相同的占用单位10。所以书写所有的26个字母，
     我们需要2个整行和占用60个单位的一行。
     */
    widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
    s = "abcdefghijklmnopqrstuvwxyz"
    res = [3, 60]
    assert(res == Solution().numberOfLines(widths, s))
    
    /**
     输入:
     widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
     S = "bbbcccdddaaa"
     输出: [2, 4]
     解释:
     除去字母'a'所有的字符都是相同的单位10，并且字符串 "bbbcccdddaa" 将会覆盖 9 * 10 + 2 * 4 = 98 个单位.
     最后一个字母 'a' 将会被写到第二行，因为第一行只剩下2个单位了。
     所以，这个答案是2行，第二行有4个单位宽度。
     */
    widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
    s = "bbbcccdddaaa"
    res = [2, 4]
    assert(res == Solution().numberOfLines(widths, s))
}
