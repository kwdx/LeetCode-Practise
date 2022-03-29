/*
 * @lc app=leetcode.cn id=2024 lang=swift
 *
 * [2024] 考试的最大困扰度
 */

// @lc code=start
class Solution {
    private var answers: [Character] = []
    private var n: Int { answers.count }
    private var k: Int = 0
    
    func maxConsecutiveAnswers(_ answerKey: String, _ k: Int) -> Int {
        self.answers = Array(answerKey)
        self.k = k
        return max(getCnt("T"), getCnt("F"))
    }
    
    private func getCnt(_ c: Character) -> Int {
        var ans = 0
        var j = 0, cnt = 0
        for i in 0..<n {
            if answers[i] == c {
                cnt += 1
            }
            while cnt > k {
                if answers[j] == c {
                    cnt -= 1
                }
                j += 1
            }
            ans = max(ans, i - j + 1)
        }
        return ans
    }
}
// @lc code=end

func main() {
    var answerKey: String
    var k: Int
    var res: Int
    
    /**
     输入：answerKey = "TTFF", k = 2
     输出：4
     解释：我们可以将两个 'F' 都变为 'T' ，得到 answerKey = "TTTT" 。
     总共有四个连续的 'T' 。
     */
    answerKey = "TTFF"
    k = 2
    res = 4
    assert(res == Solution().maxConsecutiveAnswers(answerKey, k))
    
    /**
     输入：answerKey = "TFFT", k = 1
     输出：3
     解释：我们可以将最前面的 'T' 换成 'F' ，得到 answerKey = "FFFT" 。
     或者，我们可以将第二个 'T' 换成 'F' ，得到 answerKey = "TFFF" 。
     两种情况下，都有三个连续的 'F' 。
     */
    answerKey = "TFFT"
    k = 1
    res = 3
    assert(res == Solution().maxConsecutiveAnswers(answerKey, k))
    
    /**
     输入：answerKey = "TTFTTFTT", k = 1
     输出：5
     解释：我们可以将第一个 'F' 换成 'T' ，得到 answerKey = "TTTTTFTT" 。
     或者我们可以将第二个 'F' 换成 'T' ，得到 answerKey = "TTFTTTTT" 。
     两种情况下，都有五个连续的 'T' 。
     */
    answerKey = "TTFTTFTT"
    k = 1
    res = 5
    assert(res == Solution().maxConsecutiveAnswers(answerKey, k))
}
