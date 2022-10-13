/*
 * @lc app=leetcode.cn id=769 lang=swift
 *
 * [769] 最多能完成排序的块
 */

// @lc code=start
class Solution {
    func maxChunksToSorted(_ arr: [Int]) -> Int {
        var ans = 0
        var m = 0
        for i in 0..<arr.count {
            m = max(m, arr[i])
            if m == i {
                ans += 1
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var arr: [Int]
    var res: Int
    
    /**
     输入: arr = [4,3,2,1,0]
     输出: 1
     解释:
     将数组分成2块或者更多块，都无法得到所需的结果。
     例如，分成 [4, 3], [2, 1, 0] 的结果是 [3, 4, 0, 1, 2]，这不是有序的数组。
     */
    arr = [4,3,2,1,0]
    res = 1
    assert(res == Solution().maxChunksToSorted(arr))
    
    /**
     输入: arr = [1,0,2,3,4]
     输出: 4
     解释:
     我们可以把它分成两块，例如 [1, 0], [2, 3, 4]。
     然而，分成 [1, 0], [2], [3], [4] 可以得到最多的块数。
     */
    arr = [1,0,2,3,4]
    res = 4
    assert(res == Solution().maxChunksToSorted(arr))
}
