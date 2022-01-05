/*
 * @lc app=leetcode.cn id=1576 lang=swift
 *
 * [1576] 替换所有的问号
 */

// @lc code=start
class Solution {
    func modifyString(_ s: String) -> String {
        var characters = s.map { $0.asciiValue! }
        for i in 0..<characters.count {
            if characters[i] != 63 {
                continue
            }
            for j in 0..<3 {
                if i - 1 >= 0 && characters[i - 1] == 97 + j {
                    continue
                }
                if i + 1 < characters.count && characters[i + 1] == 97 + j {
                    continue
                }
                characters[i] = UInt8(97 + j)
                break
            }
        }
        return String(characters.map { Character(.init($0)) })
    }
}
// @lc code=end

func main() {
    var s: String
    var res: String
    
    /**
     输入：s = "?zs"
     输出："azs"
     解释：该示例共有 25 种解决方案，从 "azs" 到 "yzs" 都是符合题目要求的。只有 "z" 是无效的修改，因为字符串 "zzs" 中有连续重复的两个 'z' 。
     */
    s = "?zs"
    res = "azs"
    assert(res == Solution().modifyString(s))
    
    /**
     输入：s = "ubv?w"
     输出："ubvaw"
     解释：该示例共有 24 种解决方案，只有替换成 "v" 和 "w" 不符合题目要求。因为 "ubvvw" 和 "ubvww" 都包含连续重复的字符。
     */
    s = "ubv?w"
    res = "ubvaw"
    assert(res == Solution().modifyString(s))
    
    /**
     输入：s = "j?qg??b"
     输出："jaqgacb"
     */
    s = "j?qg??b"
    res = "jaqgacb"
    assert(res == Solution().modifyString(s))
    
    /**
     输入：s = "??yw?ipkj?"
     输出："acywaipkja"
     */
    s = "??yw?ipkj?"
    res = "abywaipkja"
    assert(res == Solution().modifyString(s))
}
