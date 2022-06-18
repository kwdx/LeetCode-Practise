//
//  A.面试题-17.11.-单词距离.swift
//  swift_
//
//  Created by kingsoft on 2022/5/27.
//

// @lc code=start
class Solution {
    func findClosest(_ words: [String], _ word1: String, _ word2: String) -> Int {
        var v1: [Int] = []
        var v2: [Int] = []
        for i in 0..<words.count {
            if words[i] == word1 {
                v1.append(i)
            } else if words[i] == word2 {
                v2.append(i)
            }
        }
        var ans: Int = .max
        var j = 0
        for i in 0..<v1.count {
            // 找到v2第一个大于v1[i]的下标
            while j < v2.count && v1[i] > v2[j] {
                j += 1
            }
            if j > 0 {
                ans = min(ans, abs(v1[i] - v2[j - 1]))
            }
            if j < v2.count {
                ans = min(ans, abs(v1[i] - v2[j]))
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var words: [String]
    var word1: String
    var word2: String
    var res: Int
    
    /**
     输入：words = ["I","am","a","student","from","a","university","in","a","city"], word1 = "a", word2 = "student"
     输出：1

     来源：力扣（LeetCode）
     链接：https://leetcode.cn/problems/find-closest-lcci
     著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
     */
    words = ["I","am","a","student","from","a","university","in","a","city"]
    word1 = "a"
    word2 = "student"
    res = 1
    assert(res == Solution().findClosest(words, word1, word2))
}
