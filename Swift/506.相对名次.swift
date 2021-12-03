/*
 * @lc app=leetcode.cn id=506 lang=swift
 *
 * [506] 相对名次
 */

// @lc code=start
class Solution {
    func findRelativeRanks(_ score: [Int]) -> [String] {
        let desc = ["Gold Medal", "Silver Medal", "Bronze Medal"]
        var arr: [(Int, Int)] = []
        for i in 0..<score.count {
            arr.append((score[i], i))
        }
        arr.sort { $0.0 > $1.0 }
        var ans: [String] = .init(repeating: "", count: score.count)
        for i in 0..<score.count {
            if (i > 2) {
                ans[arr[i].1] = String(i + 1)
            } else {
                ans[arr[i].1] = desc[i]
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var score: [Int];
    var res: [String]
    
    /**
     输入：score = [5,4,3,2,1]
     输出：["Gold Medal","Silver Medal","Bronze Medal","4","5"]
     解释：名次为 [1st, 2nd, 3rd, 4th, 5th] 。
     */
    score = [5,4,3,2,1]
    res = ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
    assert(res == Solution().findRelativeRanks(score))
    
    /**
     输入：score = [10,3,8,9,4]
     输出：["Gold Medal","5","Bronze Medal","Silver Medal","4"]
     解释：名次为 [1st, 5th, 3rd, 2nd, 4th] 。
     */
    score = [10,3,8,9,4]
    res = ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
    assert(res == Solution().findRelativeRanks(score));
}
