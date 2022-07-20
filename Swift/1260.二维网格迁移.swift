/*
 * @lc app=leetcode.cn id=1260 lang=swift
 *
 * [1260] 二维网格迁移
 */

// @lc code=start
class Solution {
    func shiftGrid(_ grid: [[Int]], _ k: Int) -> [[Int]] {
        let (m, n) = (grid.count, grid[0].count)
        let N = m * n
        var ans: [[Int]] = .init(repeating: .init(repeating: 0, count: n), count: m)
        for i in 0..<m {
            for j in 0..<n {
                let idx = (i * n + j + k) % N
                let (x, y) = (idx / n, idx % n)
                ans[x][y] = grid[i][j]
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var grid: [[Int]]
    var k: Int
    var res: [[Int]]
    
    /**
     输入：grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
     输出：[[9,1,2],[3,4,5],[6,7,8]]
     */
    grid = [[1,2,3],[4,5,6],[7,8,9]]
    k = 1
    res = [[9,1,2],[3,4,5],[6,7,8]]
    assert(res == Solution().shiftGrid(grid, k))
    
    /**
     输入：grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
     输出：[[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
     */
    grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]]
    k = 4
    res = [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
    assert(res == Solution().shiftGrid(grid, k))
    
    /**
     输入：grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
     输出：[[1,2,3],[4,5,6],[7,8,9]]
     */
    grid = [[1,2,3],[4,5,6],[7,8,9]]
    k = 9
    res = [[1,2,3],[4,5,6],[7,8,9]]
    assert(res == Solution().shiftGrid(grid, k))
}
