/*
 * @lc app=leetcode.cn id=883 lang=swift
 *
 * [883] 三维形体投影面积
 */

// @lc code=start
class Solution {
    func projectionArea(_ grid: [[Int]]) -> Int {
        let n = grid.count
        var ans1 = 0, ans2 = 0, ans3 = 0
        for i in 0..<n {
            var a = 0, b = 0
            for j in 0..<n {
                if grid[i][j] > 0 {
                    ans1 += 1
                }
                a = max(a, grid[i][j])
                b = max(b, grid[j][i])
            }
            ans2 += a
            ans3 += b
        }
        return ans1 + ans2 + ans3
    }
}
// @lc code=end

func main() {
    var grid: [[Int]]
    var res: Int
    
    /**
     输入：[[1,2],[3,4]]
     输出：17
     解释：这里有该形体在三个轴对齐平面上的三个投影(“阴影部分”)。
     */
    grid = [[1,2],[3,4]]
    res = 17
    assert(res == Solution().projectionArea(grid))
    
    /**
     输入：grid = [[2]]
     输出：5
     */
    grid = [[2]]
    res = 5
    assert(res == Solution().projectionArea(grid))
    
    /**
     输入：[[1,0],[0,2]]
     输出：8
     */
    grid = [[1,0],[0,2]]
    res = 8
    assert(res == Solution().projectionArea(grid))
}
