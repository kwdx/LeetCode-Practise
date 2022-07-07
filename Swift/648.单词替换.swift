/*
 * @lc app=leetcode.cn id=648 lang=swift
 *
 * [648] 单词替换
 */

// @lc code=start
class Solution {
    func replaceWords(_ dictionary: [String], _ sentence: String) -> String {
        var ans: [String] = []
        let sorted = dictionary.sorted()
        for word in sentence.split(separator: " ") {
            var replace = String(word)
            for pre in sorted {
                if word.hasPrefix(pre) {
                    replace = pre
                    break
                }
            }
            ans.append(replace)
        }
        
        return ans.joined(separator: " ")
    }
}
// @lc code=end

func main() {
    var dictionary: [String]
    var sentence: String
    var res: String
    
    /**
     输入：dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
     输出："the cat was rat by the bat"
     */
    dictionary = ["cat","bat","rat"]
    sentence = "the cattle was rattled by the battery"
    res = "the cat was rat by the bat"
    assert(res == Solution().replaceWords(dictionary, sentence))
    
    /**
     输入：dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
     输出："a a b c"
     */
    dictionary = ["a","b","c"]
    sentence = "aadsfasf absbs bbab cadsfafs"
    res = "a a b c"
    assert(res == Solution().replaceWords(dictionary, sentence))
}
