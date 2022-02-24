/*
 * @lc app=leetcode.cn id=1706 lang=swift
 *
 * [1706] 球会落何处
 */

// @lc code=start
class Solution {
    func findBall(_ grid: [[Int]]) -> [Int] {
        return (0..<grid[0].count).map {
            var r = 0, c = $0
            while r < grid.count {
                let nc = c + grid[r][c]
                if nc < 0 || nc >= grid[0].count {
                    return -1
                }
                if grid[r][nc] != grid[r][c] {
                    return -1
                }
                r += 1
                c = nc
            }
            return c
        }
    }
}
// @lc code=end

func main() {
    var grid: [[Int]]
    var res: [Int]
    
    /**
     输入：grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
     输出：[1,-1,-1,-1,-1]
     解释：示例如图：
     b0 球开始放在第 0 列上，最终从箱子底部第 1 列掉出。
     b1 球开始放在第 1 列上，会卡在第 2、3 列和第 1 行之间的 "V" 形里。
     b2 球开始放在第 2 列上，会卡在第 2、3 列和第 0 行之间的 "V" 形里。
     b3 球开始放在第 3 列上，会卡在第 2、3 列和第 0 行之间的 "V" 形里。
     b4 球开始放在第 4 列上，会卡在第 2、3 列和第 1 行之间的 "V" 形里。
     */
    grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
    res = [1,-1,-1,-1,-1]
    assert(res == Solution().findBall(grid))
    
    /**
     输入：grid = [[-1]]
     输出：[-1]
     解释：球被卡在箱子左侧边上。
     */
    grid = [[-1]]
    res = [-1]
    assert(res == Solution().findBall(grid))
    
    /**
     输入：grid = [[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1],[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1]]
     输出：[0,1,2,3,4,-1]
     */
    grid = [[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1],[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1]]
    res = [0,1,2,3,4,-1]
    assert(res == Solution().findBall(grid))
}
