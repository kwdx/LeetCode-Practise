/*
 * @lc app=leetcode.cn id=1805 lang=swift
 *
 * [1805] 字符串中不同整数的数目
 */

// @lc code=start
class Solution {
    func numDifferentIntegers(_ word: String) -> Int {
        var nums = Set<String>()
        let word = Array(word)
        var i = 0
        let n = word.count
        while i < n {
            if word[i].isNumber {
                while i < n && word[i] == "0" {
                    i += 1
                }
                var j = i
                while j < n && word[j].isNumber {
                    j += 1
                }
                nums.insert(String(word[i..<j]))
                i = j
            }
            i += 1
        }
        return nums.count
    }
}
// @lc code=end

func main() {
    var word: String
    var res: Int
    
    /**
     输入：word = "a123bc34d8ef34"
     输出：3
     解释：不同的整数有 "123"、"34" 和 "8" 。注意，"34" 只计数一次。
     */
    word = "a123bc34d8ef34"
    res = 3
    assert(res == Solution().numDifferentIntegers(word))
    
    /**
     输入：word = "leet1234code234"
     输出：2
     */
    word = "leet1234code234"
    res = 2
    assert(res == Solution().numDifferentIntegers(word))
    
    /**
     输入：word = "a1b01c001"
     输出：1
     解释："1"、"01" 和 "001" 视为同一个整数的十进制表示，因为在比较十进制值时会忽略前导零的存在。
     */
    word = "a1b01c001"
    res = 1
    assert(res == Solution().numDifferentIntegers(word))
}
