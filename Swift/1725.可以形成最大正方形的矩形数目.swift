/*
 * @lc app=leetcode.cn id=1725 lang=swift
 *
 * [1725] 可以形成最大正方形的矩形数目
 */

// @lc code=start
class Solution {
    func countGoodRectangles(_ rectangles: [[Int]]) -> Int {
        var sides: [Int: Int] = [:]
        var maxSide = 0
        rectangles.forEach {
            let side = min($0[0], $0[1])
            sides[side] = 1 + (sides[side] ?? 0)
            maxSide = max(maxSide, side)
        }
        return sides[maxSide]!
    }
}
// @lc code=end

func main() {
    var rectangles: [[Int]]
    var res: Int
    
    /**
     输入：rectangles = [[5,8],[3,9],[5,12],[16,5]]
     输出：3
     解释：能从每个矩形中切出的最大正方形边长分别是 [5,3,5,5] 。
     最大正方形的边长为 5 ，可以由 3 个矩形切分得到。
     */
    rectangles = [[5,8],[3,9],[5,12],[16,5]]
    res = 3
    assert(res == Solution().countGoodRectangles(rectangles))
    
    /**
     输入：rectangles = [[2,3],[3,7],[4,3],[3,7]]
     输出：3
     */
    rectangles = [[2,3],[3,7],[4,3],[3,7]]
    res = 3
    assert(res == Solution().countGoodRectangles(rectangles))
}

