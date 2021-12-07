/*
 * @lc app=leetcode.cn id=1034 lang=swift
 *
 * [1034] 边框着色
 */

// @lc code=start
class Solution {
    private var m = 0
    private var n = 0
    private var visited: [[Bool]] = []
    private var borders: [(Int, Int)] = []
    private var grids: [[Int]] = []
    
    private func dfs(_ x: Int, _ y: Int, _ color: Int) {
        var isBorder = false
        // 4个方向
        let direc: [(Int, Int)] = [(0, 1), (0, -1), (1, 0), (-1, 0)];
        for dir in direc {
            let nx = dir.0 + x
            let ny = dir.1 + y
            if !(nx >= 0 && nx < m && ny >= 0 && ny < n && grids[nx][ny] == color) {
                isBorder = true
            } else if !visited[nx][ny] {
                visited[nx][ny] = true
                dfs(nx, ny, color)
            }
        }
        if (isBorder) {
            borders.append((x, y));
        }
    }

    func colorBorder(_ grid: [[Int]], _ row: Int, _ col: Int, _ color: Int) -> [[Int]] {
        grids = grid
        m = grid.count
        n = grid[0].count
        visited = .init(repeating: .init(repeating: false, count: n), count: m)
        let originalColor = grid[row][col]
        visited[row][col] = true
        dfs(row, col, originalColor)
        for (x, y) in borders {
            grids[x][y] = color
        }
        return grids
    }
}
// @lc code=end

func main() {
    var grid: [[Int]]
    var row: Int
    var col: Int
    var color: Int
    var res: [[Int]]
    
    /**
     输入：grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
     输出：[[3,3],[3,2]]
     */
    grid = [[1,1],[1,2]]
    row = 0
    col = 0
    color = 3
    res = [[3,3],[3,2]]
    assert(res == Solution().colorBorder(grid, row, col, color))
    
    /**
     输入：grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
     输出：[[1,3,3],[2,3,3]]
     */
    grid = [[1,2,2],[2,3,2]]
    row = 0
    col = 1
    color = 3
    res = [[1,3,3],[2,3,3]]
    assert(res == Solution().colorBorder(grid, row, col, color))
    
    /**
     输入：grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
     输出：[[2,2,2],[2,1,2],[2,2,2]]
     */
    grid = [[1,1,1],[1,1,1],[1,1,1]]
    row = 1
    col = 1
    color = 2
    res = [[2,2,2],[2,1,2],[2,2,2]]
    assert(res == Solution().colorBorder(grid, row, col, color))
}
