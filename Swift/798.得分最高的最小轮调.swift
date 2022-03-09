/*
 * @lc app=leetcode.cn id=798 lang=swift
 *
 * [798] 得分最高的最小轮调
 */

// @lc code=start
class Solution {
    func bestRotation(_ nums: [Int]) -> Int {
        let n = nums.count
        var diffs = [Int](repeating: 0, count: n)
        for i in 0..<n {
            let low = (i + 1) % n
            let high = (i + n + 1 - nums[i]) % n
            diffs[low] += 1
            diffs[high] -= 1
            if (low >= high) {
                diffs[0] += 1
            }
        }
        var ans = 0
        var maxScore = 0
        var score = 0
        for i in 0..<n {
            score += diffs[i]
            if score > maxScore {
                ans = i
                maxScore = score
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: Int
    
    /**
     输入：nums = [2,3,1,4,0]
     输出：3
     解释：
     下面列出了每个 k 的得分：
     k = 0,  nums = [2,3,1,4,0],    score 2
     k = 1,  nums = [3,1,4,0,2],    score 3
     k = 2,  nums = [1,4,0,2,3],    score 3
     k = 3,  nums = [4,0,2,3,1],    score 4
     k = 4,  nums = [0,2,3,1,4],    score 3
     所以我们应当选择 k = 3，得分最高。
     */
    nums = [2,3,1,4,0]
    res = 3
    assert(res == Solution().bestRotation(nums))
    
    /**
     输入：nums = [1,3,0,2,4]
     输出：0
     解释：
     nums 无论怎么变化总是有 3 分。
     所以我们将选择最小的 k，即 0。
     */
    nums = [1,3,0,2,4]
    res = 0
    assert(res == Solution().bestRotation(nums))
}
