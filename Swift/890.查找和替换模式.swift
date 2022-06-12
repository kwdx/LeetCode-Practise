/*
 * @lc app=leetcode.cn id=890 lang=swift
 *
 * [890] 查找和替换模式
 */

// @lc code=start
class Solution {
    func findAndReplacePattern(_ words: [String], _ pattern: String) -> [String] {
        var maps: [Character: Int] = [:]
        var p = ""
        var cur = 0
        for char in pattern {
            if maps[char] == nil {
                maps[char] = cur
                cur += 1
            }
            p.append(String(maps[char]!))
        }
        return words.filter { word in
            maps = [:]
            cur = 0
            var tmp = ""
            for char in word {
                if maps[char] == nil {
                    maps[char] = cur
                    cur += 1
                }
                tmp.append(String(maps[char]!))
            }
            return tmp == p
        }
    }
}
// @lc code=end

func main() {
    var words: [String]
    var pattern: String
    var res: [String]
    
    /**
     输入：words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
     输出：["mee","aqq"]
     解释：
     "mee" 与模式匹配，因为存在排列 {a -> m, b -> e, ...}。
     "ccc" 与模式不匹配，因为 {a -> c, b -> c, ...} 不是排列。
     因为 a 和 b 映射到同一个字母。
     */
    words = ["abc","deq","mee","aqq","dkd","ccc"]
    pattern = "abb"
    res = ["mee","aqq"]
    assert(res == Solution().findAndReplacePattern(words, pattern))
}
