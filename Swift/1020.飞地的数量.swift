/*
 * @lc app=leetcode.cn id=1020 lang=swift
 *
 * [1020] 飞地的数量
 */

// @lc code=start
class Solution {
    func numEnclaves(_ grid: [[Int]]) -> Int {
        let directions: [(Int, Int)] = [(0,1),(0,-1),(1,0),(-1,0)]
        
        let m = grid.count, n = grid[0].count
        var q: [(Int, Int)] = []
        var grid_ = grid
        let bfs: () -> () = {
            while !q.isEmpty {
                let cell = q.removeFirst()
                // 遍历单元格
                directions.forEach {
                    let x = cell.0 + $0.0, y = cell.1 + $0.1
                    // 确保单元格未越界，且为陆地
                    if (0..<m).contains(x) && (0..<n).contains(y) && grid_[x][y] == 1 {
                        grid_[x][y] = 0
                        q.append((x, y))
                    }
                }
            }
        }
        (0..<m).forEach {
            if grid_[$0][0] == 1 {
                q.append(($0, 0))
                grid_[$0][0] = 0
            }
            if grid_[$0][n - 1] == 1 {
                q.append(($0, n - 1))
                grid_[$0][n - 1] = 0
            }
            bfs()
        }
        (0..<n).forEach {
            if grid_[0][$0] == 1 {
                q.append((0, $0))
                grid_[0][$0] = 0
            }
            if grid_[m - 1][$0] == 1 {
                q.append((m - 1, $0))
                grid_[m - 1][$0] = 0
            }
            bfs()
        }
        
        return grid_
            .flatMap { $0 }
            .reduce(0) { $1 == 1 ? $0 + 1 : $0 }
    }
}
// @lc code=end

func main() {
    var grid: [[Int]]
    var res: Int
    
    /**
     输入：grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
     输出：3
     解释：有三个 1 被 0 包围。一个 1 没有被包围，因为它在边界上。
     */
    grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
    res = 3
    assert(res == Solution().numEnclaves(grid))
    
    /**
     输入：grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
     输出：0
     解释：所有 1 都在边界上或可以到达边界。
     */
    grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
    res = 0
    assert(res == Solution().numEnclaves(grid))
}
