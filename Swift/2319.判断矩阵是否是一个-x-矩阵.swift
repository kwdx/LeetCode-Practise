/*
 * @lc app=leetcode.cn id=2319 lang=swift
 *
 * [2319] 判断矩阵是否是一个 X 矩阵
 */

// @lc code=start
class Solution {
    func checkXMatrix(_ grid: [[Int]]) -> Bool {
        let n = grid.count
        for i in 0..<n {
            for j in 0..<n {
                if i == j || i == n - j - 1 {
                    if grid[i][j] == 0 {
                        return false
                    }
                } else if grid[i][j] != 0 {
                    return false
                }
            }
        }
        return true
    }
}
// @lc code=end

func main() {
    var grid: [[Int]]
    var res: Bool
    
    /**
     输入：grid = [[2,0,0,1],[0,3,1,0],[0,5,2,0],[4,0,0,2]]
     输出：true
     解释：矩阵如上图所示。
     X 矩阵应该满足：绿色元素（对角线上）都不是 0 ，红色元素都是 0 。
     因此，grid 是一个 X 矩阵。
     */
    grid = [[2,0,0,1],[0,3,1,0],[0,5,2,0],[4,0,0,2]]
    res = true
    assert(res == Solution().checkXMatrix(grid))
    
    /**
     输入：grid = [[5,7,0],[0,3,1],[0,5,0]]
     输出：false
     解释：矩阵如上图所示。
     X 矩阵应该满足：绿色元素（对角线上）都不是 0 ，红色元素都是 0 。
     因此，grid 不是一个 X 矩阵。
     */
    grid = [[5,7,0],[0,3,1],[0,5,0]]
    res = false
    assert(res == Solution().checkXMatrix(grid))
}
