/*
 * @lc app=leetcode.cn id=934 lang=swift
 *
 * [934] 最短的桥
 */

// @lc code=start
class Solution {
    
    static let dirs = [(1,0),(-1,0),(0,1),(0,-1)]
    
    func shortestBridge(_ grid: [[Int]]) -> Int {
        let n = grid.count
        var grid = grid
        var island = [(Int, Int)]()
        var q = [(Int, Int)]()
        
        for i in 0..<n {
            for j in 0..<n {
                if grid[i][j] == 1 {
                    q.append((i, j))
                    grid[i][j] = -1
                    while !q.isEmpty {
                        let pos = q.removeFirst()
                        island.append(pos)
                        for dir in Self.dirs {
                            let nx = pos.0 + dir.0
                            let ny = pos.1 + dir.1
                            if nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 1 {
                                q.append((nx, ny))
                                grid[nx][ny] = -1
                            }
                        }
                    }
                    q.append(contentsOf: island)
                    
                    var step = 0
                    while !q.isEmpty {
                        let sz = q.count
                        for _ in 0..<sz {
                            let pos = q.removeFirst()
                            for dir in Self.dirs {
                                let nx = pos.0 + dir.0
                                let ny = pos.1 + dir.1
                                if nx >= 0 && ny >= 0 && nx < n && ny < n {
                                    if grid[nx][ny] == 0 {
                                        q.append((nx, ny))
                                        grid[nx][ny] = -1
                                    } else if grid[nx][ny] == 1 {
                                        return step
                                    }
                                }
                            }
                        }
                        step += 1
                    }
                    
                }
            }
        }
        
        return 0
    }
}
// @lc code=end

func main() {
    var grid: [[Int]]
    var res: Int
    
    /**
     输入：grid = [[0,1],[1,0]]
     输出：1
     */
    grid = [[0,1],[1,0]]
    res = 1
    assert(res == Solution().shortestBridge(grid))
    
    /**
     输入：grid = [[0,1,0],[0,0,0],[0,0,1]]
     输出：2
     */
    grid = [[0,1,0],[0,0,0],[0,0,1]]
    res = 2
    assert(res == Solution().shortestBridge(grid))
    
    /**
     输入：grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
     输出：1
     */
    grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
    res = 1
    assert(res == Solution().shortestBridge(grid))
}
