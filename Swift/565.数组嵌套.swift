/*
 * @lc app=leetcode.cn id=565 lang=swift
 *
 * [565] 数组嵌套
 */

// @lc code=start
class Solution {
    func arrayNesting(_ nums: [Int]) -> Int {
        var A = nums
        var ans = 0
        for i in 0..<A.count {
            var cur = i, cnt = 0
            while A[cur] != -1 {
                cnt += 1
                let c = cur
                cur = A[cur]
                A[c] = -1
            }
            ans = max(ans, cnt)
        }
        return ans
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: Int
    
    /**
     输入: A = [5,4,0,3,1,6,2]
     输出: 4
     解释:
     A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

     其中一种最长的 S[K]:
     S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
     */
    nums = [5,4,0,3,1,6,2]
    res = 4
    assert(res == Solution().arrayNesting(nums))
}
