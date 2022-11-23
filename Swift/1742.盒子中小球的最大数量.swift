/*
 * @lc app=leetcode.cn id=1742 lang=swift
 *
 * [1742] 盒子中小球的最大数量
 */

// @lc code=start
class Solution {
    func countBalls(_ lowLimit: Int, _ highLimit: Int) -> Int {
        var boxes = [Int: Int]()
        var ans = 0
        for i in lowLimit...highLimit {
            var box = 0
            var x = i
            while x != 0 {
                box += x % 10
                x /= 10
            }
            boxes[box] = 1 + (boxes[box] ?? 0)
            ans = max(ans, boxes[box]!)
        }
        return ans
    }
}
// @lc code=end

func main() {
    var lowLimit: Int
    var highLimit: Int
    var res: Int
    
    /**
     输入：lowLimit = 1, highLimit = 10
     输出：2
     解释：
     盒子编号：1 2 3 4 5 6 7 8 9 10 11 ...
     小球数量：2 1 1 1 1 1 1 1 1 0  0  ...
     编号 1 的盒子放有最多小球，小球数量为 2 。
     */
    lowLimit = 1
    highLimit = 10
    res = 2
    assert(res == Solution().countBalls(lowLimit, highLimit))
    
    /**
     输入：lowLimit = 5, highLimit = 15
     输出：2
     解释：
     盒子编号：1 2 3 4 5 6 7 8 9 10 11 ...
     小球数量：1 1 1 1 2 2 1 1 1 0  0  ...
     编号 5 和 6 的盒子放有最多小球，每个盒子中的小球数量都是 2 。
     */
    lowLimit = 5
    highLimit = 15
    res = 2
    assert(res == Solution().countBalls(lowLimit, highLimit))
    
    /**
     输入：lowLimit = 19, highLimit = 28
     输出：2
     解释：
     盒子编号：1 2 3 4 5 6 7 8 9 10 11 12 ...
     小球数量：0 1 1 1 1 1 1 1 1 2  0  0  ...
     编号 10 的盒子放有最多小球，小球数量为 2 。
     */
    lowLimit = 19
    highLimit = 28
    res = 2
    assert(res == Solution().countBalls(lowLimit, highLimit))
}
