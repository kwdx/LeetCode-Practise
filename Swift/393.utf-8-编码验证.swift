/*
 * @lc app=leetcode.cn id=393 lang=swift
 *
 * [393] UTF-8 编码验证
 */

// @lc code=start
class Solution {
    func validUtf8(_ data: [Int]) -> Bool {
        let n = data.count
        var i = 0
        while i < n {
            let val = data[i]
            var j = 7
            while j >= 0 && ((val >> j) & 1) == 1 {
                j -= 1
            }
            let cnt = 7 - j
            if cnt == 1 || cnt > 4 {
                return false
            }
            if i + cnt > n {
                return false
            }
            if cnt > 0 {
                for k in (i+1)..<(i+cnt) {
                    if ((data[k] >> 7) & 1) == 1 && ((data[k] >> 6) & 1) == 0 {
                        continue
                    }
                    return false
                }
            }
            if cnt == 0 {
                i += 1
            } else {
                i += cnt
            }
        }
        return true
    }
}
// @lc code=end

func main() {
    var data: [Int]
    var res: Bool
    
    /**
     输入：data = [197,130,1]
     输出：true
     解释：数据表示字节序列:11000101 10000010 00000001。
     这是有效的 utf-8 编码，为一个 2 字节字符，跟着一个 1 字节字符。
     */
    data = [197,130,1]
    res = true
    assert(res == Solution().validUtf8(data))
    
    /**
     输入：data = [235,140,4]
     输出：false
     解释：数据表示 8 位的序列: 11101011 10001100 00000100.
     前 3 位都是 1 ，第 4 位为 0 表示它是一个 3 字节字符。
     下一个字节是开头为 10 的延续字节，这是正确的。
     但第二个延续字节不以 10 开头，所以是不符合规则的。
     */
    data = [235,140,4]
    res = false
    assert(res == Solution().validUtf8(data))
}
