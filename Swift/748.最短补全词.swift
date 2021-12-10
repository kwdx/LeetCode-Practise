/*
 * @lc app=leetcode.cn id=748 lang=swift
 *
 * [748] 最短补全词
 */

// @lc code=start
class Solution {
    private func getCnts(_ word: String) -> [Int] {
        var cnts = [Int](repeating: 0, count: 26)
        for c in word {
            if let asciiValue = c.asciiValue {
                switch c {
                case "a"..."z":
                    cnts[Int(asciiValue) - 97] += 1
                case "A"..."Z":
                    cnts[Int(asciiValue) - 65] += 1
                default:
                    break
                }
            }
        }
        return cnts
    }
    
    func shortestCompletingWord(_ licensePlate: String, _ words: [String]) -> String {
        var ans: String?
        let cnts = getCnts(licensePlate)
        for word in words {
            let cur = getCnts(word)
            var isContains = true
            for i in 0..<26 {
                if cnts[i] > cur[i] {
                    isContains = false
                    break
                }
            }
            if isContains && (ans == nil || ans!.count > word.count) {
                ans = word
            }
        }
        return ans ?? ""
    }
}
// @lc code=end

func main() {
    // insert code here...
    
    var licensePlate: String
    var words: [String]
    var res: String
    
    /**
     输入：licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
     输出："steps"
     解释：最短补全词应该包括 "s"、"p"、"s"（忽略大小写） 以及 "t"。
     "step" 包含 "t"、"p"，但只包含一个 "s"，所以它不符合条件。
     "steps" 包含 "t"、"p" 和两个 "s"。
     "stripe" 缺一个 "s"。
     "stepple" 缺一个 "s"。
     因此，"steps" 是唯一一个包含所有字母的单词，也是本例的答案。
     */
    licensePlate = "1s3 PSt"
    words = ["step", "steps", "stripe", "stepple"]
    res = "steps"
    assert(res == Solution().shortestCompletingWord(licensePlate, words))
    
    /**
     输入：licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
     输出："pest"
     解释：licensePlate 只包含字母 "s" 。所有的单词都包含字母 "s" ，其中 "pest"、"stew"、和 "show" 三者最短。答案是 "pest" ，因为它是三个单词中在 words 里最靠前的那个。
     */
    licensePlate = "1s3 456"
    words = ["looks", "pest", "stew", "show"]
    res = "pest"
    assert(res == Solution().shortestCompletingWord(licensePlate, words))
    
    /**
     输入：licensePlate = "Ah71752", words = ["suggest","letter","of","husband","easy","education","drug","prevent","writer","old"]
     输出："husband"
     */
    licensePlate = "Ah71752"
    words = ["suggest","letter","of","husband","easy","education","drug","prevent","writer","old"]
    res = "husband"
    assert(res == Solution().shortestCompletingWord(licensePlate, words))
    
    /**
     输入：licensePlate = "OgEu755", words = ["enough","these","play","wide","wonder","box","arrive","money","tax","thus"]
     输出："enough"
     */
    licensePlate = "OgEu755"
    words = ["enough","these","play","wide","wonder","box","arrive","money","tax","thus"]
    res = "enough"
    assert(res == Solution().shortestCompletingWord(licensePlate, words))
    
    /**
     输入：licensePlate = "iMSlpe4", words = ["claim","consumer","student","camera","public","never","wonder","simple","thought","use"]
     输出："simple"
     */
    licensePlate = "iMSlpe4"
    words = ["claim","consumer","student","camera","public","never","wonder","simple","thought","use"]
    res = "simple"
    assert(res == Solution().shortestCompletingWord(licensePlate, words))
}
