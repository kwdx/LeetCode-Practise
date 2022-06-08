/*
 * @lc app=leetcode.cn id=1037 lang=swift
 *
 * [1037] 有效的回旋镖
 */

// @lc code=start
class Solution {
    func isBoomerang(_ points: [[Int]]) -> Bool {
        let a = points[1][0] - points[0][0], b = points[1][1] - points[0][1]
        let x = points[2][0] - points[0][0], y = points[2][1] - points[0][1]
        return a * y - b * x != 0
    }
}
// @lc code=end

func main() {
    var points: [[Int]]
    var res: Bool
    
    /**
     输入：points = [[1,1],[2,3],[3,2]]
     输出：true
     */
    points = [[1,1],[2,3],[3,2]]
    res = true
    assert(res == Solution().isBoomerang(points))
    
    /**
     输入：points = [[1,1],[2,2],[3,3]]
     输出：false
     */
    points = [[1,1],[2,2],[3,3]]
    res = false
    assert(res == Solution().isBoomerang(points))
}
